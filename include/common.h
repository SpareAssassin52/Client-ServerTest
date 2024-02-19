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
#include<string>
#include<pthread.h> //to creat threads

#define SERVER_PORT 8989  //serverports; standard HTTP prot 80
#define BUFSIZE 4096    //size of the buffer
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100  //queue client connection requests. allowing waiting connections depending on the number of backlog
//#define SA struct sockaddr  //to type less

void err_n_die(const char *fmt, ...);
char *bin2hex(const unsigned char *input, size_t len);
void *handle_connection(void *client_socket);    //to call the function in a way that pthread_create() wants.
int check(int exp, const char *msg);
