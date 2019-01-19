
#include "common.h"
#include "kernel_list.h"

//======================server====================================

userlink userlink_init()
{
	userlink head = calloc(1, sizeof(usernode));
	if(head == NULL)
	{
		printf("用户链表初始化失败！\n");
		exit(0);
	}
	
	INIT_LIST_HEAD(&head->list);
	return head;
}

usernode *create_node(int sockfd, struct sockaddr_in *addr, uint32_t ID)
{
	userlink newnode = calloc(1, sizeof(usernode));
	if(newnode == NULL)
	{
		printf("创建用户新节点失败！\n");  
	}
	else
	{
		newnode->sockfd = sockfd;
		newnode->addr = *addr;    //addr是取地址进来的，所以需要解引用
		newnode->ID = ID;

		INIT_LIST_HEAD(&newnode->list);      //节点初始化，让它自己指向自己
	}
	
	return newnode;
}


int Accept(int fd, struct sockaddr *addr, socklen_t *clilen)
{
		int sockfd = accept(fd, addr, clilen);
		if(sockfd == -1)
		{
			printf("连接失败！\n");
			exit(0);
		}
		return sockfd;
}



void group_send(char *buf, uint32_t sender_ID)
{
	struct list_head *pos;
	usernode *p;
	
	list_for_each(pos, &head->list)
	{
		p = list_entry(pos, usernode, list);
		
		if(p->ID == sender_ID)
			continue;
		
		write(p->sockfd, buf, strlen(buf));
		
	}
}

void private(char *buf, uint32_t sender_ID, uint32_t receiver_ID)
{
	struct list_head *pos;
	usernode *p;
	
	char msg[200];
	list_for_each(pos, &head->list)
	{
		p = list_entry(pos, usernode, list);
		
		//将消息私发给指定的ID
		if(p->ID == receiver_ID)
		{
			bzero(msg, strlen(msg));
			
			snprintf(msg, 200, "来自【%u】：%s\n", sender_ID, buf);
			
			write(p->sockfd, msg, strlen(msg));
		}
		else
		{
			continue;
		}
	}
	
	printf("此ID[%u]无效\n", receiver_ID);
}

//===================================client=====================================

int Socket(int domain, int type, int protocol)
{
	int fd = socket(domain, type, protocol);
	if(fd == -1)
	{
		perror("客户端创建套接字失败！\n");
		exit(0);
	}
	return fd;
}

int Connect(int fd, const struct sockaddr *addr, socklen_t len)
{
	int sockfd = connect(fd, addr, len);
	if(sockfd == -1)
	{
		printf("连接服务器失败\n");
		exit(0);
	}
	return sockfd;
}













