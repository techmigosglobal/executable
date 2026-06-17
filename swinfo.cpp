#include "swinfo.h"
#include "ui_swinfo.h"
#include  <unistd.h>
#include "mainwindow.h"
#include <stdio.h>
#include <qmessagebox.h>
#include <qcolor.h>
#include <QProcess>
#include <QFile>
#include <QCryptographicHash>
MainWindow *w;
using namespace std;
SwInfo::SwInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwInfo)
{
    ui->setupUi(this);
}

SwInfo::~SwInfo()
{
    delete ui;
}



void SwInfo::on_PBI_clicked()
{

    if (ui->le_op_name->text().isEmpty())

    QMessageBox::information(this,"THE TITLE", "OPERATOR NAME EMPTY");
   else
    {

    if (ui->le_pwd->text()=="a")
    {
        QString op_name= ui->le_op_name->text();
        QByteArray string ;
       string= op_name.toUtf8();

    w =new MainWindow();
    w->show();
    }
    else
    QMessageBox::information(this,"MISSILE IDENTIFICATION","INCORRECT PASSWORD. TRY AGAIN");
    }


    //Md5Sum CheckoutEXEcalculate

      QProcess *processMd5=new QProcess;

      QString md5Sumcmd;
      QStringList md5args;
      md5Sumcmd="Md5";
      md5args <<"RC-MCSimulator";

              processMd5->start(md5Sumcmd,md5args,QIODevice::ReadOnly);
              processMd5->waitForBytesWritten();
              processMd5->waitForFinished();


              QString StdOut=processMd5->readAllStandardOutput();

              QString StdError =processMd5->readAllStandardError();
    qDebug()<<"StdOut  "<<StdOut;
    qDebug()<<"StdError  "<<StdError;
    //End MD5Sum Calculated


   //Store Checksum reading

      QFile file("CHECKSUM.txt");
          if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
           QString line[4];
           int I=0;

          QTextStream in(&file);
          while (!in.atEnd())
          {
              line[I] = in.readLine();

              // qDebug()<<"line"<<line[I];
                I++;
          }

       file.close();

       StdOut.remove(32, 20);

      ui->le_Checksum->setText(StdOut);
     // qDebug()<<"StdOut"<<StdOut;
       //qDebug()<<"line"<<line[0];
        usleep(1000);

      if(line[0]==StdOut)
        {
          ui->le_Checksum->setStyleSheet("background-color:rgb(0,255,0)");

        }
      else{

          ui->le_Checksum->setStyleSheet("background-color:rgb(255,0,0)");

      }
      if(line[1]=="V1/25JULY2023")
        {
          ui->le_Version->setStyleSheet("background-color:rgb(0,255,0)");
          ui->le_Version->setText(line[1]);
        }
      else{

          ui->le_Version->setStyleSheet("background-color:rgb(255,0,0)");
          ui->le_Version->setText(line[1]);

      }
  processMd5->kill();

}

