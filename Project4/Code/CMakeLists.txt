cmake_minimum_required(VERSION 3.17)
project(untitled4 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled4 main.c Database.c Database.h Tuple.c Tuple.h Query.c Query.h Algebra.h Algebra.c)