#-------------------------------------------------
#
# Project created by QtCreator 2016-09-01T15:15:50
#
#-------------------------------------------------
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RC-MCSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp \
    workthread.cpp \
    message.cpp \
    bcthread.cpp \
    rtthread.cpp \
    swinfo.cpp \
    swinfo_read.cpp \
#    scenariogeneration.cpp \
    sgeneration.cpp

HEADERS  += mainwindow.h \
    mythread.h \
    variables.h \
    workthread.h \
    mcvariables.h \
    message.h \
    bcthread.h \
    rtthread.h \
    swinfo.h \
    swinfo_read.h \
#    scenariogeneration.h \
    sgeneration.h

FORMS    += mainwindow.ui \
    swinfo.ui \
    swinfo_read.ui


win32 {
    DDC_ARCH = Win32
    contains(QMAKE_TARGET.arch, x86_64)|contains(QT_ARCH, x86_64) {
        DDC_ARCH = x64
    }

    CONFIG(release, debug|release): DDC_CONFIG = Release
    else:CONFIG(debug, debug|release): DDC_CONFIG = Debug

    LIBS += -L$$PWD/ddc/Lib/$$DDC_ARCH/$$DDC_CONFIG/ -lemacepl
    INCLUDEPATH += $$PWD/ddc/Include
    DEPENDPATH += $$PWD/ddc/Include
}
