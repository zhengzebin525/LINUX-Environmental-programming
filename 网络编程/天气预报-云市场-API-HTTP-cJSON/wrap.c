

#include "head.h"
#include "cJSON.h"

int Socket(int domain, int type, int protocol)
{
	int fd = socket(domain, type, protocol);
	if(fd == -1)
	{
		perror("套接字创建失败!\n");
		exit(0);
	}
	return fd;
}


int Connect(int fd, struct sockaddr *addr, socklen_t len)
{
	int ret = connect(fd, addr, len);
	if(ret == -1)
	{
		perror("连接服务器失败！\n");
		exit(0);
	}
	return ret;
}

char *http_request(char *city)
{
    static char buf[500];    //如果不加static ，编译会提醒函数返回本地变量的地址，执行时甚至会发生段错误
	bzero(buf, 500);
	
    /* 首先在阿里云找一个提供天气预报云服务的API云端，购买服务后进入调试工具，以下的信息就是在里面找到的
	GET 是Http Method
	/spot-to-weather 是Path格式
	HTTP/1.1 指的是HTTP协议
	ali-weather.showapi.com   是提供服务的云端的域名
	17e8b5a89e2544b289d4ad1a2fee4052 购买后可在购物车或者管理控制台找到 
	因为从键盘输入的city变量中含有\n字符，所以用strtok（）函数将\n去掉 */
	
	snprintf(buf, 500, "GET /spot-to-weather?area=%s HTTP/1.1\r\n"			
						"Host: ali-weather.showapi.com\r\n"
						"Authorization:APPCODE 17e8b5a89e2544b289d4ad1a2fee4052\r\n\r\n",
						strtok(city,"\n"));
						
	return buf;
}


void Write(int fd, char *req, int req_len)
{
	int m;
	while(req_len > 0)              //不断地从套接字中写入请求报文
	{
		m = write(fd, req, req_len);
		req_len -= m;
		req += m;
	}
}


char *Read(int fd, char *json, int json_len)
{
	int total = 0;
	while(json_len > 0)
	{
		int n = read(fd, json+total, json_len);      //不断地从套接字中读取cJSON信息
		json_len -= n;
		total += n;
	}
	return json;
}
























