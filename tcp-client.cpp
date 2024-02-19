#include"include/common.h"
#include<iostream>



int main(int argc, char **argv){
    int     sockfd, n;
    int     sendbytes;
    struct  sockaddr_in  servaddr;
    char    sendline[BUFSIZE];
    char    recvline[BUFSIZE];

    if (argc != 3)  //usage check
        err_n_die("usage: %s <server address> <filepath>", argv[0]);    

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)      //create a socket
        err_n_die("Error while creating the socket!");      //AF_INET means IPv4 internet protocals ,SOCK_STREAM means provides sequenced, reliable, two-way, connection-based byte streams. 0 means a protocal will be allocated automatically.

    bzero(&servaddr, sizeof(servaddr));     //Initiate the address by zeroing out it.
    
    servaddr.sin_family = AF_INET;          //specify servaddr by input server info into this structure.
    servaddr.sin_port = htons(SERVER_PORT); //host to network short: convert any byte order into stantard internet byte order.

    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)    //converts a text representation of an IP address to a binary equivalent
        err_n_die("inet_pton error for %s ", argv[1]);

// to track down the time client spend to recieve target file.
    long before = clock();
    
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) //try to connect the address
        err_n_die("connect failed");

    //connected, preparing the message.
    //sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");    //write formatted data into sendline. \r\n\r\n means that it is the end of the message.
    
    sprintf(sendline, "%s\r\n\r\n",argv[2]);

    
    //Send the request -- making sure you send it all
    //This code is a bit fragile, since it bails if only some of the bytes are sent.
    //normally, you would want to retry, unless the return value was -1.
    if(write(sockfd, sendline, strlen(sendline)) != strlen(sendline))   //write the formatted data into the socket file descriptor I created at the beginning.
        err_n_die("write error");

    while((n = read(sockfd, recvline, BUFSIZE-1)) > 0){ //read received data from sockfd. socket is kind like a file.
        //printf("%s", recvline);
        memset(recvline, 0, BUFSIZE);   //make sure string is null terminated by using memset.
    }
    if(n<0)
        err_n_die("read error");

    // to track down the time client spend to recieve target file.
    long after = clock();
    double elapsed = (double) (after-before)/CLOCKS_PER_SEC;
    std::cout<<std::fixed<<std::endl<<elapsed<<" seconds elapsed"<<std::endl;
    exit(0);

    return 0;
}
