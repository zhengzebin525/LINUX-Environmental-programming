#ifndef UDPRECV_H
#define UDPRECV_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class UdpRecv;
}

class UdpRecv : public QWidget
{
    Q_OBJECT

public:
    explicit UdpRecv(QWidget *parent = 0);
    ~UdpRecv();

private slots:
    void on_bindBt_clicked();

    void read_data();
    void on_checkBox_clicked(bool checked);

private:
    Ui::UdpRecv *ui;
    QUdpSocket msocket;
};

#endif // UDPRECV_H
