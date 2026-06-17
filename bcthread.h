#ifndef BCTHREAD_H
#define BCTHREAD_H

#include <QObject>
#include <QThread>


class bcthread : public QObject
{

    Q_OBJECT

public:
    explicit bcthread(QObject *parent = 0);

    void run();
signals:
    void bcconfig();
};

#endif // BCTHREAD_H
