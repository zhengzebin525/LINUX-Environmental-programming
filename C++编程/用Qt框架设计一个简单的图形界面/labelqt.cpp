#include "labelqt.h"
#include "ui_labelqt.h"
#include <QDebug>

labelQt::labelQt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::labelQt)
{
    ui->setupUi(this);
}

labelQt::~labelQt()
{
    delete ui;
}

void labelQt::on_pushButton_clicked()
{

}

void labelQt::on_login_clicked()    //运行调试的时候，只要输入用户名和密码，点击“登录”，就可以在底下的调试信息栏中看到用户名和密码
{
    //获取用户名和密码
    QString name = ui->username->text();
    QString password = ui->password->text();

    //Qt调试输出
    qDebug()<<name<<password;
}
