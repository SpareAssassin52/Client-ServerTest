cmake_minimum_required(VERSION 3.28.1)
project(libs)

include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(${PROJECT_NAME} SHARED common.cpp)


#[==[ remember to use "make" after using "cmake -S .. -B." ]==]