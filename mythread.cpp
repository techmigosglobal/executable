/********************************************************************
        Created		:	November 2014
        File Name	:	mythread.cpp
        Author		:	DNEC, RCI, Hyderabad - 500069

        Purpose		:

*********************************************************************/

#include "mythread.h"
#include <QtCore>
#include<QDebug>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
}

void MyThread::run()
{
    emit display();
    qDebug()<<" my thread inside display fun call";


}
