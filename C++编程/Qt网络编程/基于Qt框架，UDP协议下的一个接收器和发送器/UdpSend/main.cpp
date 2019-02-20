#include "udpsend.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpSend w;
    w.show();

    return a.exec();
}
