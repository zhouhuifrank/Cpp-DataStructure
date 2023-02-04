cmake_minimum_required(VERSION 3.24)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sort main.cpp mergeSort.cpp quickSort.cpp)
include_directories(.)