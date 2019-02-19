#include "runwaterled.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RunWaterLED w;
    w.show();

    return a.exec();
}
