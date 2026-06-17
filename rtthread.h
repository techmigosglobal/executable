#ifndef RTTHREAD_H
#define RTTHREAD_H

#include <QObject>

class rtthread : public QObject
{
    Q_OBJECT
public:
    explicit rtthread(QObject *parent = 0);

    void run();
signals:
    void rtconfig();
};

#endif // RTTHREAD_H
