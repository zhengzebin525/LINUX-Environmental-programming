#ifndef RUNWATERLED_H
#define RUNWATERLED_H

#include <QMainWindow>
#include <QTimer>

extern "C"
{
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
}

namespace Ui {
class RunWaterLED;
}

class RunWaterLED : public QMainWindow
{
    Q_OBJECT

public:
    explicit RunWaterLED(QWidget *parent = 0);
    ~RunWaterLED();

     int lednum;

private slots:
    void on_StartBt_clicked();

    void on_EndBt_clicked();

    void LedWork();

    void LedOn(int lednum);

    void LedOff(int lednum);

    void Delay_ms(int msec);

private:
    Ui::RunWaterLED *ui;
    int ledfd;
    int msec;
    int flag;
    QTimer mtime;
};

#endif // RUNWATERLED_H
