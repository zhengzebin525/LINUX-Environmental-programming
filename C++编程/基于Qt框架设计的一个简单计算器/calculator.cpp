#include "calculator.h"
#include "ui_calculator.h"

calculator::calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);

    //将按键数字添加进按钮组中
    group.addButton(ui->num0, 0);
    group.addButton(ui->num1, 1);
    group.addButton(ui->num2, 2);
    group.addButton(ui->num3, 3);
    group.addButton(ui->num4, 4);
    group.addButton(ui->num5, 5);
    group.addButton(ui->num6, 6);
    group.addButton(ui->num7, 7);
    group.addButton(ui->num8, 8);
    group.addButton(ui->num9, 9);
    group.addButton(ui->point, 10);

    //将按钮组与槽函数进行关联
    connect(&group, SIGNAL(buttonClicked(int)), this, SLOT(button_click(int)));

    //尾剔除按钮与槽函数进行关联
    connect(ui->X,SIGNAL(clicked(bool)),this,SLOT(on_delete_clicked()));
}

calculator::~calculator()
{
    delete ui;
}

//前后两个操作数的槽函数
void calculator::button_click(int num)
{

    if(calc == 0)
    {
        if(num == 10)            // 如果检测到按下的按钮是10，就以“.”进入计算
        {
            FirstNumber  += ".";
            ui->lineEdit->setText(FirstNumber);
        }
        else                     //如果按下的按钮是0~9，那就以0~9进入计算
        {
            FirstNumber.append(QString::number(num));
            ui->lineEdit->setText(FirstNumber);
        }
    }
    else
    {
        if(num == 10)
        {
            SecondNumber  += ".";
            ui->lineEdit->setText(SecondNumber);
        }
        else
        {
            SecondNumber.append(QString::number(num));  //后一个操作数字符串型放在ScondNumber中
            line.clear();
            line = ui->lineEdit->text();   //在输入后一个操作数时，将之前输入第一个操作数和运算符放入line中
            line +=SecondNumber;
            ui->lineEdit->setText(line);   //整条式子一并打印出来让用户看到
        }
    }
}

//运算符 "+ - * /" 的槽函数
void calculator::on_add_clicked()
{
    calc = 1;
    line.clear();
    line = ui->lineEdit->text();
    line += "+";
    ui->lineEdit->setText(line);
}

void calculator::on_sub_clicked()
{
    calc = 2;
    line.clear();
    line = ui->lineEdit->text();
    line += "-";
    ui->lineEdit->setText(line);
}


void calculator::on_mul_clicked()
{
    calc = 3;
    line.clear();
    line = ui->lineEdit->text();
    line += "*";
    ui->lineEdit->setText(line);
}


void calculator::on_dev_clicked()
{
    calc = 4;
    line.clear();
    line = ui->lineEdit->text();
    line += "/";
    ui->lineEdit->setText(line);
}


//运算符 "=" 的槽函数
void calculator::on_res_clicked()
{
    double result = 0.0;
    switch (calc)
    {
        case 1:result = FirstNumber.toDouble() + SecondNumber.toDouble();    //将第一个和第二个操作数转为Double类型
              break;
        case 2:result = FirstNumber.toDouble() - SecondNumber.toDouble();    //将第一个和第二个操作数转为Double类型
              break;
        case 3:result = FirstNumber.toDouble() * SecondNumber.toDouble();    //将第一个和第二个操作数转为Double类型
               break;
        case 4:result = FirstNumber.toDouble() / SecondNumber.toDouble();    //将第一个和第二个操作数转为Double类型
              break;
        }
    ui->lineEdit->setText(QString::number(result));    //因为setText（）只能输出字符型，所以需要将result进行转换
    calc = 0;
    FirstNumber.clear();
    SecondNumber.clear();
}

//尾剔除 按钮的槽函数
void calculator::on_delete_clicked()
{
    if(calc == 0)
    {
        FirstNumber = ui->lineEdit->text();
        FirstNumber.chop(1);
        ui->lineEdit->setText(FirstNumber);
    }
    else
    {
        SecondNumber = ui->lineEdit->text();
        SecondNumber.chop(1);
        ui->lineEdit->setText(SecondNumber);
    }
}


//其中前一个/后一个 操作数置零
void calculator::on_CE_clicked()
{
    if(calc == 0)
    {
        FirstNumber.clear();
        ui->lineEdit->setText(FirstNumber);
    }
    else
    {
        SecondNumber.clear();
        ui->lineEdit->setText(SecondNumber);
    }
}

//操作数全部置零
void calculator::on_C_clicked()
{
    FirstNumber.clear();
    ui->lineEdit->setText(FirstNumber);
    SecondNumber.clear();
    ui->lineEdit->setText(SecondNumber);
}

//“+-”按钮 槽函数
void calculator::on_pn_clicked()
{

    if(FirstNumber.at(0) == '-')     //判断第一个操作数的第0个字符是否为‘-’
    {
        // FirstNumber.at(0) = ' ';    // at（）是const修饰的，不能修改其值
         FirstNumber.replace("-","");
         ui->lineEdit->setText(FirstNumber);
    }
    else
    {
        FirstNumber = "-" + FirstNumber;
        ui->lineEdit->setText(FirstNumber);
    }

}
