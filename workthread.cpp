#include "workthread.h"
#include<QThread>
#include<QDebug>

int count;

workthread::workthread(QObject *parent) :
    QObject(parent)
{
    count =0;
time_g = new QTimer(this);
connect(time_g,SIGNAL(timeout()),this,SLOT(recieveUpdate()));
time_g->start(1000);
}
void workthread::run()
{
    emit mesgcount();
}
void workthread::recieveUpdate() //parallel process for updating GUI while sending/receiving data
{  
    emit sendMessge();
}
