#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QDebug>
#include <QAtomicInteger>
#include <QVector>
#include <QProgressBar>
#include <QString>

class WorkerThread: public QObject
{
    Q_OBJECT
public:
    WorkerThread();


public slots:
    void stop();
void run();
void updateWindow(int value);
signals:
   void completed();
   void valueChanged(int value);
   void stopped();
public:
    volatile bool stopFlag ;
    QAtomicInteger<int> counter ;

public:
    int maximum ;
    bool btnStartEnabled;
    QString btnCloseText ;
    QProgressBar *pPercentage ;
};




class MyThread: public QThread {
    Q_OBJECT
public:
    void run();
};

#endif // WORKERTHREAD_H
