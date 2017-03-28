#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    registerEvents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::registerEvents()
{
    QObject::connect(ui->actionSort, SIGNAL(triggered(bool)), this , SLOT(openSortDialog()));
}

void MainWindow::openSortDialog()
{
     sortdialog *dialog = new sortdialog(this);

  //   dialog->moveToThread(thread);

   //QObject::connect(th, SIGNAL(started()), dialog , SLOT(show()));
     //QObject::connect(dialog , SIGNAL(destroyed(QObject*)), thread , SLOT(quit()));

   // this->start();
      dialog->show();
}
