#include "runwaterled.h"
#include "ui_runwaterled.h"
#include <QDebug>
#include <QTime>
#include <QDate>

RunWaterLED::RunWaterLED(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunWaterLED)
{
    ui->setupUi(this);

    //打开设备
    this->ledfd = ::open("/dev/led_drv",O_RDWR);  //"::"表示open()这个函数不属于类中成员

    lednum = 8;
    flag = 0;

        //设置定时时间
        mtime.setInterval(1000);

        //将定时器和槽函数关联起来
        connect(&mtime,SIGNAL(timeout()),this,SLOT(LedWork()));  

}

RunWaterLED::~RunWaterLED()
{
    delete ui;
    ::close(this->ledfd);      //关闭文件描述符
}


//"开始"按钮
void RunWaterLED::on_StartBt_clicked()
{
    //启动定时器
    mtime.start();

     qDebug()<<"启动定时器";
}

//“结束”按钮
void RunWaterLED::on_EndBt_clicked()
{
    //停止定时器
    mtime.stop();

     qDebug()<<"停止定时器";
}

//定时执行槽函数
void RunWaterLED::LedWork()
{

        if(flag == 0)
        {
            RunWaterLED::LedOff(lednum);          //8号关灯
            RunWaterLED::LedOff(lednum+1);        //9号关灯
            RunWaterLED::LedOff(lednum+2);        //10号关灯
        }

        if(flag == 1)
        {
            lednum = 8;
            RunWaterLED::LedOn(lednum);           //8号开灯
            RunWaterLED::LedOff(lednum+1);        //9号关灯
            RunWaterLED::LedOff(lednum+2);        //10号关灯
        }

        if(flag == 2)
        {
            RunWaterLED::LedOff(lednum-1);          //8号关灯
            RunWaterLED::LedOff(lednum+1);          //10号关灯
            RunWaterLED::LedOn(lednum);             //9号开灯
        }
        if(flag == 3)
        {
            RunWaterLED::LedOff(lednum-1);          //8号关灯
            RunWaterLED::LedOff(lednum-2);          //9号关灯
            RunWaterLED::LedOn(lednum);             //10号开灯
        }

        lednum++;
        flag++;

        if(lednum == 11)
            lednum = 8;

        if(flag == 4)
            flag = 1;

}

//开灯
void RunWaterLED::LedOn(int lednum)
{

    switch(lednum)
    {
    case 8:ui->LedLabel1->setStyleSheet("background-color:#ff0000");
             qDebug()<<"开灯8";
            break;
    case 9:ui->LedLabel2->setStyleSheet("background-color:#ff0000");
             qDebug()<<"开灯9";
            break;
    case 10:ui->LedLabel3->setStyleSheet("background-color:#ff0000");
            qDebug()<<"开灯10";
            break;
    }

    char buf[2];
    buf[1] = lednum;
    buf[0] = 1;
    int ret = ::write(ledfd, buf, 2);
}

//关灯函数
void RunWaterLED::LedOff(int lednum)
{

    switch(lednum)
    {

    case 8:ui->LedLabel1->setStyleSheet("background-color:#000000");
            qDebug()<<"关灯8";
            break;
    case 9:ui->LedLabel2->setStyleSheet("background-color:#000000");
            qDebug()<<"关灯9";
            break;
    case 10:ui->LedLabel3->setStyleSheet("background-color:#000000");
            qDebug()<<"关灯10";
            break;
    }

    char buf[2];
    buf[1] = lednum;
    buf[0] = 0;
    int ret = ::write(ledfd, buf, 2);
}




