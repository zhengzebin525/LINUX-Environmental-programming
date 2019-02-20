#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    void on_ConnectBt_clicked();

    void on_SendBt_clicked();

    void read_data();
private:
    Ui::Client *ui;

    QTcpSocket msocket;
};

#endif // CLIENT_H
