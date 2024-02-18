#include "include/common.h"
#include<iostream>

int main(int argc, char **argv){
    int server_socket, client_socket, addr_size;
    struct sockaddr_in server_addr, client_addr;

    check((server_socket = socket(AF_INET, SOCK_STREAM , 0)), "Failed to create socket");

    //initialize the address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);  //htons means host to network standard format

    check(bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)), "Bind Failed!");

    check(listen(server_socket, SERVER_BACKLOG), "Listen Failed");

    while (true)
    {   char client_address[BUFSIZE+1];

        printf("waiting for connection...\n");
        //wait for, and eventually accept an incoming connection.
        addr_size=sizeof(struct sockaddr_in);
        check(client_socket = 
        accept(server_socket, (sockaddr*)&client_addr, (socklen_t*) &addr_size),
        "accept failed");
        printf("Connected!\n");

        inet_ntop(AF_INET, &client_addr, client_address, BUFSIZE);
        std::cout<<"Client's address is "<<client_address<<std::endl;

        //do what we do with connections.
        handle_connection(client_socket);

    }
    

    return 0;
}