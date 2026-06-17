#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<math.h>
#include<QDesktopWidget>
#define bitshift(x,y) x<<y
#define bitad(x,y) x&y
#define npi2pi(x) ((x>0)&& (x<180))? x:(x-360)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //     setting geometry to GUI window
    QDesktopWidget *dwed = QApplication::desktop();
    QRect rect = dwed->availableGeometry();

    rect.setX(400);
    rect.setY(400);
    this->setGeometry(rect);
    c1=0;
    c2=0;
    ui->setupUi(this);
    timer = new QTimer;
    poperror = new QMessageBox();
    timer2 =new QTimer;
    connect(this->timer,SIGNAL(timeout()),this,SLOT(calling()));
    connect(this->timer2,SIGNAL(timeout()),this,SLOT(calling_2()));
//    ECEF= Geodetic2ECEF(87.12,94.22,120);
//            qDebug()<<"af 00"<<ECEF[0][0];
//     qDebug()<<"af 10"<<ECEF[1][0];
//     qDebug()<<"af 20"<<ECEF[2][0];

     arr =new Arry(3,3);
//     arr->Arry//
    //timer2->start(500);
   // timer->start(1);
     unsigned short z =bitshift(254738432,-16);
     qDebug("%x",255);
     qDebug("%d",z);
//    z= bitad(4,4);
//    qDebug("%x",z);
//    signed int  s = npi2pi(181);
    qDebug("int-------------%d",sizeof(int)*8);
    qDebug("unsigned--------%d",sizeof(unsigned int)*8);
    qDebug("float ----------%d",sizeof(float)*8);
    qDebug("signed int------%d",sizeof(signed int)*8);
    qDebug("short-----------%d",sizeof(short)*8);
    qDebug("unsigned short -%d",sizeof(unsigned short)*8);
    qDebug("signed short ---%d",sizeof(signed short)*8);
    qDebug("dobule----------%d",sizeof(double)*8);
    qDebug("long------------%d",sizeof(long)*8);
    qDebug("long double-----%d",sizeof(long double)*8);
    qDebug("signed long-----%d",sizeof(signed long)*8);
    qDebug("unsigned long---%d",sizeof(unsigned long)*8);
    qDebug("char------------%d",sizeof(char)*8);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calling()
{
    qDebug()<<"c1"<<c1++;
    c1++;
}

void MainWindow::calling_2()
{
    qDebug()<<"c2"<<c2++;

}

void MainWindow::on_pB_gO_clicked()
{
    if(ui->lE_iNPUT->text()=="")
        poperror->information(this,"Information","input is empty");

    if(ui->lE_nTHBIT->text()=="")
        poperror->information(this,"Information","nth bit in empty");


    int iNPUT = ui->lE_iNPUT->text().toInt();
    short nTHBIT = ui->lE_nTHBIT->text().toInt();

    ui->lE_rESULT->setText(QString::number(sHIFTbIT(iNPUT,nTHBIT,sHIFTdiR),10));



}

int MainWindow::sHIFTbIT(int number, int nth, bool D)
{
    if(D == true)
        return number = number >> nth;
    else
        return number = number << nth;
}




void MainWindow::on_rB_sHIFT_clicked(bool checked)
{
    if(checked == true){
        ui->rB_sHIFT->setText("RIGHT");
        sHIFTdiR=true;
    }else if(checked == false){
        ui->rB_sHIFT->setText("LIFT");
        sHIFTdiR=false;
    }

}

int * MainWindow::matrix(int , int)
{

}
//double * MainWindow ::Geodetic2ECEF(double Lat, double Lon, double h)
//{
//    //    %--------------------------------------------------------------------
//    //    % function to compute ECEF coordinates of a given geodetic position.
//    //    % Lat is the geodetic latitude in deg
//    //    % Lon is the geodetic longitude in deg
//    //    % h is the altitude above MSL in meters
//    //    %--------------------------------------------------------------------
//    double  esq = 0.00669437999014;
//    double   a = 6378137.0;
//    double   dr = 1.0 - esq * sin(Lat)^2;
//    int  N = a/sqrt(dr);
//    double CEF[3][1];
//       CEF[0][0] = (N + h) * cos(Lat) * cos(Lon);
//  qDebug()<<"bfr 00"<< CEF[0][0];
//      CEF[1][0] = (N + h) * cos(Lat) * sin(Lon);
//    qDebug()<<"bfr 10"<< CEF[1][0];
//  CEF[2][0] = (N * (1-esq) + h) * sin(Lat);
//  qDebug()<<"bfr 20"<<   CEF[2][0];
//  return CEF[0][0];
//}

//Arry MainWindow::work2d()
//{
//}
