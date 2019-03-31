#ifndef __DLINKLIST_H
#define __DLINKLIST_H

#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>
#include <dlfcn.h>
#include <strings.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/fb.h>
#include <linux/un.h>
#include <linux/input.h>

#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct node           //链表的结构体
{
	char *name;
	struct node *next;
	struct node *prev;
}*dlinklist;


bool is_empty(dlinklist head);
dlinklist init_dlinklist();
dlinklist node_dlinklist(char *file_name);
void dlinklist_move_tail(dlinklist new,dlinklist head);
void show_dlinklist(dlinklist head);




#endif


