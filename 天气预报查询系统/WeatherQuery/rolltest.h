#ifndef ROLLTEST_H
#define ROLLTEST_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>

namespace Ui {
class RollTest;
}

class RollTest : public QWidget
{
    Q_OBJECT

public:
    explicit RollTest(QWidget *parent = 0);
    ~RollTest();

    void paintEvent(QPaintEvent *event);
    void setRollStr(const QString &value);

private slots:
    void pushButton_clicked();

private:
    Ui::RollTest *ui;
    QTimer mtimer;       //创建一个定时器对象
    QString rollStr;     //创建一个字符串对象，用来从外界输入字符串
    int x;               //字符串显示的横坐标
};

#endif // ROLLTEST_H
