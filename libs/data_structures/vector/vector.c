//
// Created by Admin on 19.02.2024.
//
#include "../../data_structures/vector/vector.h"


vector createVector(size_t n) {
    int *new_data = (int *) malloc(n * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {new_data, 0, n};
}


void shrinkToFit(vector *v) {
    if (v->size < v->capacity) {
        int *new_data = (int *) realloc(v->data, v->size * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "bad realloc");
            exit(1);
        }
        v->data = new_data;
        v->capacity = v->size;
    }
}


void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->capacity = newCapacity;
        return;
    }
    int *new_data = (int *) realloc(v->data, newCapacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "bad realloc");
        exit(1);
    }
    if (v->size > newCapacity) {
        v->size = newCapacity;
    }
    v->data = new_data;
    v->capacity = newCapacity;
}


void clear(vector *v) {
    v->size = 0;
}


void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}


bool isEmpty(vector *v) {
    return v->size == 0 ? 1 : 0;
}


bool isFull(vector *v) {
    return v->size == v->capacity ? 1 : 0;
}