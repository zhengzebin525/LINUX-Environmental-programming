
#include "paino.h"

extern key;
extern voice;
extern suspend;    //标志位，判断是否按到了暂停键，默认没按到


void *routine(void *msg)
{
	pthread_detach(pthread_self());
	int key_num = *(int *)msg;
	
	char buf[50];
	system("killall -s SIGKILL madplay");
	snprintf(buf,30,"madplay ./mp3/d%d.mp3 -a %d",key_num,voice);
	system(buf);
	
	pthread_exit(NULL);      //退出当前子线程
}



int main(int argc,char *argv[])
{
	
	pthread_t tid;
	
	//显示主界面
	display_interface();
	
	//手指触摸钢琴，显示按下去的效果
	int tp = open("/dev/input/event0",O_RDONLY);
	
	int key_num;
	int key_x;
	
	int former = 0;     //表示前状态的按键序号
	int now = 0;        //表示现在状态的按键序号
	int move = 753;
	
	
	
	while(1)
	{
		//小图标满天飞
		display("./jpg/heart.jpg",move,0);
		move -= 10;
		if(move < 205)
		{
			move = 753;
		}
		display("./jpg/bar.jpg",0,0);
		
		//前一个状态的琴键序号
		former = now;
		//返回当前状态的琴键序号
		now = touch(tp);    
		
			if(now >=1 && now <= 12)
			{
				printf("The key number of paino = %d\n",now);

				if(now != former)
				{
			
					display("./jpg/key_on.jpg",10+(now-1)*65,47);
					
					//创建一个线程,通过钢琴序号决定每个按键发出的音频
					pthread_create(&tid, NULL, routine, (void *)&now);  
					
					int i,j;
					for(i=0;i<(now-1);i++)
					{
						display("./jpg/key_off.jpg",10+i*65,47);
					}
					for(j=now;j<12;j++)
					{
						display("./jpg/key_off.jpg",10+j*65,47);
					}
				}
			}
	}
	
	 pthread_exit(NULL);     //退出当前主线程            
}
