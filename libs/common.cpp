#include "../include/common.h"
std::queue<int*> qclient_socket;
std::mutex mtx;
std::unique_lock<std::mutex> lk(mtx);
std::condition_variable cv;

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
    std::string hexits = "0123456789ABCDEF";

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

int check(int exp, const char *msg){
    if(exp == SOCKETERROR){
        perror(msg);
        exit(1);
    }
    return exp;
}

void *handle_connection(void *p_client_socket){
    int client_socket = *((int*) p_client_socket);
    free(p_client_socket);
    char buffer[BUFSIZE]; 
    size_t bytes_read;
    int msgsize = 0;
    char actualpath[PATH_MAX+1];

    //read the client's message -- the name of the file to read
    while((bytes_read = read(client_socket, buffer+msgsize, sizeof(buffer)+msgsize-1)) > 0){
        msgsize += bytes_read;
        if(msgsize < 0||msgsize > BUFSIZE-1 || (buffer[msgsize-4]=='\r' && buffer[msgsize-3]=='\n' && buffer[msgsize-2]=='\r' && buffer[msgsize-1]=='\n'))  //msgsize < 0 because byte_read can be really huge that it overflowed, which makes it become negative.
        break;  //buffer overflow or end of file.

    }
    check(bytes_read, "recv error");
    buffer[msgsize-1] = 0, buffer[msgsize-2] = 0, buffer[msgsize-3] = 0, buffer[msgsize-4] = 0;  //null terminate the message and remove the \n

    printf("REQUEST: %s\n", buffer);
    fflush(stdout);

    //validity check
    if(realpath(buffer, actualpath) == NULL){   //realpath() can convert any relative path into absolute path which is stored into resolved.
        printf("ERROR(bad path): %s\n", buffer);
        close(client_socket);
        return NULL;
    }

    //read file contents and send its contents to client
    FILE *fp = fopen(actualpath, "r");
    if(fp == NULL){
        printf("ERROR(open): %s\n", buffer);
        close(client_socket);
        return NULL;  
    }
    //sleep(1); //to demonstrate that thread is really helpful and can be relatively faster.
    //this is a fine example program, but rather insecure.
    //a real program should limit the client to certain files.
    while((bytes_read = fread(buffer, 1, BUFSIZE, fp)) > 0){
        printf("sending %zu bytes\n", bytes_read);
        write(client_socket, buffer, bytes_read);
    }
    close(client_socket);
    fclose(fp);
    printf("closing connection\n");
    fflush(stdout);

    return NULL;
}


void * thread_function(void* arg){      //C
    while(true){    //thread will keeping checking the queue, if we have connection from client then run handle_connection.
        mtx.lock();//using mutex to lock the global queue, making it can only be accessed by one thread.
        int *pclient= NULL;
        if(!qclient_socket.empty()){
            pclient = qclient_socket.front();
            qclient_socket.pop();
            if(pclient!=NULL){
                //we have a new connection!
                handle_connection(pclient);
            }
        }
        mtx.unlock();
    }

    return NULL;
}

void thread_functioncpp(void* arg){ //same as thread_function, its return type is void in order to let std::thread to create thread.
    while(true){    //thread will keeping checking the queue, if we have connection from client then run handle_connection.
        mtx.lock();//using mutex to lock the global queue, making it can only be accessed by one thread.
        cv.wait(lk, [] {return !qclient_socket.empty(); });     //in order to use a lambda function, I need to use unique_lock type. 
        int *pclient= NULL;                                     //because of the lambda expression in the .wait(), there is no need to add additional
        pclient = qclient_socket.front();                       //if() expression to check the queue is empty or not.
        qclient_socket.pop();
        if(pclient!=NULL){
            //we have a new connection!
            handle_connection(pclient);
        }
        mtx.unlock();
    }

    return;
}