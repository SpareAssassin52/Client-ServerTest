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
#include<pthread.h> //to creat threads.
#include<thread>    //c++ version threads.
#include<queue>
#include<iostream>
#include<mutex> //a synchronization primitive that ensures only one thread can access a critical section of code at a time.
#include<condition_variable>    //to control threads.
#include<vector>

#define SERVER_PORT 8989  //serverports; standard HTTP prot 80
#define BUFSIZE 4096    //size of the buffer
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100  //queue client connection requests. allowing waiting connections depending on the number of backlog
#define THREAD_POOL_SIZE 10
//#define SA struct sockaddr  //to type less

void err_n_die(const char *fmt, ...);   //print out error then shut down program.
char *bin2hex(const unsigned char *input, size_t len);
//void *handle_connection(void *p_client_socket);    //to call the function in a way that pthread_create() wants.
void *handle_connection(int client_socket); 
int check(int exp, const char *msg);    //print out errors.

extern std::queue<int*> qclient_socket; //queue for threads to process sockets.
void *thread_function(void *arg);       //C
void thread_functioncpp();     //C++
extern std::mutex mtx;  //making it global so that it can lock up the queue in tcpMultiserver.cpp   C++
//std::unique_lock<std::mutex> lk(mtx);     //unique_lock can't be a global varible.
extern std::condition_variable cv;//global condition variable. C++

int setup_server(short port, int backlog);  
int accept_new_connection(int server_socket);