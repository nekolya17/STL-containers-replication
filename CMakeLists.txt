cmake_minimum_required(VERSION 3.20)
project(stl_containers)

add_executable(main main.cpp)



add_library(associative_containers
INTERFACE
    ./sequence/array.h
)

target_link_libraries(main
PRIVATE 
    associative_containers
)