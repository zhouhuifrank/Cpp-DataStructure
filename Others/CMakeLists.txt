cmake_minimum_required(VERSION 3.24)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(Others main.cpp LRUCache.cpp)
include_directories(.)