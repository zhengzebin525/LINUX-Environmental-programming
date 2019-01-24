#ifndef LCD_H
#define LCD_H

#include <iostream>
using namespace std;

class lcd
{
public:
    enum Color{red=0xff0000,green=0x00ff00,blue=0x0000ff};

public:
    lcd(string lcdname);
    bool open();
    void setcolor(Color color);
    void linew(int w);
    void setline(int x1,int y1,int x2,int y2,Color color);
    void setrect(int x1,int y1,int x2,int y2,Color color);
    void lcdclose();

private:
    string lcdname;
    Color lcdcolor;
    int linewidth;
    int fd;
    int screen_w,screen_h,pixel_byte;
    void *mapptr;

};

#endif // LCD_H
