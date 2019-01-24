
//执行程序只能在字符串界面显示，因为图像界面是显示不出来的
//ctrl+alt+F2 图形界面   ctrl+alt+F3字符串界面

#include <iostream>

#include "lcd.h"

using namespace std;

int main(int argc, char *argv[])
{

    lcd A("/dev/fb0");
    if(!A.open())
    {
        cout<<"open fail"<<endl;
        return -1;
    }
    A.setcolor(lcd::red);
    A.linew(5);
    A.setline(10,10,200,20,lcd::green);          //直线
    A.setrect(10,30,100,100,lcd::blue);          //矩形



    A.lcdclose();

    return 0;
}
