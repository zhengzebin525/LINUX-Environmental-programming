#include "udpsend.h"
#include "ui_udpsend.h"

UdpSend::UdpSend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UdpSend)
{
    ui->setupUi(this);
}

UdpSend::~UdpSend()
{
    delete ui;
}

void UdpSend::on_sendBt_clicked()
{
    //获取ip，port
    QString ip=ui->ipEdit->text();
    quint16 port = ui->portEdit->text().toShort();

    //获取要发送的数据
    QString  msg = ui->textEdit->toPlainText();
    QHostAddress addr(ip);
    msocket.writeDatagram(msg.toUtf8(),addr, port);

}
