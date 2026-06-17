#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QMessageBox>

namespace Ui {
    class MainWindow;
}
class Arry
{
public:
    Arry(int N, int M) {
        double arry[N][M];
    }
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *timer,*timer2;
    unsigned short c1,c2;
QMessageBox *poperror;
bool sHIFTdiR;
int sHIFTbIT(int, int, bool);
int* matrix(int,int);
double ECEF[3][1];
Arry *arr;
//double* Geodetic2ECEF(double,double,double);

    ~MainWindow();
public slots:
    void calling();
    void calling_2();

private slots:
    void on_pB_gO_clicked();



    void on_rB_sHIFT_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
