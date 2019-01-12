#include "head.h"
#include "cJSON.h"


/* gcc weather_forecast.c wrap.c -o weather_forecast -I . -I /home/gec/cJSON -L /home/gec/cJSON -lcjson */
/* （我将cJSON的库放在了家目录中）*/
 
int main(int argc,char *argv[])       
{ 
	//通过域名获取网络结构体，结构体中有IP信息,域名可以通过阿里云网站获得
	struct hostent *official = gethostbyname("ali-weather.showapi.com");
	if(official == NULL)
	{
		perror("获取服务器IP失败！\n");
		exit(0);
	}
	
	
	//从结构体中获取IP信息
	//inet_ntoa()将32位IP转换成点分十进制的IP
	char *ip = inet_ntoa(*((struct in_addr *)(official->h_addr_list[0])));
	printf("%s\n",ip);
	
	//创建套接字来试图连接服务器
	int fd = Socket(AF_INET, SOCK_STREAM, 0);
	
	
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	bzero(&addr,len);
	addr.sin_family = AF_INET;
	addr.sin_addr = *((struct in_addr *)(official->h_addr_list[0]));     //此时的IP地址需要是长整型的
	addr.sin_port = htons(80);                                           //HTTP协议端口都是80
	
	//试图连接服务器····
	int ret = Connect(fd, (struct sockaddr *)&addr, len);
	
	printf("连接服务器成功！\n");
	
	//发送报文给服务器
	printf("请输入城市名称：");
	char city[20];
	bzero(city,20);
	fgets(city,20,stdin);     //从键盘输入城市名称
	
	
	char *req = http_request(city);
	printf("要发送的报文%s\n",req);
	
	int req_len = strlen(req);
	Write(fd, req, req_len);        //从套接字中写入请求报文
	
	printf("发送报文成功！\n");
	
	//等待服务器回应，然后读取头部内容数据
	char response[1024];
	bzero(response, 1024);
	
	int i;
	for(i=0; ; i++)
	{
		read(fd, response+i, 1);                //不断地从套接字中读取数据，大小一个字节，不用太大，因为目的在于找到\r\n\r\n
		
		if(strstr(response, "\r\n\r\n"))       //找到\r\n\r\n后，此时response就停在\r\n\r\n所在地址，因为此地址后面，就是头部信息
			break;
		
	} 
	printf("响应头部：%s\n",response);
	
	//从头部信息中获取长度信息
	int json_len;
	char *p;
	
	/* 在打印出来的头部信息中，可看到Content-Length：xxxx 信息，后面xxxx那就是我们想要的数据长度，必须要得到它 */
	if((p = strstr(response,"Content-Length: ")) != NULL)
	{
		json_len = atoi(p+strlen("Content-Length: "));  //此时p+strlen("Content-Length: ")指向了xxxx，但因为是字符串，所以必须依靠atoi（）转换成整型
	}
	else
	{
		perror("cJSON数据长度获取失败！\n");
		exit(0);
	}
	printf("cJSON数据长度%d\n",json_len);
	
	//读取最终的JSON信息
	char *json = calloc(1,json_len);   /* *json的大小一定要根据cJSON长度来定义，否则cJSON *root = cJSON_Parse(json)可能会出错 */
	                
	json = Read(fd, json, json_len);
					
	printf("JSON:%s\n",json);
	
	
	//从JSON筛选出自己需要的信息
	
	cJSON *root = cJSON_Parse(json);      //将一个cJSON数据按照CJSON结构体的结构列化，并在堆中开辟一块内存来存储cJSON结构体的数据，内存大小根据括号内参数决定
	cJSON *showapi_res_body = cJSON_GetObjectItem(root,"showapi_res_body");  //从主分支下定位到名为”showapi_res_body“的分支
	cJSON *now = cJSON_GetObjectItem(showapi_res_body,"now");                //从名为”showapi_res_body“的分支下定位到名为”now“的分支
	char *temp = cJSON_GetObjectItem(now,"temperature")->valuestring;        //从名为”now“的分支下定位到名为”temperature“的分支,并将temperature的值提取出来
	/* 要向知道以上的分支情况，可在网上找一个cJSON在线视图网站
	将得到的cJSON数据拷贝到里面，便可以看到分支视图，每个分支的名字，都在里面一清二楚*/
	
	printf("当前温度:%s\n",temp); 
	
	
	return 0;
	
	
}