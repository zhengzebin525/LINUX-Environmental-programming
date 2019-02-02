#ifndef __PAINO_H
#define __PAINO_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>
#include <linux/input.h>
#include <semaphore.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdbool.h>

#include <linux/fb.h>
#include <linux/input.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <pthread.h>

#include "jpeglib.h"


struct image_info
{
	int width;
	int height;
	int pixel_size;
};


void display_interface();
int touch(int tp);

unsigned long read_image_from_file(int fd,
				   unsigned char *jpg_buffer,
				   unsigned long jpg_size);
				   
void display(char *filename,int x,int y);



#endif


