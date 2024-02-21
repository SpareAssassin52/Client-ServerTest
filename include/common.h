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
#include<queue>
#include<iostream>
#include<mutex> //a synchronization primitive that ensures only one thread can access a critical section of code at a time.

#define SERVER_PORT 8989  //serverports; standard HTTP prot 80
#define BUFSIZE 4096    //size of the buffer
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100  //queue client connection requests. allowing waiting connections depending on the number of backlog
#define THREAD_POOL_SIZE 2
//#define SA struct sockaddr  //to type less

void err_n_die(const char *fmt, ...);   //print out error then shut down program.
char *bin2hex(const unsigned char *input, size_t len);
void *handle_connection(void *client_socket);    //to call the function in a way that pthread_create() wants.
int check(int exp, const char *msg);    //print out errors.

extern std::queue<int*> qclient_socket; //queue for threads to process sockets.
void *thread_function(void *arg);   
extern std::mutex mtx;  //making it global so that it can lock up the queue in tcpMultiserver.cpp