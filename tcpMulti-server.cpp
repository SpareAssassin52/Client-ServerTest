#include "include/common.h"

int main(int argc, char **argv){
    
    /*pthread_t thread_pool[THREAD_POOL_SIZE];  //use a thread pool. C*/
    std::vector<std::thread> thread_pool;
    //                                                std::thread thread_pool[THREAD_POOL_SIZE];  //C++
    //first off create a bunch of threads to handle future connections.
    for(int i=0; i < THREAD_POOL_SIZE; i++){
        /*pthread_create(&thread_pool[i], NULL, thread_function, NULL);   //C  */
        //thread_pool[i] = std::thread(thread_functioncpp,nullptr);    //C++
        thread_pool.emplace_back(std::thread(thread_functioncpp));
        //thread_pool[i].join();      //join() means the main() thread will wait til the thread_pool[i] finishes.
    }

    int server_socket = setup_server(SERVER_PORT, SERVER_BACKLOG);

    while (true)
    {   
        int client_socket = accept_new_connection(server_socket);

        //do what we do with connections.
        //handle_connection(client_socket);     //pass handle_connection into pthread_create and its argument client_socket.
        //pthread_t t;    //thread identifiers to track thread
        {       
        std::unique_lock<std::mutex> lk(mtx);
        //mtx.lock(); //making sure that only one thread can access the queue at the same time, to prevent potentially data loss.
              //using {} to automatically lock because of scope-locking in unique_lock
        int *pclient = new int(client_socket);
        //*pclient = client_socket;     //simplify the syntax
        qclient_socket.push(pclient);   //put the connection elsewhere so that thread can find it.
        cv.notify_one();                //to wake up one of the waiting threads.
        //mtx.unlock();
        //pthread_create(&t, NULL, handle_connection, pclient); //use threads
        //handle_connection(pclient); //not use threads
        }
    } 
    

    return 0;
}