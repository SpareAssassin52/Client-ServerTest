#include "include/common.h"

int main(int argc, char **argv){

    //std::vector<std::thread> thread_pool;
    
    /*for(int i=0; i < THREAD_POOL_SIZE; i++){
        thread_pool.emplace_back(std::thread(thread_functioncpp));
    }
    */
    

    int server_socket = setup_server(SERVER_PORT, SERVER_BACKLOG);

    fd_set current_sockets, ready_sockets;      //2 sets of file descriptor.
    
    //initialize my current set
    FD_ZERO(&current_sockets); FD_ZERO(&ready_sockets);
    FD_SET(server_socket,&current_sockets);     //add server_socket to the current FD_set.


    while (true)
    {   
        ready_sockets = current_sockets;        //select is destructive, operate sets that need to operate now.
        if(select(FD_SETSIZE, &ready_sockets, NULL, NULL, NULL) < 0){
            perror("select error");
            exit(EXIT_FAILURE);
        }

        for(int i=0; i < FD_SETSIZE; i++){
            if(FD_ISSET(i, &ready_sockets)){    //FD_ISSET() checks whether I is in the FD_set of ready_sockets.
                if (i == server_socket){        //means new connection selected by SELECT and it is readable.
                    int client_socket = accept_new_connection(server_socket);
                    FD_SET(client_socket, &current_sockets);        //add it into current_sockets for the next round SELECT.
                }
                else{       //i == client_socket; means that SELECT told us client_socket is readable and needs further process.
                    //sleep(500);
                    handle_connection(i);
                    printf("closing connection\n");
                    FD_CLR(i, &current_sockets);        //once client's request is over, just move its FD out of the current FD_SET.
                }
            }
        }    
    } 
    
    return 0;
}



/*
{"id":1,"jsonrpc":"2.0","method":"print","params":"a"}
{"id":1,"jsonrpc":"2.0","method":"readfile","params":{"path":"/home/zyd/Documents/tst.txt"}}
*/