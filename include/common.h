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


#include"jsonrpc.h"
#include"jsonrpc_server.h"

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

class zyd{
    public:
        bool Print(const Json::Value& root, Json::Value& response)     //reply with success
        {    std::cout<< "Receive query: "<< root << std::endl;
            response["jsonrpc"] = "2.0";
            response["id"] = root["id"];
            response["result"] = "success";
            return true;
        }
        bool Notify(const Json::Value& root, Json::Value& response)    //notification
        {
            std::cout<<"Notification: "<<root<<std::endl;
            response = Json::Value::null;
            return true;
        }
        bool ReadF(const Json::Value& root, Json::Value& response)       //read file
        {
            std::cout<<"Receive query: "<< root << std::endl;       //query from client. json format, client has to be this format then send it to server.
            
            //respond to the query
            response["jsonrpc"] = "2.0";
            response["id"] = root["id"];


            char bufferparas[BUFSIZE];
            char actualpath[PATH_MAX+1];
            //size_t requestsize;

            memset(bufferparas,0, BUFSIZE);
            memset(actualpath,0, PATH_MAX+1);
            
            if(root.isMember("params")){
                if(root["params"].isMember("path")){
                    strncpy(bufferparas, root["params"]["path"].asCString(), BUFSIZE - 1);
                    //requestsize = strlen(root["params"]["path"].asCString());
                }
            }else{
                std::cout<<std::endl<< "invalid parameters: there is no path" << std::endl;
                return false;
            }


            printf("REQUEST: %s\n", bufferparas);
            fflush(stdout);

            
            //validity check
            if(realpath(bufferparas, actualpath) == NULL){   //realpath() can convert any relative path into absolute path which is stored into resolved.
                std::cout<< std::endl<<errno<< strerror(errno)<<std::endl;
                printf("ERROR(bad path): %s\n", bufferparas);
                //close(client_socket);
                return false;
            }

            //read file contents and send its contents to client
            FILE *fp = fopen(actualpath, "r");
            if(fp == NULL){
                printf("ERROR(open): %s\n", bufferparas);
                //close(client_socket);
                return false;  
            }

            long unsigned int bytes_read;
            //insecure.
            //a real program should limit the client to certain files.
            while((bytes_read = fread(bufferparas, 1, BUFSIZE, fp)) > 0){
                printf("sending %zu bytes\n", bytes_read);
                //write(client_socket, bufferparas, bytes_read);            //instead of write, I uses response[] to send back message.
                response["content"].append(bufferparas);
            }
            fclose(fp);
            //close(client_socket);
            
            fflush(stdout);

            return true;

        }
};
