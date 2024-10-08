#include "include/common.h"
#include <string.h>
#include <iostream>

int main(int argc, char **argv){
    int     listenfd, connfd, n;
    struct sockaddr_in  servaddr;   //struct sockaddr for IPv4
    uint8_t     buff[BUFSIZE+1];
    uint8_t     recvline[BUFSIZE+1];

    //create a socket to listenfd
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_n_die("socket error");

    //set up the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   //htonl(): converts the unsined integer hostlong from host byte order to network byte order. meanings the server will respond to anything.
    servaddr.sin_port   = htons(SERVER_PORT);       //htons(): converts the unsigned short integer hostshort from host byte order to network byte order.

    //bind & listen
    if((bind(listenfd, (struct sockaddr *) &servaddr,sizeof(servaddr))) < 0)    //binds a unique local name to the socket with descriptor with descriptor socket.
        err_n_die("bind error");

    if((listen(listenfd, 10)) < 0)  //steam sockets only. indicates a readiness to accept client connection requests, and creates a connection request queue of length backlog to queue incoming connection requests.
        err_n_die("listen error");
    
    while(true){
        struct sockaddr_in* addr;        //to store the client's structure.
        socklen_t addr_len;             
        char client_address[BUFSIZE+1];//to get decimal format of the client address.

        //accept blocks until an incoming connection arrives
        //it returns a "file descriptor" to the connection
        printf("waiting for a connection on port %d\n", SERVER_PORT);
        fflush(stdout);
        connfd = accept(listenfd, (struct sockaddr*) &addr, (socklen_t*) &addr_len);  //new socket that we actually talk to other clients, meanwhile, store the client's info into struct sockaddr.
        
        inet_ntop(AF_INET, &addr, client_address, BUFSIZE); //take an address in network format and convert into presentation format.
        std::cout<<"Client address is "<<client_address<<std::endl;


        //zero out the receive buffer to make sure it ends up null terminated
        memset(recvline, 0, BUFSIZE); 
        //now read the client's message.
        while((n = read(connfd, recvline, BUFSIZE-1)) > 0){
            fprintf(stdout, "\n%s\n\n%s", bin2hex(recvline, n), recvline);  //print out the data: transform it form binary into hexadeciaml, and print out the original data.

            //hacky way to detact the end of the message.
            if(recvline[n-4] == '\r' && recvline[n-3] == '\n'&&recvline[n-2] == '\r' && recvline[n-1] == '\n') break;   //HTTP requests end with \r\n\r\n
            memset(recvline, 0, BUFSIZE);
        }
        if(n < 0)   //the length of data can't below 0.
            err_n_die("read error");

        snprintf((char*)buff, sizeof(buff), "HTTP/1.0 200 OK\r\n\r\nHello"); //write data into buffer.

        //normally, I may want to check the results from write and close.
        //in case errors occur.
        write(connfd, (char*)buff, strlen((char*)buff));
        close(connfd);
    }
    return 0;
}