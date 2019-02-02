

#include "paino.h"

bool key = 0;
int voice = -20;      //正常音量 -50
int suspend = 0;        //标志位，判断是否按到了暂停键，默认没按到

//显示主界面
void display_interface()         
{
	display("./jpg/background.jpg",0,0);      //背景
	display("./jpg/bar.jpg",0,0);         //头条
	
	int key_num;
	for(key_num=0;key_num<12;key_num++)
	{
		display("./jpg/key_off.jpg",10+key_num*65,47);     //钢琴按键,未按下时
	}
	display("./jpg/logo.jpg",230,370);             //logo图片
	
	display("./jpg/voice01.jpg",10,370);          //上调音量健
	display("./jpg/voice02.jpg",100,370);         //下调音量健
	
}


int touch(int tp)
{
	if(tp == -1)
	{
		perror("触摸屏文件打开失败！\n");
		exit(0);
	}
	
	struct input_event buf;
	
	int key_x;
	int key_y;
	int num;             //用来表示按键序号
	
	while(1)
	{
        bool xdone;
	 
		bzero(&buf,sizeof(buf));
	    read(tp,&buf,sizeof(buf));
		
		if(buf.type == EV_ABS)
		{
			if(buf.code == ABS_X)
			{
				key_x = buf.value;
				xdone = 1;
				//printf("(%d ,",key_x);
			}
				
			if(buf.code ==ABS_Y)
			{
				key_y = buf.value;
				//printf(" %d)\n",key_y);
			}
		}

		if(key_y >=47 && key_y <=327 && xdone == 1)
		{
			switch(key_x)
			{

				case 0 ... 75:
						key = 1;       //表示手指按下了
						num = 1;
						return num;
				case 76 ... 724:
						key = 1; 
						num = (key_x/65)+1;
				        return num;
				case 725 ... 800:
						key = 1;
						num = 12;
						return num;	
				default:
					return 0;
			}
		}
		
		if(key_x >= 10 && key_x <= 75 &&
		   key_y >= 370 && key_y <= 435)
		{
		    voice++;	                          //音量+1
			printf("voice = %d\n",voice);
		}
		if(key_x >= 100 && key_x <= 165 &&
		   key_y >= 370 && key_y <= 435)
		{
			   voice--;						     //音量-1
			   printf("voice = %d\n",voice);
		}
	
		
		if(key_x >= 230 && key_x <= 572 &&       //退出程序
		   key_y >=370 && key_y <= 436)
		{
			printf("The ending!\n");
			display("./jpg/cat02.jpg",0,0);
			close(tp);
			break;
		}
	    
	
	
	   
		  if(buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0)
		{
			key = 0;                             //表示手指已经离开
			 int i;
			for(i=0;i<12;i++)
			{
				display("./jpg/key_off.jpg",10+i*65,47);     
			} 
			return num;	
		}   	
	}
}





// 将jpeg文件的压缩图像数据读出，放到jpg_buffer中去等待解码
unsigned long read_image_from_file(int fd,
				   unsigned char *jpg_buffer,
				   unsigned long jpg_size)
{
	unsigned long nread = 0;
	unsigned long total = 0;

	while(jpg_size > 0)
	{
		nread = read(fd, jpg_buffer, jpg_size);

		jpg_size -= nread;
		jpg_buffer += nread;
		total += nread;
	}
	close(fd);

	return total;
}

//显示图片在指定坐标
void display(char *filename,int x,int y)    //图片名  x坐标   y坐标
{
	// ***** 1、读取JPG格式的图片文件 ****** //

	// 读取图片文件属性信息
	// 并根据其大小分配内存缓冲区jpg_buffer
	struct stat file_info;
	int ret_stat = stat(filename, &file_info);
	if(ret_stat == -1)
	{
		perror("结构体stat读取数据失败！\n");
		exit(0);
	}
	int fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		perror("图片文件打开失败！\n");
		exit(0);
	}

	unsigned char *jpg_buffer;
	jpg_buffer = (unsigned char *)calloc(1, file_info.st_size);
	read_image_from_file(fd, jpg_buffer, file_info.st_size);


	// ***** 2、将JPG格式解码成RGB ****** //

	// 声明解码缩结构体，以及错误管理结构体
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	// 使用缺省的出错处理来初始化解码缩结构体
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	// 配置该cinfo，使其从jpg_buffer中读取jpg_size个字节
	// 这些数据必须是完整的JPEG数据
	jpeg_mem_src(&cinfo, jpg_buffer, file_info.st_size);


	// 读取JPEG文件的头，并判断其格式是否合法
	int ret = jpeg_read_header(&cinfo, true);
	if(ret != 1)
	{
		fprintf(stderr, "[%d]: jpeg_read_header failed: "
			"%s\n", __LINE__, strerror(errno));
		exit(1);
	}

	// 开始解码
	jpeg_start_decompress(&cinfo);

	struct image_info imageinfo;
	imageinfo.width = cinfo.output_width;
	imageinfo.height = cinfo.output_height;
	imageinfo.pixel_size = cinfo.output_components;

	int row_stride = imageinfo.width * imageinfo.pixel_size;

	// 根据图片的尺寸大小，分配一块相应的内存rgb_buffer
	// 用来存放从jpg_buffer解码出来的图像数据
	unsigned long rgb_size;
	unsigned char *rgb_buffer;
	rgb_size = imageinfo.width *
			imageinfo.height * imageinfo.pixel_size;
	rgb_buffer = (unsigned char *)calloc(1, rgb_size);

	// 循环地将图片的每一行读出并解码到bmp_buffer中
	int line = 0;
	while(cinfo.output_scanline < cinfo.output_height)
	{
		unsigned char *buffer_array[1];
		buffer_array[0] = rgb_buffer +
				(cinfo.output_scanline) * row_stride;
		jpeg_read_scanlines(&cinfo, buffer_array, 1);
	}

	// 解码完了，将jpeg相关的资源释放掉
 	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	free(jpg_buffer);
	
	// ***** 3、将RGB数据，妥善地放到显存中 ****** //
	
	// 准备LCD屏幕
	int lcd = open("/dev/fb0", O_RDWR);
	if(lcd == -1)
	{
		perror("lcd文件打开失败！\n");
		exit(0);
	}

	// 获取LCD设备的当前参数
	struct fb_var_screeninfo vinfo;
	ioctl(lcd, FBIOGET_VSCREENINFO, &vinfo);

	// 根据当前LCD设备参数申请适当大小的FRAMEBUFFR
	unsigned char *FB;
	unsigned long bpp = vinfo.bits_per_pixel;
	FB = mmap(NULL, vinfo.xres * vinfo.yres * bpp/8,
		  PROT_READ|PROT_WRITE, MAP_SHARED, lcd, 0);
		  
	// 将bmp_buffer中的RGB图像数据，写入LCD的FRAMEBUFFER中
	//write_lcd(bmp_buffer, &imageinfo, FB, &vinfo);
	
	//bzero(FB, vinfo.xres * vinfo.yres * 4);
	
	FB += (vinfo.xres * y + x)* vinfo.bits_per_pixel/8;
	
	int lcd_w = imageinfo.width;
	int lcd_h = imageinfo.height;
	
	int row,column;

	for(row=0; row<lcd_h ; row++)                  //以列 打印像素点
	    {
		   for(column=0; column<lcd_w ; column++)   //以行 打印像素点
		    {
			unsigned long lcd_offset = (vinfo.xres*row + column) * 4;
			unsigned long rgb_offset = (imageinfo.width*row+column) *
						    imageinfo.pixel_size;

			memcpy(FB + lcd_offset + vinfo.red.offset/8,
			       rgb_buffer + rgb_offset + 0, 1);
			memcpy(FB + lcd_offset + vinfo.green.offset/8,
			       rgb_buffer + rgb_offset + 1, 1);
			memcpy(FB + lcd_offset + vinfo.blue.offset/8,
			       rgb_buffer + rgb_offset + 2, 1);
		    }
	    }
	close(lcd);
}