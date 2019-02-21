#include "photoshow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoShow w;
    w.show();

    return a.exec();
}
