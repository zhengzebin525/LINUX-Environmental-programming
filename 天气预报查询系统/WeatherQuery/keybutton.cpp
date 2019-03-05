#include "keybutton.h"
#include <QApplication>
#include <QKeyEvent>

KeyButton::KeyButton(QWidget *parent):QPushButton(parent)
{

    //当按下自己的时候，给自己发一个信号 ，至此自己类中的click_buton()函数
    connect(this,SIGNAL(clicked(bool)),this,SLOT(click_button()));
}


void KeyButton::click_button()
{
    //整个文件就算俺就本身，所以只要获取自身text，就算所在按钮的text
    QString str = this->text();
    char keyvale = str.at(0).toLatin1();
    //定义按钮事件
    QKeyEvent *key = new QKeyEvent(QKeyEvent::KeyPress,keyvale,Qt::NoModifier,str);

    //发送事件
    QApplication::postEvent(QApplication::focusWidget(),key);
}
