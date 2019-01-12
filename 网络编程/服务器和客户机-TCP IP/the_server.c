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

//服务器

int main(int argc,char *argv[])
{
	//创建一个套接字
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	
	bzero(&addr, len);    //初始化结构体
	
	addr.sin_family      = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);  //htonl()将主机数转换为无符号长整型的网络字节序，INADDR_ANY表示所有的网卡IP都可以作为服务器的IP地址，说白了就是自动获取IP
	addr.sin_port        = htons(50001);       //htons()将无符号短整型转换为网络字节序
	
	//将本地地址与一套接字接口绑定
	bind(fd, (struct sockaddr *)&addr, len);
	
	
	// 设置监听状态和最大同时连接数
	//将未连接的套接字转换为一个被动套接字
	listen(fd, 3);  //连接数是7，默认已经有了4个
	
	struct sockaddr_in cliaddr;
	socklen_t clilen = sizeof(cliaddr);
	bzero(&cliaddr,clilen);
	
	//阻塞等待客户端的连接请求
	int sockfd = accept(fd, (struct sockaddr *)&cliaddr,&clilen);
	//等待成功后获得客户端套接字的IP地址和端口信息
	printf("欢迎[%s:%hu]\n",
			inet_ntoa(cliaddr.sin_addr),  //将一个32位IP地址转换为十进制IP地址
			ntohs(cliaddr.sin_port));  	  //将16位网络字节序转换为主机字节序

	char buf[200];
	while(1)
	{
		bzero(buf,200);
		if(read(sockfd, buf, 200) == 0)
			break;
		
		write(sockfd, buf, strlen(buf));
		
	}
	
	close(sockfd);
	close(fd);
	return 0;
}