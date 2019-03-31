#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>
#include <dlfcn.h>
#include <strings.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/fb.h>
#include <linux/un.h>
#include <linux/input.h>

#include <arpa/inet.h>
#include <netinet/in.h>

//#include "show_jpeg.h"

typedef struct node           //链表的结构体
{
	char *name;
	struct node *next;
	struct node *prev;
}*dlinklist;

bool is_empty(dlinklist head);
dlinklist init_dlinklist();
dlinklist node_dlinklist(char *file_name);
void dlinklist_move_tail(dlinklist new,dlinklist head);
void show_dlinklist(dlinklist head);

char *init_lcd(struct fb_var_screeninfo *vinfo)
{
	int lcd = open("/dev/fb0", O_RDWR);

	ioctl(lcd, FBIOGET_VSCREENINFO, vinfo);
	int bpp = vinfo->bits_per_pixel;
	int screensize = vinfo->xres * vinfo->yres * bpp/8;

	char *fbmem = mmap(NULL, screensize, PROT_READ|PROT_WRITE,
			   MAP_SHARED, lcd, 0);
	if(fbmem == MAP_FAILED)
	{
		perror("映射显存失败");
		exit(0);
	}
	return fbmem;
}

void usage(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("参数不对\n");
		exit(0);
	}
}

int main(int argc, char **argv) // ./showimg [image]
{
	// 判断参数的合法性（必须要有一个图片参数，用来指定要显示的图片）
	//usage(argc, argv);
	
	//链表的代码
	dlinklist head = init_dlinklist();              //链表初始化
	
	//打开目录
	DIR *dp = opendir(argv[1]);
	// 进入目录
	chdir(argv[1]);
	// 读取里面的目录项（每一个文件都是一个目录项）
	struct dirent *ep;
	while(1)
	{
		ep = readdir(dp);    //开始读取目录中的文件
		if(ep == NULL)
			break;
		if(ep->d_name[0] == '.')
			continue;
		dlinklist new = node_dlinklist(ep->d_name);    //将文件名放入新节点
		if(new == NULL)
		{
			perror("节点返回地址失败！\n");
			exit(0);
		}
		dlinklist_move_tail(new,head);    //将新节点放入链表尾部
		if(ep == NULL)
		{
			printf("目录读取完毕\n");
			break;
		}
	}
	show_dlinklist(head);               //将链表信息打印出来

	// 根据参数的后缀，决定要加载哪个动态库
	char *lib;
	lib = "libjpg.so";

	// 动态加载动态库
	void *handle = dlopen(lib/*指定的动态库名称*/, RTLD_NOW/*立即解析库中的符号*/);
	if(handle == NULL)
	{
		perror("打开动态库失败");	
		exit(0);
	}
	

	// 定义你要用到的库中的符号（函数）: display
	void (*display)(char *imgfile, char *fbmem,
			struct fb_var_screeninfo *vinfo,
			int xoffset, int yoffset);

	// 让 display 指向库中的具体的函数
	display = dlsym(handle, "display");
	if(display == NULL)
	{
		perror("查找符号失败");
		exit(0);
	}

	// 准备好 LCD 设备
	struct fb_var_screeninfo vinfo;
	bzero(&vinfo, sizeof(vinfo));
	char *fbmem = init_lcd(&vinfo);

	  dlinklist photo = head->next;
	// 把指定的图片 argv[1] 丢该 display 函数去处理
	display(photo->name, fbmem, &vinfo, 0, 0);
	
	
	// 1，打开触摸屏文件
	int tp = open("/dev/input/event0", O_RDONLY);
	
	// 2，读取触摸屏信息
	struct input_event buf; // 输入数据结构体
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int x_0 = 0;
	int x_1 = 0;
	int i=0;
	
while(1)
{

	while(1)
	{
		bzero(&buf, sizeof(buf));
		read(tp, &buf, sizeof(buf)); // 读取触摸屏数据，放到 buf 中
		if(buf.type == EV_ABS)
		{
			if(buf.code == ABS_X)
			{
				x1 = buf.value;
				//printf("x1 = %d\n",x1);
				break;
			}
		}
	}
	

	while(1)
	{
		bzero(&buf, sizeof(buf));
		read(tp, &buf, sizeof(buf)); // 读取触摸屏数据，放到 buf 中

		// 读到触摸屏的坐标事件
		if(buf.type == EV_ABS)
		{
			// 读到x轴坐标
				if(buf.code == ABS_X)
			   {
				  if(i%2==0)
				  {
					   x_0 = buf.value;
				     printf("x_0 = %d\n ", buf.value);
				  }
				  
				  
				  if(i%2 == 1)
				  {
					  x_1 = buf.value;
				     printf("x_1 = %d\n ", buf.value);
				  } 
				  
				//printf("%d\n ", buf.value);
			  }
		}
		
		// 读到按键事件（包括键盘、触摸屏的按压、鼠标的左右键……）
		if(buf.type == EV_KEY)
		{
			
			// 读到触摸屏的按压事件
			if(buf.code == BTN_TOUCH)
			{
				 //读到按下触摸屏
				if(buf.value > 0)
					continue;

				// 读到松开触摸屏
				if(i%2== 0 && buf.value == 0)
				  {
					x_0 = buf.value;
					break;
				  }
					
				if(i%2== 1 && buf.value == 0)
				  {
					x_1 = buf.value;
					break;
				  }
					
			}
		}
		
		i++;
	}
	
	printf("x1 = %d\n",x1);
	printf("x_0 = %d\n",x_0);
	printf("x_1 = %d\n",x_1);
	if(x_0 !=0)
		x2 = x_0;
	if(x_1 != 0)
		x2 = x_1;
	
	printf("x2 = %d\n",x2);
	printf("\n");
	
	if(x3 == x2)
	{
		display(photo->name, fbmem, &vinfo, 0, 0);
		continue;
	}
	x3 = x2;
	
	/*
	if(x_0 - x1 < 20|| x_1 - x1 <20)
		continue;
	if(x1 - x_0 < 20 || x1 - x_1 < 20)
		continue;
	*/
	
	if(x2 - x1 >= 150 )
	{
		if(x_0!=0 ||x_1!=0)
		{
			photo = photo->next;
		   if(photo == head)
		  {
			photo = head->next;
		  }
		   display(photo->name, fbmem, &vinfo, 0, 0);
		}
	}
	
	 if(x2 - x1 <150)
	{
		display(photo->name, fbmem, &vinfo, 0, 0);
	}	
	
	  if(x1 - x2 > 100 )
	{
		if(x_0!=0 || x_1!=0)
		{
			photo = photo->prev;
		   if(photo == head)
		   {
			photo = head->prev;
		   }
		   display(photo->name, fbmem, &vinfo, 0, 0);
		}
	}
	
	 if(x1 - x2 < 100)
	{
		 display(photo->name, fbmem, &vinfo, 0, 0);
	}

		
	//printf("x1 = %d\n",x1);
	//printf("x_0 = %d\n",x_0);
	//printf("x_1 = %d\n",x_1);
	//printf("x2 = %d\n",x2);
	//printf("\n");
	

}
	// 3，释放资源
	close(tp);
	return 0;
}



bool is_empty(dlinklist head)        //判断链表是否为空
{
	if(head->next==head)
		return true;
	else
		return false;
}

dlinklist init_dlinklist()                //初始化链表
{
	dlinklist head = calloc(1,sizeof(struct node));
	if(head == NULL)
	{
		perror("链表内存申请失败!\n");
		exit(0);
	}
	head->next = head;
	head->prev = head;
	return head;
}


dlinklist node_dlinklist(char *file_name)       //初始化新节点
{
	dlinklist new = calloc(1,sizeof(struct node));
	if(new == NULL)
	{
		perror("节点内存申请失败！\n");
		exit(0);
	}
	new->name = file_name;
	new->next = new;
	new->prev = new;
	return new;
}



void dlinklist_move_tail(dlinklist new,dlinklist head)     //将新节点放置在链表尾部
{
	dlinklist temp = head->prev;
	
	temp->next = new;
	new->prev = temp;
	head->prev = new;
	new->next = head;
}


void show_dlinklist(dlinklist head)
{
	if(is_empty(head))
	{
		perror("链表为空，无法打印！\n");
		exit(0);
	}
	dlinklist temp = head->next;
	while(temp != head)
	{
		printf("%s\n",temp->name);
		temp = temp->next;
	}
}









