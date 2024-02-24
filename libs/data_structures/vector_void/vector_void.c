#include "../../data_structures/vector_void/vector_void.h"


vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *new_data = malloc(sizeof(baseTypeSize) * n);
    if (new_data == NULL) {
        fprintf(stderr, "bad realloc");
        exit(1);
    }
    return (vectorVoid) {new_data, 0, n, baseTypeSize};
}


void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
        return;
    }

    void *new_data = (void *) realloc(v->data, newCapacity * sizeof(v->baseTypeSize));

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


void shrinkToFitV(vectorVoid *v) {
    if (v->size < v->capacity) {
        void *new_data = (void *) realloc(v->data, v->size * sizeof(v->baseTypeSize));
        if (new_data == NULL) {
            fprintf(stderr, "bad realloc");
            exit(1);
        }
        v->data = new_data;
        v->capacity = v->size;
    }
}


void clearV(vectorVoid *v) {
    v->size = 0;
}


void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}


bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}


bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}


void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}


void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index > v->size - 1) {
        fprintf(stderr, "IndexError: a [%zu] is not exists", index);
        exit(1);
    }
    memcpy((void *) v->data + index * v->baseTypeSize, source, v->baseTypeSize);
}


void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }

    int a = 0;
    setVectorValueV(v,v->size-1,&a);
    v->size--;
}


void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v)) {
        if (v->capacity != 0)
            reserveV(v, v->capacity * 2);
        else
            reserveV(v, v->capacity + 1);
    }
    memcpy((void *) v->data + v->size * v->baseTypeSize, source, v->baseTypeSize);
    v->size++;
}

