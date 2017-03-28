#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>
#include <QThread>
#include <QVector>
#include <QDebug>
#include "workerthread.h"


namespace Ui {
class sortdialog;
}

class sortdialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit sortdialog(QWidget *parent = 0);
    ~sortdialog();
    void registerEvents();
public slots:
   void updateWindow(int value);
   void sort();
   void setValues();
private:
    Ui::sortdialog *ui;
    QThread *th ;
    WorkerThread *worker;
    int calculatePercentage();
};

#endif // SORTDIALOG_H
