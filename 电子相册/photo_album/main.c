

#include "show_jpeg.h"
#include "dlinklist.h"


//获取触屏时第一个坐标的横坐标
int swiping_first_point(int tp,struct input_event buf,int x1);
	
//读取里面的目录项（每一个文件都是一个目录项），将目录dp中的文件名信息放到链表节点中
void store_information(struct dirent *ep,DIR *dp,dlinklist head);  

// 根据参数的后缀，决定要加载哪个动态库,让 display函数指针指向库中的具体的函数
void Load_dynamic_library();





int main(int argc, char **argv) // ./showimg [image]
{
	//链表的代码
	dlinklist head = init_dlinklist();              //链表初始化
	
	//打开目录
	DIR *dp = opendir(argv[1]);
	// 进入目录
	chdir(argv[1]);

	struct dirent *ep;
	// 读取里面的目录项（每一个文件都是一个目录项），将目录dp中的文件名信息放到链表节点中
	store_information(ep,dp,head);      
	//将链表信息打印出来
	show_dlinklist(head);               

	// 根据参数的后缀，决定要加载哪个动态库，让 display函数指针指向库中的具体的函数
	Load_dynamic_library();

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
     x1 = swiping_first_point(tp,buf,x1);      //获取触屏时第一个坐标的横坐标

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
	
	if(x2 - x1 >= 50 )
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
	
	 if(x2 - x1 <50)
	{
		display(photo->name, fbmem, &vinfo, 0, 0);
	}	
	
	  if(x1 - x2 > 50 )
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
	
	 if(x1 - x2 < 50)
	{
		 display(photo->name, fbmem, &vinfo, 0, 0);
	}
}

	// 3，释放资源
	close(tp);
	return 0;
}







//获取触屏时第一个坐标的横坐标
int swiping_first_point(int tp,struct input_event buf,int x1)
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
	return x1;
}
//读取里面的目录项（每一个文件都是一个目录项），将目录dp中的文件名信息放到链表节点中
void store_information(struct dirent *ep,DIR *dp,dlinklist head)  
{
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
}

// 根据参数的后缀，决定要加载哪个动态库,让 display函数指针指向库中的具体的函数
void Load_dynamic_library()
{
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
}








