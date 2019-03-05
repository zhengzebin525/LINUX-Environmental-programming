#include "rolltest.h"
#include "ui_rolltest.h"
#include <QDebug>
#include <QPainter>
RollTest::RollTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RollTest)
{
    ui->setupUi(this);

    x = this->width();        //获取窗口的宽度

    //将定时器对象与槽函数关联，每个一段定时时间就执行槽函数一次
    connect(&mtimer, SIGNAL(timeout()),this, SLOT(pushButton_clicked()));

    mtimer.start(50);     //开启定时器，同时定时50ms触发一次定时信号
                       /*也就是说，每个50ms，定时器对象就产生一个timeout信号，
                       就执行一次槽函数，槽函数的功能就是将字符串一次一次往改变显示坐标*/
}

RollTest::~RollTest()
{
    delete ui;
}

void RollTest::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);         //创建绘图工具

    QFontMetrics mtr(this->font());   //把字符串长度转成像素长度
    int tw = mtr.width(rollStr);      //获取字符串长度
    int th = mtr.height();            //获取字符串宽度
    //绘制文字
    if(x<0 && x+tw>=0) //当字符串的x坐标小于0并且此字符串的尾部还处在窗口内看得见的时候
    {
        painter.drawText(x, th, rollStr);  //重新绘制一段相同的字符串
        //让这段字符串在窗口最右边外侧产生，并慢慢减小x坐标，产生移动效果
        painter.drawText(this->width()+x, th, rollStr);
        if(x+tw == 0)
        {
            x = this->width()-tw;
            qDebug()<<"x:"<<x;
        }

    }else
    {
        painter.drawText(x, th, rollStr);
    }
}

void RollTest::pushButton_clicked()
{
    x -= 1;
    update();
}

void RollTest::setRollStr(const QString &value)
{
    rollStr = value;
}
