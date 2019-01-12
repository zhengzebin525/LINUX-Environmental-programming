#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>


int Socket(int domain, int type, int protocol);
int Connect(int fd, struct sockaddr *addr, socklen_t len);
char *http_request(char *city);
void Write(int fd, char *req, int req_len);
char *Read(int fd, char *json, int json_len);