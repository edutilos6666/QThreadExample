/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sortdialog
{
public:
    QWidget *centralwidget;
    QProgressBar *pPercentage;
    QSpinBox *sbCount;
    QPushButton *btnStart;
    QPushButton *btnClose;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sortdialog)
    {
        if (sortdialog->objectName().isEmpty())
            sortdialog->setObjectName(QStringLiteral("sortdialog"));
        sortdialog->resize(864, 259);
        centralwidget = new QWidget(sortdialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pPercentage = new QProgressBar(centralwidget);
        pPercentage->setObjectName(QStringLiteral("pPercentage"));
        pPercentage->setGeometry(QRect(120, 30, 681, 51));
        pPercentage->setMaximum(10000);
        pPercentage->setValue(24);
        sbCount = new QSpinBox(centralwidget);
        sbCount->setObjectName(QStringLiteral("sbCount"));
        sbCount->setGeometry(QRect(340, 110, 101, 22));
        sbCount->setMaximum(10000);
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(500, 110, 101, 23));
        btnClose = new QPushButton(centralwidget);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(660, 110, 101, 23));
        sortdialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sortdialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 864, 21));
        sortdialog->setMenuBar(menubar);
        statusbar = new QStatusBar(sortdialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        sortdialog->setStatusBar(statusbar);

        retranslateUi(sortdialog);

        QMetaObject::connectSlotsByName(sortdialog);
    } // setupUi

    void retranslateUi(QMainWindow *sortdialog)
    {
        sortdialog->setWindowTitle(QApplication::translate("sortdialog", "MainWindow", 0));
        btnStart->setText(QApplication::translate("sortdialog", "Start", 0));
        btnClose->setText(QApplication::translate("sortdialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class sortdialog: public Ui_sortdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
