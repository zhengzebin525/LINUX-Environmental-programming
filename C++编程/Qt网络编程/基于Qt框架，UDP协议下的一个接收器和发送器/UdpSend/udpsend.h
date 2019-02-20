#ifndef UDPSEND_H
#define UDPSEND_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class UdpSend;
}

class UdpSend : public QMainWindow
{
    Q_OBJECT

public:
    explicit UdpSend(QWidget *parent = 0);
    ~UdpSend();

private slots:
    void on_sendBt_clicked();

private:
    Ui::UdpSend *ui;
    QUdpSocket msocket;
};

#endif // UDPSEND_H
