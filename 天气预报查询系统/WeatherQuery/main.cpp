#include "weatherquery.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherQuery w;
    w.show();

    return a.exec();
}
