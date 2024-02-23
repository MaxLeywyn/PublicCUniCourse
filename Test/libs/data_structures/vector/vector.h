#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include <stdio.h>









typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;



#endif //TEST_VECTOR_H
