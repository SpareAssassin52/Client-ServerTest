#include "include/common.h"

int main(int argc, char **argv){
    int server_socket, client_socket, addr_size;
    struct sockaddr_in server_addr, client_addr;
    

    /*pthread_t thread_pool[THREAD_POOL_SIZE];  //use a thread pool. C*/
    std::vector<std::thread> thread_pool;
    //                                                std::thread thread_pool[THREAD_POOL_SIZE];  //C++
    //first off create a bunch of threads to handle future connections.
    for(int i=0; i < THREAD_POOL_SIZE; i++){
        /*pthread_create(&thread_pool[i], NULL, thread_function, NULL);   //C  */
        //thread_pool[i] = std::thread(thread_functioncpp,nullptr);    //C++
        thread_pool.emplace_back(std::thread(thread_functioncpp));
    }
    /////////////////////////////////////////////////////////////////////////////////////////thread_pool.join();??

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

        inet_ntop(AF_INET, &client_addr, client_address, BUFSIZE);  //convert network address's format from network standard to presentation format.
        std::cout<<"Client's address is "<<client_address<<std::endl;

        //do what we do with connections.
        //handle_connection(client_socket);     //pass handle_connection into pthread_create and its argument client_socket.
        //pthread_t t;    //thread identifiers to track thread
        {       
        //mtx.lock(); //making sure that only one thread can access the queue at the same time, to prevent potentially data loss.
              //using {} to automatically lock because of scope-locking in unique_lock
        int *pclient = new int(client_socket);
        //*pclient = client_socket;     //simplify the syntax
        qclient_socket.push(pclient);   //put the connection elsewhere so that thread can find it.
        cv.notify_one();              //to wake up one of the waiting threads.
        //mtx.unlock();
        //pthread_create(&t, NULL, handle_connection, pclient); //use threads
        //handle_connection(pclient); //not use threads
        }
    } 
    

    return 0;
}