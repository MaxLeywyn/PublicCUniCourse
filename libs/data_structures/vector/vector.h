#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;


vector createVector(size_t n);

void shrinkToFit(vector *v);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void deleteVector(vector *v);

bool isEmpty(vector *v);

bool isFull(vector *v);


#endif //TEST_VECTOR_H
