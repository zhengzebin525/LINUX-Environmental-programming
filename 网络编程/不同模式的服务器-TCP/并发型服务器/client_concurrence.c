
#include "common.h"

void *routine(void *msg)
{
	pthread_detach(pthread_self());
	
	int fd = *(int *)msg;
	
	char buf[200];
	
	while(1)
	{
		bzero(buf, 200);
		
		read(fd, buf, 200);
		
		printf("接收到的信息：%s\n", buf);
	}
	pthread_exit(NULL); 
}


int main(int argc,char *argv[])
{
	int fd = Socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	bzero(&addr, len);
	
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(atoi(argv[2]));
	
	Connect(fd, (struct sockaddr *)&addr, len);    //成功返回0，失败返回-1
	
	printf("连接服务器成功\n");
	
	char id[10];
	bzero(id, 10);
	read(fd, id, 10);
	printf("我的ID:%s\n", id);

	//创建一个线程，迎来接收服务器发来的数据
	pthread_t tid;
	pthread_create(&tid, NULL,routine, (void *)&fd);
	
	//主线程，用来向服务器发送数据
	char buf[200];

	while(1)
	{
		
		bzero(buf, 200);
		
		fgets(buf, 200, stdin);
		
	    write(fd, buf, 200);
			
		
	}
	
}