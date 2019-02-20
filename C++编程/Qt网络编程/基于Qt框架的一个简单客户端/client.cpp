#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

   connect(&msocket,SIGNAL(readyRead()),this,SLOT(read_data()));
}

Client::~Client()
{
    delete ui;
}

//“接入服务器”按钮
void Client::on_ConnectBt_clicked()
{
    //连接服务器，IP地址和端口号来自于ui界面的输入
    msocket.connectToHost(ui->IPEdit->text(),
                          ui->PortEdit->text().toInt());   //将端口号的字符串类型转换成int型
}

//“发送”按钮
void Client::on_SendBt_clicked()
{
    //将ui界面的textEdit中的内容没有->text(),所以只能转成标准文本文件
    QString msg = ui->textEdit->toPlainText();

    //发送的时候用UTF8格式发送
    //因为write()并不支持QString类型发送，只支持QByteArray字节数格式
    msocket.write(msg.toUtf8());
}

void Client::read_data()
{
    QString msg = msocket.readAll();
    ui->textBrowse->append(msg);
}








