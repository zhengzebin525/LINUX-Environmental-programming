#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QDebug>

TCPServer::TCPServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TCPServer)
{
    ui->setupUi(this);

    //将TCP对象信号与客户端关联起来，关联操作要在监听之前
    //当有客户端连接的时候，QTcpServer对象就会发送一个newConnection信号，然后立即执行槽函数
    connect(&mserver,SIGNAL(newConnection()),this,SLOT(new_client()));
}

TCPServer::~TCPServer()
{
    delete ui;
}

//"启动"按钮用来监听客户端连接
void TCPServer::on_StareBt_clicked()
{
    //启动服务器，开始监听
    qDebug()<<"开始监听";
    mserver.listen(QHostAddress::Any,50001); //监听的IP为任意IP，端口号为50001
}


void TCPServer::new_client()
{
    //获取成功连接客户端的套接字
    QTcpSocket *msocket = mserver.nextPendingConnection();

    msocket->write("郑泽彬");

    //一旦接收到客户端要发来的数据，QTcpSocket对象msocket就会发送一个readyRead读取信号
    //一旦出发了readyRead读取信号，就立即关联到read_data()函数，即执行read_data函数
    connect(msocket,SIGNAL(readyRead()),this,SLOT(read_data()));

}

void TCPServer::read_data()
{

    //获取信号的发送者
    QTcpSocket *msocket = (QTcpSocket*)sender();

    //获取从客户端传过来的数据
    QString msg = msocket->readAll();

    //获取从客户端的ip地址
    QString ip = msocket->peerAddress().toString();

    qDebug()<<ip;
    qDebug()<<msg;

    ui->listWidget->addItem(ip+":"+msg);

}




























