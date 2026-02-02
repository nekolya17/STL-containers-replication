cmake_minimum_required(VERSION 3.20)
project(stl_containers)

add_executable(main main.cpp)

set_target_properties(main PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_include_directories(main PRIVATE
    ./functions
    ./sequence
    ./associative
    ./adapters
    ./unordered_associative
)

#Libraries

add_library(associative_containers
INTERFACE
    ./sequence/array.h
)

add_library(algorithms
INTERFACE
    ./functions/container_algorithms.h
)


#Linking

target_link_libraries(main
PRIVATE 
    algorithms
    associative_containers
)