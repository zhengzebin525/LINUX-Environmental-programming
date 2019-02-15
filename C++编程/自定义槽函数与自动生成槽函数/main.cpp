#include "codesignalslot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CodeSignalSlot w;
    w.show();

    return a.exec();
}
