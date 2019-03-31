#include "dlinklist.h"



bool is_empty(dlinklist head)        //判断链表是否为空
{
	if(head->next==head)
		return true;
	else
		return false;
}

dlinklist init_dlinklist()                //初始化链表
{
	dlinklist head = calloc(1,sizeof(struct node));
	if(head == NULL)
	{
		perror("链表内存申请失败!\n");
		exit(0);
	}
	head->next = head;
	head->prev = head;
	return head;
}


dlinklist node_dlinklist(char *file_name)       //初始化新节点
{
	dlinklist new = calloc(1,sizeof(struct node));
	if(new == NULL)
	{
		perror("节点内存申请失败！\n");
		exit(0);
	}
	new->name = file_name;
	new->next = new;
	new->prev = new;
	return new;
}



void dlinklist_move_tail(dlinklist new,dlinklist head)     //将新节点放置在链表尾部
{
	dlinklist temp = head->prev;
	
	temp->next = new;
	new->prev = temp;
	head->prev = new;
	new->next = head;
}


void show_dlinklist(dlinklist head)
{
	if(is_empty(head))
	{
		perror("链表为空，无法打印！\n");
		exit(0);
	}
	dlinklist temp = head->next;
	while(temp != head)
	{
		printf("%s\n",temp->name);
		temp = temp->next;
	}
}