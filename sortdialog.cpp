#include "sortdialog.h"
#include "ui_sortdialog.h"


sortdialog::sortdialog(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::sortdialog)
{
     ui->setupUi(this);
     this->worker = new WorkerThread();
     registerEvents();
}

sortdialog::~sortdialog()
{
    delete ui;
}


void sortdialog::registerEvents()
{
	th = new QThread(this); 
  
	qDebug() << QThread::currentThreadId();

    worker->maximum = ui->sbCount->maximum();
    ui->pPercentage->setMaximum(ui->sbCount->maximum());
    worker->moveToThread(th);

	QObject::connect(th, SIGNAL(started()), worker , SLOT(run()));

    QObject::connect(ui->btnClose, &QPushButton::clicked, [this](){
           qDebug() << "inside stop" ;
        if(ui->btnClose->text() == "Stop") {

          //   timer->stop();
            //this->thread()->
           // thread->stop();
          // thread->stop();
            th->quit();
         //   timer->stop();
        } else if(ui->btnClose->text() == "Close") {
             this->close();
        }
    });

  
    QObject::connect(ui->btnStart, &QPushButton::clicked, [this](){
        worker->stopFlag = false ;
        th->start();
    });

    //QObject::connect(thread, SIGNAL(valueChanged(int)), thread , SLOT(updateWindow(int)));
   QObject::connect(worker , SIGNAL(valueChanged(int)), this, SLOT(updateWindow(int)));
   QObject::connect(th, SIGNAL(destroyed()), worker, SLOT(deleteLater())); 

   // QObject::connect(ui->sbCount, SIGNAL(valueChanged(int)), this, SLOT(setValues()));
   // QObject::connect(ui->sbCount, SIGNAL(valueChanged(int)), ui->pPercentage, SLOT(update()));

//    QObject::connect(th , SIGNAL(started()), timer, SLOT(start()));
 //   QObject::connect(thread , SIGNAL(stopped()), timer , SLOT(stop()));



}

int callcount = 0;
void sortdialog::updateWindow(int value)
{
	//qDebug() << QThread::currentThreadId() << " # Calls: " << ++callcount;
    //qDebug() << "inside updateWindow = " << QThread::currentThreadId() ;
    //ui->btnClose->setText(thread->btnCloseText);
    //ui->btnStart->setEnabled(thread->btnStartEnabled);
    ui->pPercentage->setValue(value+1);
//    int max = ui->pPercentage->maximum();
//    //qDebug() << "new Value = " << value << " " << max  ;
//    ui->pPercentage->setValue(value+1);

//     // int value = ui->pPercentage->value();
//      if(value < max) {
//          if(ui->btnClose->text() == "Close") ui->btnClose->setText("Stop");
//          if(ui->btnStart->isEnabled()) ui->btnStart->setEnabled(false);
//      } else if(value == max) {
//          if(ui->btnClose->text() == "Stop") ui->btnClose->setText("Close");
//          if(ui->btnStart->isEnabled() == false) ui->btnStart->setEnabled(true);
//       //   timer->stop();
//      }

}

void sortdialog::sort()
{
   QVector<int> vector;
   int max = ui->sbCount->maximum();
   ui->pPercentage->setMaximum(max);
   vector.reserve(max);
   for(int i=0; i< max; ++i) {
       vector.push_back(max-i+1);
   }

   //sorting (insertion sort)
   for(int i=1 ; i< vector.count(); ++i) {
       int j = i;
       while(j > 0 && vector.at(j-1) > vector.at(j)) {
            int temp = vector.at(j-1);
            vector.replace(j-1, vector.at(j));
            vector.replace(j , temp);

            ui->pPercentage->setValue(i+1);
       }
   }

   qDebug() << vector ;
}

void sortdialog::setValues()
{
    ui->pPercentage->setMaximum(ui->sbCount->maximum());
    worker->maximum = ui->sbCount->maximum();
}

int sortdialog::calculatePercentage()
{
   int max = ui->sbCount->maximum();
     int value = ui->sbCount->value();

     return (int) ((value/(double)max) * 100);
}
