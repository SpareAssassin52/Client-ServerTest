cmake_minimum_required(VERSION 3.28.1)
set(CMAKE_BUILD_TYPE Debug)
project(example)

add_executable(tcpclient tcp-client.cpp)
add_executable(tcpserver tcp-server.cpp)
add_executable(tcpMultiserver tcpMulti-server.cpp libs/common.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include/)

target_link_directories(tcpclient PRIVATE libs/build/)
target_link_directories(tcpserver PRIVATE libs/build/)
target_link_directories(tcpMultiserver PRIVATE libs/build/)

target_link_libraries(tcpclient libs)
target_link_libraries(tcpserver libs)
target_link_libraries(tcpMultiserver libs)

set(THREADS_PREFER_PTHREAD_FLAG ON) #set thread flag on
find_package(Threads REQUIRED)      #find threads package
target_link_libraries(tcpMultiserver Threads::Threads)  #add pthread.h to the library

find_package(jsoncpp REQUIRED)
target_link_libraries(tcpMultiserver jsoncpp)

