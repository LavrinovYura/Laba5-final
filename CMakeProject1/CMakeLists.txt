cmake_minimum_required(VERSION 3.6)

set(CMAKE_C_STANDARD 99)
add_library(myLib STATIC heap.c )
add_executable(HeapMain Main.c)
add_executable(HeapTest test.c)
TARGET_LINK_LIBRARIES(HeapMain myLib)
TARGET_LINK_LIBRARIES(HeapTest myLib)