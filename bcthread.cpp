#include "bcthread.h"
#include<QDebug>

bcthread::bcthread(QObject *parent) :
    QObject(parent)
{

}

void bcthread::run()
{
    emit bcconfig();
    qDebug()<<"bc emit";
}
