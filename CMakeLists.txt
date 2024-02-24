cmake_minimum_required(VERSION 3.26)
project(Test C)

set(CMAKE_C_STANDARD 11)

add_executable(Test main.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/vector.c
        libs/data_structures/vector_test/vector_test.c
        libs/data_structures/vector_test/vector_test.h
        libs/data_structures/vector_void/vector_void.c
        libs/data_structures/vector_void/vector_void.h)
