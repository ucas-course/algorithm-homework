cmake_minimum_required(VERSION 3.6)
project(workspace)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES multiplication.c multiplication.h main.c matrix-multi.c matrix-multi.h inversion-number.c inversion-number.h kthLargest.c kthLargest.h tree-local-min.c tree-local-min.h)
add_executable(workspace ${SOURCE_FILES})