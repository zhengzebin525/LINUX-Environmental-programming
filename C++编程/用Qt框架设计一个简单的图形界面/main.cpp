#include "labelqt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    labelQt w;
    w.show();

    return a.exec();
}
