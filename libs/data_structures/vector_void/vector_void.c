#include "../../data_structures/vector_void/vector_void.h"



vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    void* new_data = malloc(sizeof(baseTypeSize)*n);
    if (new_data == NULL) {
        fprintf(stderr, "bad realloc");
        exit(1);
    }
    return (vectorVoid){new_data,0,n,baseTypeSize};
}


void reserveV(vectorVoid *v, size_t newCapacity){
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


void shrinkToFitV(vectorVoid *v){
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


void clearV(vectorVoid *v){
    v->size = 0;
}


void deleteVectorV(vectorVoid *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize=0;
}





