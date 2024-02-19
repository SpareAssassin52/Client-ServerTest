#include "../include/common.h"

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
    while((bytes_read = read(client_socket, buffer+msgsize, sizeof(buffer)-msgsize-1)) > 0){
        msgsize += bytes_read;

        if(msgsize > BUFSIZE-1 || (buffer[msgsize-4]=='\r' && buffer[msgsize-3]=='\n' && buffer[msgsize-2]=='\r' && buffer[msgsize-1]=='\n'))
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
    printf("closing connection");

    return NULL;
}
