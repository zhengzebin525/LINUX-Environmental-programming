
#include "common.h"
#include "kernel_list.h"

void *routine(void *msg)
{
	//线程分离
	pthread_detach(pthread_self());
	
	usernode *newnode = (usernode *)msg;

	//静静等待客户端发来的消息
	
	char buf[200];
	while(1)
	{
		bzero(buf, 200);
	
		if(read(newnode->sockfd, buf, 200) == 0)
		{

			printf("[%u]已经断开\n", newnode->ID);

			close(newnode->sockfd);       //释放该用户的套接字
			list_del(&newnode->list);     //用户节点从链表中断开
			free(newnode);				  //释放用户所在节点
			
			break;
		}
		
		//以":"作为私聊标志，判断读来的数据从是否含有":"，若为真，指针real指向":",若为假，指针为NULL
		char *real = strstr(buf,":");   
	
		//说明发来的消息中没有":"，为群发消息
		if(real == NULL)
		{
			group_send(buf, newnode->ID);
		}
		//说明发来的消息中有":"，为私聊消息
		else        
		{
			printf("接收到ID: %d\n", atoi(buf));
			private(real+1, newnode->ID, atoi(buf));   //real+1 正好指向了":"后面的私聊消息部分
		}
		
	}
	pthread_exit(NULL);
}




int main(int argc, char *argv[])
{
	//用户链表初始化,建立一个头节点
	head = userlink_init();
	
	//创建套接字,采用TCP协议
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	
	//定义网络地址结构体，存放服务器的IP和端口号
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	bzero(&addr, len);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(50001);
	
	bind(fd, (struct sockaddr *)&addr, len);
	
	listen(fd, 3);
	
	//定义另外一个网络地址结构体，用来存放客户端的IP和端口号
	struct sockaddr_in cliaddr;
	socklen_t clilen = sizeof(cliaddr);

	/* 依靠时间的不断改变产生一个随机数，
	如果srand()参数不变，rand（）产生的数值就会一样 */
	srand(time(NULL));    

	int ret_write;
	char buf[200];
	while(1)
	{
		bzero(&cliaddr,clilen);
		
		//静静地等待客户端的连接······
		int sockfd = Accept(fd, (struct sockaddr *)&cliaddr, &clilen);

		printf("连接[%s:%hu]\n", 
					inet_ntoa(cliaddr.sin_addr),
					ntohs(cliaddr.sin_port));
		

		//创建一个新的用户节点，将用户套接字，用户地址，用户ID存入节点中，ID是服务器自动分配的
		uint32_t ID = rand()%10000;
		usernode *newnode = create_node(sockfd, &cliaddr, ID); 
		
		if(newnode == NULL)
		{
			close(sockfd);    //创建新节点失败，通讯已经没有意义了，断开连接套接字
			continue;
		}
	
		//将用户新节点不断加入到链表尾部
		list_add_tail(&newnode->list, &head->list);
		
		//通知用户其分配到的ID号
		char ID_buf[10];
		bzero(ID_buf, 10);
		snprintf(ID_buf, 10 ,"%u", ID);
		ret_write = write(sockfd, ID_buf, strlen(ID_buf));
		if(ret_write == -1)
		{
			printf("通知用户ID号失败!\n");
		}
		
		//创建一条线程，处理客户端发来的信息
		
		pthread_t tid;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		pthread_create(&tid, &attr, routine, (void *)newnode);
		
		
	}
	
	return 0;
	
}