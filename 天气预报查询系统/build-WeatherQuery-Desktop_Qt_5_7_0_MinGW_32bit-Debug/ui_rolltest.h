/********************************************************************************
** Form generated from reading UI file 'rolltest.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLLTEST_H
#define UI_ROLLTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RollTest
{
public:

    void setupUi(QWidget *RollTest)
    {
        if (RollTest->objectName().isEmpty())
            RollTest->setObjectName(QStringLiteral("RollTest"));
        RollTest->resize(415, 36);

        retranslateUi(RollTest);

        QMetaObject::connectSlotsByName(RollTest);
    } // setupUi

    void retranslateUi(QWidget *RollTest)
    {
        RollTest->setWindowTitle(QApplication::translate("RollTest", "RollTest", 0));
    } // retranslateUi

};

namespace Ui {
    class RollTest: public Ui_RollTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLLTEST_H
