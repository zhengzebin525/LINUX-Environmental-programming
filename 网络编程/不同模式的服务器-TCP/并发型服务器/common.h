#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

#include "kernel_list.h"


typedef struct node
{
	int sockfd;
	struct sockaddr_in addr;
	uint32_t ID;
	
	struct list_head list;      //内核链表
	
}usernode , *userlink;          //用户链表


//链表头节点，定义为全局变量
userlink head;


userlink userlink_init();
usernode *create_node(int sockfd, struct sockaddr_in *addr, uint32_t ID);
int Accept(int fd, struct sockaddr *addr, socklen_t *clilen);
void group_send(char *buf, uint32_t sender_ID);
void private(char *buf, uint32_t sender_ID, uint32_t receiver_ID);



int Socket(int domain, int type, int protocol);
int Connect(int fd, const struct sockaddr *addr, socklen_t len);


