#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QObject>
#include<QTimer>
class workthread : public QObject
{
    Q_OBJECT
public:
    explicit workthread(QObject *parent = 0);
QTimer *time_g;
    void run();
signals:
    void mesgcount();
    void sendMessge();
public slots:
    void recieveUpdate();

};

#endif // WORKTHREAD_H
