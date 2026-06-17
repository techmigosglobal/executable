# Windows 32-bit executable build

This project is a Qt/qmake C++ desktop application. The checked-in executable under
`release/` is 64-bit, so a real 32-bit Windows package must be rebuilt with a
32-bit Qt kit and the 32-bit DDC runtime.

## Recommended option: GitHub Actions

Use `.github/workflows/windows-32bit.yml`.

1. Push this repository to GitHub.
2. Open the repository on GitHub.
3. Go to **Actions**.
4. Run **Windows 32-bit Build** manually, or push to `main`/`master`.
5. Download the `RC-MCSimulator-win32` artifact.
6. Run `RC-MCSimulator.exe` from inside the downloaded folder.

The workflow:

- installs Qt 5.12.12 MinGW 32-bit,
- builds with `qmake` and `mingw32-make`,
- runs `windeployqt`,
- copies `ddc/Lib/Win32/Release/emacepl.dll`,
- includes the bundled data files,
- verifies the executable PE header is `i386` before uploading the artifact.

## Other viable options

### Local Windows build

Install Qt 5.12.x with the 32-bit MinGW kit, open `RC-MCSimulator.pro` in Qt
Creator, select the 32-bit kit, build Release, then run `windeployqt` on the
generated executable and copy `ddc/Lib/Win32/Release/emacepl.dll` beside it.

This is useful for quick debugging on a Windows machine, but it is easier to
accidentally build 64-bit if the wrong kit is selected.

### Self-hosted Windows runner

Use a dedicated Windows machine with Qt Creator/Qt/MinGW already installed and
run the same qmake build steps from CI.

This is best only if the public GitHub runner cannot access required private
dependencies or if hardware-specific validation is needed.

### Installer package

After the CI build succeeds, wrap the `RC-MCSimulator-win32` folder with Inno
Setup, NSIS, or WiX.

This is useful for end users, but it should be a second step after the portable
folder build is proven on a clean 32-bit Windows machine.

## Best path

Use GitHub Actions for the reproducible 32-bit build, then optionally add an
installer after the artifact is tested.
