/********************************************************************************
** Form generated from reading UI file 'runwaterled.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNWATERLED_H
#define UI_RUNWATERLED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunWaterLED
{
public:
    QWidget *centralWidget;
    QLabel *LedLabel1;
    QLabel *LedLabel2;
    QLabel *LedLabel3;
    QPushButton *StartBt;
    QPushButton *EndBt;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RunWaterLED)
    {
        if (RunWaterLED->objectName().isEmpty())
            RunWaterLED->setObjectName(QStringLiteral("RunWaterLED"));
        RunWaterLED->resize(441, 413);
        RunWaterLED->setStyleSheet(QLatin1String("QLabel{\n"
"border:1px solid#123456;\n"
"border-radius:25px;\n"
"}"));
        centralWidget = new QWidget(RunWaterLED);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LedLabel1 = new QLabel(centralWidget);
        LedLabel1->setObjectName(QStringLiteral("LedLabel1"));
        LedLabel1->setGeometry(QRect(50, 50, 50, 50));
        LedLabel2 = new QLabel(centralWidget);
        LedLabel2->setObjectName(QStringLiteral("LedLabel2"));
        LedLabel2->setGeometry(QRect(170, 50, 50, 50));
        LedLabel3 = new QLabel(centralWidget);
        LedLabel3->setObjectName(QStringLiteral("LedLabel3"));
        LedLabel3->setGeometry(QRect(300, 50, 50, 50));
        StartBt = new QPushButton(centralWidget);
        StartBt->setObjectName(QStringLiteral("StartBt"));
        StartBt->setGeometry(QRect(50, 170, 91, 31));
        EndBt = new QPushButton(centralWidget);
        EndBt->setObjectName(QStringLiteral("EndBt"));
        EndBt->setGeometry(QRect(230, 170, 91, 31));
        RunWaterLED->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RunWaterLED);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 441, 23));
        RunWaterLED->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RunWaterLED);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RunWaterLED->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RunWaterLED);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RunWaterLED->setStatusBar(statusBar);

        retranslateUi(RunWaterLED);

        QMetaObject::connectSlotsByName(RunWaterLED);
    } // setupUi

    void retranslateUi(QMainWindow *RunWaterLED)
    {
        RunWaterLED->setWindowTitle(QApplication::translate("RunWaterLED", "RunWaterLED", 0));
        LedLabel1->setText(QApplication::translate("RunWaterLED", "LED1", 0));
        LedLabel2->setText(QApplication::translate("RunWaterLED", "LED2", 0));
        LedLabel3->setText(QApplication::translate("RunWaterLED", "LED3", 0));
        StartBt->setText(QApplication::translate("RunWaterLED", "\345\274\200\345\247\213", 0));
        EndBt->setText(QApplication::translate("RunWaterLED", "\347\273\223\346\235\237", 0));
    } // retranslateUi

};

namespace Ui {
    class RunWaterLED: public Ui_RunWaterLED {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNWATERLED_H
