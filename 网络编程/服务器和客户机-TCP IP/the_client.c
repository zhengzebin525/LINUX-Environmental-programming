/* 网络编程的目的就是直接或者间接通过网络协议实现计算机之间的通讯
这样就面临两个问题：
（1）如何准确定位网络上的计算机
（2）找到计算机后如何进行数据传输

现在流行的网络编程模型是客户机/服务器结构，即C/S结构

IP地址可以用来确定一台计算机，但是网络通讯的对象准确来讲并不是主机，而是主机中运行的进程.

一旦主机中有多个进程执行，光有IP地址是不够的，这时候就引入了端口号，只有IP地址和端口号对应才能确定某一个进程。
而用来描述IP地址和端口号的，就是套接字，即socket

套接字是IP/TCP通讯的基本单元，可将套接字看作不同主机之间双向通信的端点
每个进程通信需要一对套接字，客户端一个，服务器一个 */

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

//客户机

int main(int argc,char *argv[])        /*  ./the_client 192.168.91.63 (此IP必须与ubuntu的IP地址一致)  50001（端口号） */
{
	//创建套接字
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	
	//网络协议结构体
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);    //结构体的字节数
	bzero(&addr,len);                //结构体清零
	
	addr.sin_family      = AF_INET;   //存放网络协议簇
	addr.sin_addr.s_addr = inet_addr(argv[1]);  //IP地址，inet_adddr()将一个IP地址传唤为一个整数值
	addr.sin_port        = htons(atoi(argv[2])); //端口号，htons()将无符号短整型转换为网络字节序
	
	//建立与服务器的连接，会一直阻塞等待
	//试图连接服务器~~~
	connect(fd, (struct sockaddr *)&addr, len);
	
	char buf1[200];
	char buf2[200];
	
	while(1)
	{
		bzero(buf1,200);
		fgets(buf1, 200, stdin);
		//将数据传给服务器
		write(fd, buf1, strlen(buf1));
		
		bzero(buf2, 200);
		read(fd, buf2, 200);
		printf("接收到服务器信息：%s\n",buf2);
		
	}
	close(fd);
	
	return 0;
	
}











