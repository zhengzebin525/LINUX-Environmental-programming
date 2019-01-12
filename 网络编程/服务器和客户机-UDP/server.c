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



int main(int argc,char *argv[])
{
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
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(50001);
	
	int bind_ret = bind(fd, (struct sockaddr*)&addr, len);
	if(bind_ret == -1)
	{
		perror("地址绑定失败！\n");
		exit(0);
	}
	
	struct sockaddr_in cliaddr;
	socklen_t clilen = sizeof(cliaddr);
	bzero(&cliaddr, clilen);
	
	char buf[200];
	while(1)
	{
		bzero(buf, 200);
		
		recvfrom(fd, buf,200, 0, (struct sockaddr*)&cliaddr,&clilen);
		
		printf("接收到来自[%s:%hu]的数据：%s",
				inet_ntoa(cliaddr.sin_addr),
				ntohs(cliaddr.sin_port),
				buf);
				
		sendto(fd, buf, strlen(buf), 0, (struct sockaddr*)&cliaddr, clilen);
				
	}
	
	return 0;
	
}





