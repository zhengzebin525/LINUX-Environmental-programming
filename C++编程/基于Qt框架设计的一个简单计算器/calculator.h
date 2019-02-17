#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QButtonGroup>         //按钮组头文件

namespace Ui {
class calculator;
}

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();

private slots:
    void on_add_clicked();
    void on_sub_clicked();
    void on_mul_clicked();
    void on_dev_clicked();

    void on_res_clicked();

    void button_click(int num);

    void on_delete_clicked();

    void on_CE_clicked();

    void on_C_clicked();

    void on_pn_clicked();

private:
    Ui::calculator *ui;

    QString line;

    QString FirstNumber;    //第一个操作数
    QString SecondNumber;   //第二个操作数
    int calc;               //0表示没按，1，2，3，4表示按了运算符键

    //创建一个按钮组
    QButtonGroup group;
};

#endif // CALCULATOR_H
