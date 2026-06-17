#include "rtthread.h"
#include<QDebug>
rtthread::rtthread(QObject *parent) :
    QObject(parent)
{

}

void rtthread::run()
{
    emit rtconfig();

    qDebug()<<"rt  emit";
}
