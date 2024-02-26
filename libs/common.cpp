#include "../include/common.h"

std::queue<int*> qclient_socket;
std::mutex mtx;
std::condition_variable cv;

Json::Rpc::Handler m_jsonHandler;
zyd classzyd;

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
    //exit(1);
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

int setup_server(short port, int backlog){
    //add method
    m_jsonHandler.AddMethod(new Json::Rpc::RpcMethod<zyd>(classzyd, &zyd::Print, std::string("print")));
    m_jsonHandler.AddMethod(new Json::Rpc::RpcMethod<zyd>(classzyd, &zyd::Notify, std::string("notify")));
    m_jsonHandler.AddMethod(new Json::Rpc::RpcMethod<zyd>(classzyd, &zyd::ReadF, std::string("readfile")));
    //~add method

    int server_socket, client_socket, addr_size;
    struct sockaddr_in server_addr;  //, client_addr;

    check((server_socket = socket(AF_INET, SOCK_STREAM , 0)), "Failed to create socket");

    //set the socket into non-blocking mode using file control(fcntl).
    fcntl(server_socket, F_SETFL, fcntl(server_socket, F_GETFL) | O_NONBLOCK);

    //initialize the address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);  //htons means host to network standard format

    check(bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)), "Bind Failed!");

    check(listen(server_socket, backlog), "Listen Failed");
    printf("waiting for connection...\n");
    //wait for, and eventually accept an incoming connection.

    return server_socket;
}

int accept_new_connection(int server_socket){
    int client_socket;
    sockaddr_in client_addr;
    int addr_size;
    char client_address[BUFSIZE+1];

    addr_size=sizeof(struct sockaddr_in);
    check(client_socket = 
            accept(server_socket, (sockaddr*)&client_addr, (socklen_t*) &addr_size),
            "accept failed");

    printf("Connected!\n");

    inet_ntop(AF_INET, &client_addr, client_address, BUFSIZE);  //convert network address's format from network standard to presentation format.
    std::cout<<"Client's address is "<<client_address<<std::endl;

    return client_socket;
}

int check(int exp, const char *msg){
    if(exp == SOCKETERROR){
        perror(msg);
        exit(1);
    }
    return exp;
}

void *handle_connection(int client_socket){
    //int client_socket = *((int*) p_client_socket);
    //free(p_client_socket);
    char buffer[BUFSIZE]; 
    size_t bytes_read;
    int msgsize = 0;
    

    Json::Value response;
    ssize_t numb = -1;      //number of received data;

    numb = recv(client_socket, buffer, BUFSIZE, 0);
    if(numb > 0){
        std::string msg = std::string(buffer, numb);        //convert char[] into string.

        if(Json::Rpc::RAW==Json::Rpc::NETSTRING)        //format of code? 
        {
            try{
            msg = netstring::decode(msg);       
            }
            catch(const netstring::NetstringException &e){
                std::cerr<< e.what() << std::endl;
                return NULL;
            }
        }

        m_jsonHandler.Process(msg, response);           //processing and then parsing the result into jsonRPC format

        //start encoding the response then send it back to client.
        //in case of notification message received, the response could be Json::Value::null
        if(response != Json::Value::null){
            std::string rep = m_jsonHandler.GetString(response);
            if(Json::Rpc::RAW==Json::Rpc::NETSTRING){
                rep=netstring::encode(rep); 
            }

            size_t bytesTOSend = rep.length();
            const char* ptrBuffer = rep.c_str();        //?
            do{
                int retVal = send(client_socket, ptrBuffer, bytesTOSend, 0);
                if(retVal == -1)
                {       //error
                    std::cerr << "Error while sending data: "<< strerror(errno) << std::endl;
                    return NULL;
                }
                bytesTOSend -= retVal;
                ptrBuffer += retVal;
            }while(bytesTOSend > 0);

        }


    }


    /*      move to the class zyd as a method in jsonrpc.
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

    //this is a fine example program, but rather insecure.
    //a real program should limit the client to certain files.
    while((bytes_read = fread(buffer, 1, BUFSIZE, fp)) > 0){
        printf("sending %zu bytes\n", bytes_read);
        write(client_socket, buffer, bytes_read);
    }
    fclose(fp);
    close(client_socket);
    printf("closing connection\n");
    fflush(stdout);*/

    return NULL;
}


/*void * thread_function(void* arg){      //C
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
}*/

void thread_functioncpp(){ //same as thread_function, its return type is void in order to let std::thread to create thread.
    while(true){    //thread will keeping checking the queue, if we have connection from client then run handle_connection.
        //mtx.lock();//using mutex to lock the global queue, making it can only be accessed by one thread.
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [] {return !qclient_socket.empty(); });     //in order to use a lambda function, I need to use unique_lock type. 
        int *pclient= NULL;                                     //because of the lambda expression in the .wait(), there is no need to add additional
        pclient = qclient_socket.front();                       //if() expression to check the queue is empty or not.
        qclient_socket.pop();
        if(pclient!=NULL){
            //we have a new connection!
            handle_connection(*pclient);
        }
        //mtx.unlock();
    }

    return;
}