#include "udprecv.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpRecv w;
    w.show();

    return a.exec();
}
