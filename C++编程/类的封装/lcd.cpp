#include "lcd.h"

extern "C"
{
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/mman.h>
    #include <sys/ioctl.h>
    #include <linux/fb.h>
}


lcd::lcd(string lcdname)
{
    this->lcdname = lcdname;
}

bool lcd::open()
{
    //this->lcdname.data() 将string转换成const char*类型  this->lcdname.c_str 也是一样
    this->fd = ::open(this->lcdname.data(),O_RDWR); //::去系统找open函数
    struct fb_var_screeninfo info;
    int ret = ioctl(this->fd, FBIOGET_VSCREENINFO,&info);
    if(ret < 0)
    {
        cout<<"info fail"<<endl;
        return false;
    }

    this->screen_w = info.xres_virtual;
    this->screen_h = info.xres_virtual;

    this->pixel_byte = info.bits_per_pixel/8;

    this->mapptr = mmap(NULL, this->screen_h*this->screen_w*pixel_byte,
                        PROT_READ|PROT_WRITE,MAP_SHARED,this->fd,0);

    if(this->mapptr == (void *)-1)
    {
        cout<<"mapptr fail"<<endl;
        return false;
    }
    return true;

}

void lcd::setcolor(Color color)
{
    this->lcdcolor = color;
}

void lcd::linew(int w)
{
    this->linewidth = w;
}


//直线
void lcd::setline(int x1, int y1, int x2, int y2,Color color)
{
    this->lcdcolor = color;

    unsigned int *p = (unsigned int *)this->mapptr;
    p = p+x1+y1*this->screen_w;

    for(int j=0;j<(y2-y1);j++)
    {
        for(int i=x1;i<x2;i++)
        {
            p[i] = this->lcdcolor;
        }
        p = p+this->screen_w;
    }
}

//矩形
void lcd::setrect(int x1,int y1,int x2,int y2,Color color)
{
    this->lcdcolor = color;

    unsigned int *p = (unsigned int *)this->mapptr;
    p = p+x1+y1*this->screen_w;

    for(int j=y1;j<y2;j++)
    {
        for(int i=x1;i<x2;i++)
        {
            p[i] = this->lcdcolor;
        }
        p = p+this->screen_w;
    }
}

void lcd::lcdclose()
{
    ::close(this->fd);
    free(this->mapptr);
}





