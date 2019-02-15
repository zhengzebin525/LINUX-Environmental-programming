#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    //创建一个窗口
    QMainWindow w;

    //创建一个按钮
    QPushButton bt1(&w);               //将按钮创建在窗口里面
    bt1.setGeometry(20,20,100,50);     //按钮定位
    bt1.setText("关闭窗口");            //设置按钮文本

    w.show();

    //将信号与槽函数进行关联
    //信号与槽函数进行关联后，当按下按钮，信号就会发送，被关联的槽函数就会自动执行close()关闭窗口函数
    QObject::connect(&bt1, SIGNAL(clicked(bool)),&w, SLOT(close()));


    return a.exec();

}
