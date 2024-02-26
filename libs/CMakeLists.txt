cmake_minimum_required(VERSION 3.28.1)
project(libs)

include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(${PROJECT_NAME} SHARED 
common.cpp
system.cpp
netstring.cpp
networking.cpp
jsonrpc_client.cpp
jsonrpc_handler.cpp
jsonrpc_httpclient.cpp
jsonrpc_server.cpp
jsonrpc_tcpclient.cpp
jsonrpc_tcpserver.cpp
jsonrpc_udpclient.cpp
jsonrpc_udpserver.cpp
)
set(THREADS_PREFER_PTHREAD_FLAG ON) #set thread flag on
find_package(Threads REQUIRED)      #find threads package
target_link_libraries(${PROJECT_NAME} Threads::Threads)  #add pthread.h to the library

find_package(jsoncpp REQUIRED)
target_link_libraries(${PROJECT_NAME} jsoncpp)

#[==[ remember to use "make" after using "cmake -S .. -B." ]==]