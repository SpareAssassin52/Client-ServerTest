cmake_minimum_required(VERSION 3.28.1)

project(example)

add_executable(tcpclient tcp-client.cpp)
add_executable(tcpserver tcp-server.cpp)
add_executable(tcpMultiserver tcpMulti-server.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include/)

target_link_directories(tcpclient PRIVATE libs/build/)
target_link_directories(tcpserver PRIVATE libs/build/)
target_link_directories(tcpMultiserver PRIVATE libs/build/)

target_link_libraries(tcpclient libs)
target_link_libraries(tcpserver libs)
target_link_libraries(tcpMultiserver libs)