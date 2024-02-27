#include "../../data_structures/vector_test/vector_test.h"
#include "assert.h"


void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
}


void test_pushBack_fullVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    pushBack(&v, 5);
    assert(v.size == 2);
    assert(v.capacity == 2);
}


void test_popBack_notEmptyVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}


void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 4);
    pushBack(&v, 7);
    assert(atVector(&v, 0) == &v.data[0]);
}


void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 4);
    pushBack(&v, 7);
    assert(atVector(&v, v.size - 1) == &v.data[v.size - 1]);
}


void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 2);
    assert(back(&v) == &v.data[v.size - 1]);
}


void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 2);
    assert(front(&v) == &v.data[0]);
}


void test(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}