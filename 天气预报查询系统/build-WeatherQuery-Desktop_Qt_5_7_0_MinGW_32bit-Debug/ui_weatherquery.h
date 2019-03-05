/********************************************************************************
** Form generated from reading UI file 'weatherquery.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERQUERY_H
#define UI_WEATHERQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <softkey.h>
#include "rolltest.h"

QT_BEGIN_NAMESPACE

class Ui_WeatherQuery
{
public:
    QWidget *centralWidget;
    QLabel *GanmaoLabel;
    QLabel *IndexLabel;
    QLabel *TemperatureLabel;
    QLCDNumber *DateLcdNumber;
    QLCDNumber *TimeLcdNumber;
    QLabel *CityLabel;
    QLabel *TodayLabel;
    QLabel *TodayTypeLabel;
    QLabel *TodayHIghLabel;
    QLabel *TodayLowLabel;
    QLabel *YesterdayLowLabel;
    QLabel *YesterdayTypeLabel;
    QLabel *YesterdayHighLabel;
    QLabel *YesterdayLabel;
    QLabel *TomorrowLowLabel;
    QLabel *TomorrowTypeLabel;
    QLabel *TomorrowHIghLabel;
    QLabel *TomorrowLabel;
    QLabel *AfterTomorrowLabel;
    QLabel *AfterTomorrowTypeLabel;
    QLabel *AfterTomorrowLowLabel;
    QLabel *AfterTomorrowHIghLabel;
    RollTest *rollwidget;
    QPushButton *SkinBt;
    QLineEdit *InputLineEdit;
    QPushButton *CheckBt;
    QLabel *YesterdayTypeText;
    QLabel *TodayTypeText;
    QLabel *TomorrowTypeText;
    QLabel *AfterTomorrowTypeText;
    softkey *softkeywidget;
    QLabel *FengxiangLabel;
    QPushButton *CloseBt;
    QPushButton *NarrowBt;
    QLabel *FengliLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WeatherQuery)
    {
        if (WeatherQuery->objectName().isEmpty())
            WeatherQuery->setObjectName(QStringLiteral("WeatherQuery"));
        WeatherQuery->resize(563, 456);
        WeatherQuery->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border:1px solid#123455;\n"
"\n"
"\n"
"\n"
""));
        centralWidget = new QWidget(WeatherQuery);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GanmaoLabel = new QLabel(centralWidget);
        GanmaoLabel->setObjectName(QStringLiteral("GanmaoLabel"));
        GanmaoLabel->setGeometry(QRect(360, 40, 201, 61));
        GanmaoLabel->setAlignment(Qt::AlignCenter);
        GanmaoLabel->setWordWrap(false);
        IndexLabel = new QLabel(centralWidget);
        IndexLabel->setObjectName(QStringLiteral("IndexLabel"));
        IndexLabel->setGeometry(QRect(330, 40, 20, 81));
        IndexLabel->setAlignment(Qt::AlignCenter);
        IndexLabel->setWordWrap(true);
        TemperatureLabel = new QLabel(centralWidget);
        TemperatureLabel->setObjectName(QStringLiteral("TemperatureLabel"));
        TemperatureLabel->setGeometry(QRect(0, 30, 121, 61));
        QFont font;
        font.setPointSize(20);
        TemperatureLabel->setFont(font);
        TemperatureLabel->setAlignment(Qt::AlignCenter);
        DateLcdNumber = new QLCDNumber(centralWidget);
        DateLcdNumber->setObjectName(QStringLiteral("DateLcdNumber"));
        DateLcdNumber->setGeometry(QRect(150, 10, 141, 21));
        DateLcdNumber->setFocusPolicy(Qt::StrongFocus);
        DateLcdNumber->setStyleSheet(QStringLiteral(""));
        TimeLcdNumber = new QLCDNumber(centralWidget);
        TimeLcdNumber->setObjectName(QStringLiteral("TimeLcdNumber"));
        TimeLcdNumber->setGeometry(QRect(300, 10, 141, 21));
        TimeLcdNumber->setFocusPolicy(Qt::StrongFocus);
        CityLabel = new QLabel(centralWidget);
        CityLabel->setObjectName(QStringLiteral("CityLabel"));
        CityLabel->setGeometry(QRect(170, 40, 111, 51));
        CityLabel->setFont(font);
        CityLabel->setAlignment(Qt::AlignCenter);
        TodayLabel = new QLabel(centralWidget);
        TodayLabel->setObjectName(QStringLiteral("TodayLabel"));
        TodayLabel->setGeometry(QRect(150, 130, 91, 31));
        TodayLabel->setAlignment(Qt::AlignCenter);
        TodayTypeLabel = new QLabel(centralWidget);
        TodayTypeLabel->setObjectName(QStringLiteral("TodayTypeLabel"));
        TodayTypeLabel->setGeometry(QRect(150, 200, 91, 61));
        TodayTypeLabel->setStyleSheet(QStringLiteral(""));
        TodayTypeLabel->setAlignment(Qt::AlignCenter);
        TodayHIghLabel = new QLabel(centralWidget);
        TodayHIghLabel->setObjectName(QStringLiteral("TodayHIghLabel"));
        TodayHIghLabel->setGeometry(QRect(150, 270, 91, 21));
        TodayHIghLabel->setAlignment(Qt::AlignCenter);
        TodayLowLabel = new QLabel(centralWidget);
        TodayLowLabel->setObjectName(QStringLiteral("TodayLowLabel"));
        TodayLowLabel->setGeometry(QRect(150, 300, 91, 21));
        TodayLowLabel->setAlignment(Qt::AlignCenter);
        YesterdayLowLabel = new QLabel(centralWidget);
        YesterdayLowLabel->setObjectName(QStringLiteral("YesterdayLowLabel"));
        YesterdayLowLabel->setGeometry(QRect(20, 300, 91, 21));
        YesterdayLowLabel->setAlignment(Qt::AlignCenter);
        YesterdayTypeLabel = new QLabel(centralWidget);
        YesterdayTypeLabel->setObjectName(QStringLiteral("YesterdayTypeLabel"));
        YesterdayTypeLabel->setGeometry(QRect(20, 200, 91, 61));
        YesterdayTypeLabel->setAlignment(Qt::AlignCenter);
        YesterdayHighLabel = new QLabel(centralWidget);
        YesterdayHighLabel->setObjectName(QStringLiteral("YesterdayHighLabel"));
        YesterdayHighLabel->setGeometry(QRect(20, 270, 91, 21));
        YesterdayHighLabel->setAlignment(Qt::AlignCenter);
        YesterdayLabel = new QLabel(centralWidget);
        YesterdayLabel->setObjectName(QStringLiteral("YesterdayLabel"));
        YesterdayLabel->setGeometry(QRect(20, 130, 91, 31));
        YesterdayLabel->setAlignment(Qt::AlignCenter);
        TomorrowLowLabel = new QLabel(centralWidget);
        TomorrowLowLabel->setObjectName(QStringLiteral("TomorrowLowLabel"));
        TomorrowLowLabel->setGeometry(QRect(280, 300, 91, 21));
        TomorrowLowLabel->setAlignment(Qt::AlignCenter);
        TomorrowTypeLabel = new QLabel(centralWidget);
        TomorrowTypeLabel->setObjectName(QStringLiteral("TomorrowTypeLabel"));
        TomorrowTypeLabel->setGeometry(QRect(280, 200, 91, 61));
        TomorrowTypeLabel->setAlignment(Qt::AlignCenter);
        TomorrowHIghLabel = new QLabel(centralWidget);
        TomorrowHIghLabel->setObjectName(QStringLiteral("TomorrowHIghLabel"));
        TomorrowHIghLabel->setGeometry(QRect(280, 270, 91, 21));
        TomorrowHIghLabel->setAlignment(Qt::AlignCenter);
        TomorrowLabel = new QLabel(centralWidget);
        TomorrowLabel->setObjectName(QStringLiteral("TomorrowLabel"));
        TomorrowLabel->setGeometry(QRect(280, 130, 91, 31));
        TomorrowLabel->setAlignment(Qt::AlignCenter);
        AfterTomorrowLabel = new QLabel(centralWidget);
        AfterTomorrowLabel->setObjectName(QStringLiteral("AfterTomorrowLabel"));
        AfterTomorrowLabel->setGeometry(QRect(400, 130, 91, 31));
        AfterTomorrowLabel->setAlignment(Qt::AlignCenter);
        AfterTomorrowTypeLabel = new QLabel(centralWidget);
        AfterTomorrowTypeLabel->setObjectName(QStringLiteral("AfterTomorrowTypeLabel"));
        AfterTomorrowTypeLabel->setGeometry(QRect(400, 200, 91, 61));
        AfterTomorrowTypeLabel->setAlignment(Qt::AlignCenter);
        AfterTomorrowLowLabel = new QLabel(centralWidget);
        AfterTomorrowLowLabel->setObjectName(QStringLiteral("AfterTomorrowLowLabel"));
        AfterTomorrowLowLabel->setGeometry(QRect(400, 300, 91, 21));
        AfterTomorrowLowLabel->setAlignment(Qt::AlignCenter);
        AfterTomorrowHIghLabel = new QLabel(centralWidget);
        AfterTomorrowHIghLabel->setObjectName(QStringLiteral("AfterTomorrowHIghLabel"));
        AfterTomorrowHIghLabel->setGeometry(QRect(400, 270, 91, 21));
        AfterTomorrowHIghLabel->setAlignment(Qt::AlignCenter);
        rollwidget = new RollTest(centralWidget);
        rollwidget->setObjectName(QStringLiteral("rollwidget"));
        rollwidget->setGeometry(QRect(0, 360, 531, 31));
        SkinBt = new QPushButton(centralWidget);
        SkinBt->setObjectName(QStringLiteral("SkinBt"));
        SkinBt->setGeometry(QRect(470, 0, 31, 31));
        SkinBt->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-image: url(:/new/prefix1/images/update.png);\n"
"}\n"
"\n"
"QPushButton:Pressed\n"
"{\n"
"	\n"
"	background-image: url(:/new/prefix1/images/update_on.png);\n"
"}"));
        InputLineEdit = new QLineEdit(centralWidget);
        InputLineEdit->setObjectName(QStringLiteral("InputLineEdit"));
        InputLineEdit->setGeometry(QRect(0, 0, 141, 31));
        CheckBt = new QPushButton(centralWidget);
        CheckBt->setObjectName(QStringLiteral("CheckBt"));
        CheckBt->setGeometry(QRect(110, 0, 31, 31));
        CheckBt->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/\346\237\245\346\211\276.png);"));
        YesterdayTypeText = new QLabel(centralWidget);
        YesterdayTypeText->setObjectName(QStringLiteral("YesterdayTypeText"));
        YesterdayTypeText->setGeometry(QRect(20, 170, 91, 21));
        YesterdayTypeText->setAlignment(Qt::AlignCenter);
        TodayTypeText = new QLabel(centralWidget);
        TodayTypeText->setObjectName(QStringLiteral("TodayTypeText"));
        TodayTypeText->setGeometry(QRect(150, 170, 91, 21));
        TodayTypeText->setAlignment(Qt::AlignCenter);
        TomorrowTypeText = new QLabel(centralWidget);
        TomorrowTypeText->setObjectName(QStringLiteral("TomorrowTypeText"));
        TomorrowTypeText->setGeometry(QRect(280, 170, 91, 21));
        TomorrowTypeText->setAlignment(Qt::AlignCenter);
        AfterTomorrowTypeText = new QLabel(centralWidget);
        AfterTomorrowTypeText->setObjectName(QStringLiteral("AfterTomorrowTypeText"));
        AfterTomorrowTypeText->setGeometry(QRect(400, 170, 91, 21));
        AfterTomorrowTypeText->setAlignment(Qt::AlignCenter);
        softkeywidget = new softkey(centralWidget);
        softkeywidget->setObjectName(QStringLiteral("softkeywidget"));
        softkeywidget->setGeometry(QRect(10, 40, 541, 311));
        FengxiangLabel = new QLabel(centralWidget);
        FengxiangLabel->setObjectName(QStringLiteral("FengxiangLabel"));
        FengxiangLabel->setGeometry(QRect(130, 100, 71, 21));
        FengxiangLabel->setAlignment(Qt::AlignCenter);
        CloseBt = new QPushButton(centralWidget);
        CloseBt->setObjectName(QStringLiteral("CloseBt"));
        CloseBt->setGeometry(QRect(530, 0, 31, 31));
        CloseBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-image: url(:/new/prefix1/images/\345\205\263\351\227\255\346\214\211\351\222\256.png);\n"
"}\n"
"\n"
"QPushButton:Pressed\n"
"{\n"
"	background-image: url(:/new/prefix1/images/\345\205\263\351\227\255\346\214\211\351\222\2561.png);\n"
"}"));
        NarrowBt = new QPushButton(centralWidget);
        NarrowBt->setObjectName(QStringLiteral("NarrowBt"));
        NarrowBt->setGeometry(QRect(500, 0, 31, 31));
        NarrowBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-image: url(:/new/prefix1/images/\346\234\200\345\260\217\345\214\2261.png);\n"
"}\n"
"\n"
"QPushButton:Pressed\n"
"{\n"
"	background-image: url(:/new/prefix1/images/\346\234\200\345\260\217\345\214\226.png);\n"
"}"));
        FengliLabel = new QLabel(centralWidget);
        FengliLabel->setObjectName(QStringLiteral("FengliLabel"));
        FengliLabel->setGeometry(QRect(200, 100, 81, 21));
        FengliLabel->setAlignment(Qt::AlignCenter);
        WeatherQuery->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WeatherQuery);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 563, 25));
        WeatherQuery->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WeatherQuery);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WeatherQuery->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WeatherQuery);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WeatherQuery->setStatusBar(statusBar);

        retranslateUi(WeatherQuery);

        QMetaObject::connectSlotsByName(WeatherQuery);
    } // setupUi

    void retranslateUi(QMainWindow *WeatherQuery)
    {
        WeatherQuery->setWindowTitle(QApplication::translate("WeatherQuery", "WeatherQuery", 0));
        GanmaoLabel->setText(QApplication::translate("WeatherQuery", "\346\270\251\351\246\250\346\217\220\347\244\272", 0));
        IndexLabel->setText(QApplication::translate("WeatherQuery", "\346\204\237\345\206\222\346\214\207\346\225\260", 0));
        TemperatureLabel->setText(QApplication::translate("WeatherQuery", "\346\270\251\345\272\246", 0));
        CityLabel->setText(QApplication::translate("WeatherQuery", "\345\237\216\345\270\202", 0));
        TodayLabel->setText(QApplication::translate("WeatherQuery", "\344\273\212\345\244\251", 0));
        TodayTypeLabel->setText(QString());
        TodayHIghLabel->setText(QApplication::translate("WeatherQuery", "high", 0));
        TodayLowLabel->setText(QApplication::translate("WeatherQuery", "low", 0));
        YesterdayLowLabel->setText(QApplication::translate("WeatherQuery", "low", 0));
        YesterdayTypeLabel->setText(QString());
        YesterdayHighLabel->setText(QApplication::translate("WeatherQuery", "high", 0));
        YesterdayLabel->setText(QApplication::translate("WeatherQuery", "\346\230\250\345\244\251", 0));
        TomorrowLowLabel->setText(QApplication::translate("WeatherQuery", "low", 0));
        TomorrowTypeLabel->setText(QString());
        TomorrowHIghLabel->setText(QApplication::translate("WeatherQuery", "high", 0));
        TomorrowLabel->setText(QApplication::translate("WeatherQuery", "\346\230\216\345\244\251", 0));
        AfterTomorrowLabel->setText(QApplication::translate("WeatherQuery", "\345\220\216\345\244\251", 0));
        AfterTomorrowTypeLabel->setText(QString());
        AfterTomorrowLowLabel->setText(QApplication::translate("WeatherQuery", "low", 0));
        AfterTomorrowHIghLabel->setText(QApplication::translate("WeatherQuery", "high", 0));
        SkinBt->setText(QString());
        CheckBt->setText(QString());
        YesterdayTypeText->setText(QString());
        TodayTypeText->setText(QString());
        TomorrowTypeText->setText(QString());
        AfterTomorrowTypeText->setText(QString());
        FengxiangLabel->setText(QApplication::translate("WeatherQuery", " \351\243\216\345\220\221", 0));
        CloseBt->setText(QString());
        NarrowBt->setText(QString());
        FengliLabel->setText(QApplication::translate("WeatherQuery", "\351\243\216\345\212\233", 0));
    } // retranslateUi

};

namespace Ui {
    class WeatherQuery: public Ui_WeatherQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERQUERY_H
