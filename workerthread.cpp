#include "workerthread.h"


WorkerThread::WorkerThread()
{
  stopFlag = true ;
}

void WorkerThread::run()
{

	qDebug() << "inside Worker : " << QThread::currentThreadId();
	//qDebug() << "stopFlag = " << stopFlag ;
	QVector<int> vector;
	vector.reserve(maximum);
	for (int i = 0; i< maximum; ++i) {
		vector.push_back(maximum - i + 1);
	}

	//sorting (insertion sort)
	if (!stopFlag) {
		for (int i = 0; i< vector.count(); ++i) {
			int j = i;
			QThread::currentThread()->msleep(10);
			while (j > 0 && vector.at(j - 1) > vector.at(j)) {
				int temp = vector.at(j - 1);
				vector.replace(j - 1, vector.at(j));
				vector.replace(j, temp);
			}
			//if (i % 5 == 0)
			{
				//qDebug() << QThread::currentThread() << ": Emitting " << i;
				emit valueChanged(i);
			}
				
		}
	}
	else {


		emit stopped();
	}

	// qDebug() << vector ;
}

void WorkerThread::stop()
{
   stopFlag = true ;
    QThread::currentThread()->quit();
}



void WorkerThread::updateWindow(int value)
{

    qDebug() << "inside updateWindow = " << QThread::currentThreadId() ;
    //qDebug() << "new Value = " << value << " " << max  ;
   // pPercentage->setValue(value+1);

     // int value = ui->pPercentage->value();
      if(value < maximum) {
          if(btnCloseText == "Close") btnCloseText = "Stop";
          btnStartEnabled = false ;
      } else if(value == maximum) {
          if(btnCloseText == "Stop") btnCloseText = "Close";
          btnStartEnabled = true ;
       //   timer->stop();
      }

}


void MyThread::run() {
//   // QThread *th = new QThread();
//    sortdialog *dialog = new sortdialog(0, this);

// //   dialog->moveToThread(thread);

//  QObject::connect(this, SIGNAL(started()), dialog , SLOT(show()));
//    //QObject::connect(dialog , SIGNAL(destroyed(QObject*)), thread , SLOT(quit()));

//  // this->start();
////     dialog->show();
}
