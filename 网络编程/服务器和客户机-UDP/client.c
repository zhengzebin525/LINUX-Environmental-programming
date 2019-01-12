#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/fb.h>
#include <linux/un.h>

#include <arpa/inet.h>
#include <netinet/in.h>

//编写一个基于 UDP 的镜子服务器，将客户端发送过来的数据照原样反弹回去。

int main(int argc,char *argv[])
{
	//创建UDP通信端点，SOCK_DGRAM表示采用UDP协议
	/* UDP协议特征：
	1、发送的数据，肯能会无序到达接收端
	2、数据可能丢失，丢失了不会采取任何不久措施，而且接受端也不知道有数据丢失
	3、数据有尺寸大小限制 */
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd == -1)
	{
		perror("socket()发生错误\n");
		exit(0);
	}
	
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	bzero(&addr,len);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(atoi(argv[2]));
	
	char buf[200];
	while(1)
	{
		bzero(buf, 200);
		fgets(buf,200, stdin);
		
		/* 将数据传给对方主机，UDP协议中socket可以不进行连接操作
		参数4：是一个标志位，一般设为0
		参数5：对方主机的套接字标准地址
		参数6：对方主机地址的长度 */
		sendto(fd, buf, strlen(buf), 0, (struct sockaddr*)&addr, len);
		
     	bzero(buf, 200);
		
		/* 接收来自cliaddr地址的数据，函数中有一个地址的参数，可以自己手动输入
		参数1：套接字描述符
		参数4：调用方式标志位，一般为0
		参数5：目的套接字的标准地址
		参数6：目的地址的长度 */
		recvfrom(fd, buf,200, 0, (struct sockaddr*)&addr,&len);
		
		printf("接受到服务器信息：%s",buf);
	}
	
	return 0;
	
}