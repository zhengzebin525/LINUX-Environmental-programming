#include "codesignalslot.h"
#include "ui_codesignalslot.h"
#include <QDebug>

CodeSignalSlot::CodeSignalSlot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CodeSignalSlot)
{
    ui->setupUi(this);

    //将按钮按下产生的信号类构造函数中的OpenFun()函数进行关联

    //按下OPenBt按钮，执行OpenFun()函数
    connect(ui->OpenBt, SIGNAL(clicked(bool)), this, SLOT(OpenFun()));

    //按下CloseBt按钮，执行CloseFun()函数
    connect(ui->CloseBt, SIGNAL(clicked(bool)), this, SLOT(CloseFun()));
}

CodeSignalSlot::~CodeSignalSlot()
{
    delete ui;
}

//以下两个都是自定义的槽函数
void CodeSignalSlot::OpenFun()
{
     qDebug()<<"打开";    //调试打印输出

     //while(1);         //操函数中不能加入死循环，否则窗口会卡死
                         //原因是槽函数跟程序是同步的，执行完后就会刷新一遍程序，再执行再刷新
}

void CodeSignalSlot::CloseFun()
{
     qDebug()<<"关闭";
}


//在ui图形界面中右击“打开”按钮，选择“转到槽”，点击OK，就会自动生成槽函数
//自动生成的槽函数已经与信号关联好了，不需要手动关联
void CodeSignalSlot::on_OpenBt_clicked()
{
    qDebug()<<"自动转到Open槽函数";
}


void CodeSignalSlot::on_CloseBt_clicked()
{
    qDebug()<<"自动传到close槽函数";
}


/*自定义槽函数与自动生成槽函数就会被执行，而且，自动生成槽函数的程序会比自定义槽函数程序优先执行*/

