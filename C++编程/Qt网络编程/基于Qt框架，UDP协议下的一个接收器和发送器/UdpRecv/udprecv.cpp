#include "udprecv.h"
#include "ui_udprecv.h"

UdpRecv::UdpRecv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UdpRecv)
{
    ui->setupUi(this);
    //关联读数据信号
    connect(&msocket, SIGNAL(readyRead()),this, SLOT(read_data()));
}

UdpRecv::~UdpRecv()
{
    delete ui;
}

void UdpRecv::on_bindBt_clicked()
{
    //绑定端口
    QString pstr = ui->portEdit->text();
    msocket.bind(QHostAddress::AnyIPv4, pstr.toInt());
}

//读取数据
void UdpRecv::read_data()
{
    //获取可读数据长度
    QByteArray array;//定义字节数组对象
    array.resize(msocket.bytesAvailable());//重新设定空间
    QHostAddress addr;
    quint16 port = 0;
    msocket.readDatagram(array.data(), array.size(), &addr, &port);
    //把数据显示在textBrowser上格式（ip：数据）
    ui->textBrowser->append(addr.toString()+":"+QString(array));
}

void UdpRecv::on_checkBox_clicked(bool checked)
{
    QString ip = ui->ipEidt->text();
    if(checked)
    {
        //添加到组播
        msocket.joinMulticastGroup(QHostAddress(ip));
    }else
    {
        //退出组播
        msocket.leaveMulticastGroup(QHostAddress(ip));
    }
}
