#ifndef CODESIGNALSLOT_H
#define CODESIGNALSLOT_H

#include <QMainWindow>

namespace Ui {
class CodeSignalSlot;
}

class CodeSignalSlot : public QMainWindow
{
    Q_OBJECT    //信号与槽函数处理所用到的宏
                //如果要在一个类中用到信号与槽函数，就必须添加Q_OBIECT这个宏

public:
    explicit CodeSignalSlot(QWidget *parent = 0);
    ~CodeSignalSlot();

    //声明自定义的槽函数
private slots:
    void OpenFun();
    void CloseFun();


    void on_OpenBt_clicked();

    void on_CloseBt_clicked();

private:
    Ui::CodeSignalSlot *ui;
};

#endif // CODESIGNALSLOT_H
