/********************************************************************************
** Form generated from reading UI file 'photoshow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOSHOW_H
#define UI_PHOTOSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoShow
{
public:
    QAction *actionClear;
    QAction *actionUpdata;
    QWidget *centralWidget;
    QListWidget *Photolist;
    QLabel *photolabel;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PhotoShow)
    {
        if (PhotoShow->objectName().isEmpty())
            PhotoShow->setObjectName(QStringLiteral("PhotoShow"));
        PhotoShow->resize(432, 379);
        actionClear = new QAction(PhotoShow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionUpdata = new QAction(PhotoShow);
        actionUpdata->setObjectName(QStringLiteral("actionUpdata"));
        centralWidget = new QWidget(PhotoShow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Photolist = new QListWidget(centralWidget);
        Photolist->setObjectName(QStringLiteral("Photolist"));
        Photolist->setGeometry(QRect(0, 0, 151, 271));
        photolabel = new QLabel(centralWidget);
        photolabel->setObjectName(QStringLiteral("photolabel"));
        photolabel->setGeometry(QRect(170, 0, 221, 311));
        photolabel->setLayoutDirection(Qt::LeftToRight);
        PhotoShow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PhotoShow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 432, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        PhotoShow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PhotoShow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PhotoShow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PhotoShow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PhotoShow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionClear);
        menu->addAction(actionUpdata);

        retranslateUi(PhotoShow);

        QMetaObject::connectSlotsByName(PhotoShow);
    } // setupUi

    void retranslateUi(QMainWindow *PhotoShow)
    {
        PhotoShow->setWindowTitle(QApplication::translate("PhotoShow", "PhotoShow", 0));
        actionClear->setText(QApplication::translate("PhotoShow", "clear", 0));
        actionUpdata->setText(QApplication::translate("PhotoShow", "update", 0));
        photolabel->setText(QApplication::translate("PhotoShow", "\345\233\276\347\211\207\346\230\276\347\244\272", 0));
        menu->setTitle(QApplication::translate("PhotoShow", "\350\217\234\345\215\225", 0));
    } // retranslateUi

};

namespace Ui {
    class PhotoShow: public Ui_PhotoShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOSHOW_H
