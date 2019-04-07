cmake_minimum_required(VERSION 3.7)
project(C_Implementation)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/local/include)

set(SOURCE_FILES main.c demo.h)

add_executable(C_Implementation ${SOURCE_FILES})