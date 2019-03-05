#ifndef KEYBUTTON_H
#define KEYBUTTON_H

#include <QObject>
#include <QPushButton>

class KeyButton : public QPushButton
{
    Q_OBJECT            //用到信号和槽
public:
    //KeyButton();      //这个构造函数是不能用的，因为是继承QPushButton过来的，必须要跟QPushButton构造函数一样的形式才有效
    explicit KeyButton(QWidget *parent = Q_NULLPTR);
private slots:
    void click_button();
};

#endif // KEYBUTTON_H
