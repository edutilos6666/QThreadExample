#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sortdialog.h"
#include <QThread>
#include <QTimer>
#include <QDialog>
#include "workerthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void registerEvents();
public slots:
    void openSortDialog();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
