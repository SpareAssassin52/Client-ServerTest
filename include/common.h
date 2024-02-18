#include<sys/socket.h>
#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdarg.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/time.h>
#include<sys/ioctl.h>
#include<netdb.h>
#include<limits.h>


#define SERVER_PORT 8989  //serverports; standard HTTP prot 80
#define BUFSIZE 4096    //size of the buffer
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 1
//#define SA struct sockaddr  //to type less

void err_n_die(const char *fmt, ...);
char *bin2hex(const unsigned char *input, size_t len);
void handle_connection(int client_socket);
int check(int exp, const char *msg);
