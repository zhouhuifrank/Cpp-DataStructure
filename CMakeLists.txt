cmake_minimum_required(VERSION 3.24)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure main.cpp)

add_subdirectory(LinearList)
add_subdirectory(Stack)
add_subdirectory(Queue)
add_subdirectory(Tree)
add_subdirectory(Heap)
add_subdirectory(Hash)
add_subdirectory(Graph)
add_subdirectory(Others)
add_subdirectory(Sort)
add_subdirectory(DynamicProgramming)
