#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class TCPServer;
}

class TCPServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TCPServer(QWidget *parent = 0);
    ~TCPServer();

private slots:
    void on_StareBt_clicked();

    void new_client();
    void read_data();
private:
    Ui::TCPServer *ui;

    QTcpServer mserver;      //创建一个QTcpServer对象，用来监听客户端连接
};

#endif // TCPSERVER_H
