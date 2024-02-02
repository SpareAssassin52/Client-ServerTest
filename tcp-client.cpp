
#include"include/common.h"

void err_n_die(const char *fmt, ...);


int main(int argc, char **argv){
    int     sockfd, n;
    int     sendbytes;
    struct  sockaddr_in  servaddr;
    char    sendline[MAXLINE];
    char    recvline[MAXLINE];

    if (argc != 2)  //usage check
        err_n_die("usage: %s <server address>", argv[0]);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)      //create a socket
        err_n_die("Error while creating the socket!");      //AF_INET means IPv4 internet protocals ,SOCK_STREAM means provides sequenced, reliable, two-way, connection-based byte streams. 0 means a protocal will be allocated automatically.

    bzero(&servaddr, sizeof(servaddr));     //Initiate the address by zeroing out it.
    
    servaddr.sin_family = AF_INET;          //specify servaddr by input server info into this structure.
    servaddr.sin_port = htons(SERVER_PORT); //host to network short: convert any byte order into stantard internet byte order.

    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)    //converts a text representation of an IP address to a binary equivalent
        err_n_die("inet_pton error for %s ", argv[1]);

    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) //try to connect the address
        err_n_die("connect failed");

    //connected, preparing the message.
    sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");    //write formatted data into sendline. \r\n\r\n means that it is the end of the message.

    //Send the request -- making sure you send it all
    //This code is a bit fragile, since it bails if only some of the bytes are sent.
    //normally, you would want to retry, unless the return value was -1.
    if(write(sockfd, sendline, strlen(sendline)) != strlen(sendline))   //write the formatted data into the socket file descriptor I created at the beginning.
        err_n_die("write error");

    while((n = read(sockfd, recvline, MAXLINE-1)) > 0){ //read received data from sockfd. socket is kind like a file.
        printf("%s", recvline);
        memset(recvline, 0, MAXLINE);   //make sure string is null terminated by using memset.
    }
    if(n<0)
        err_n_die("read error");

    exit(0);


    return 0;
}




void err_n_die(const char *fmt, ...){
    int errno_save;
    va_list ap; //a way for C functions to accept a variable number of arguments.

    //any system or library call can set errno, so we need to save it now.
    errno_save = errno;

    //print out the fmt+args to standard out.
    va_start(ap, fmt);  //a macro defined in the stdarg header file in the C Programming languages.
    vfprintf(stdout, fmt, ap);  //writes a formatted string to a specified output stream.
    fprintf(stdout, "\n"); 
    fflush(stdout); //causes the system to empty the buffer that is associated with the specified output stream, if possible.

    //print out error message is errno was set.
    if (errno_save != 0){
        fprintf(stdout, "(errno = %d) : %s\n", errno_save, strerror(errno_save));
        fprintf(stdout,"\n");
        fflush(stdout);
    }
    va_end(ap); //performs cleanup for an ap object initialized by a call to va_start or va_copy.

    //this is the .. and_die part. Terminate with an error.
    exit(1);
    return;
}


char *bin2hex(const unsigned char *input, size_t len){
    char *result;
    char *hexits = "013456789ABCDEF";

    if(input == NULL || len <=0)
        return NULL;
    //(2 hexits+space)/chr + NULL
    int resultlength = (len*3) + 1;

    result = (char*)malloc(resultlength);
    bzero(result, resultlength);

    for (int i=0; i<len; i++){
        result[i*3] = hexits[input[i] >> 4];
        result[(i*3)+1] = hexits[input[i] & 0x0F];
        result[(i*3)+2] = ' ';  //for readability 
    }

    return result;
}
