//
// Created by chen on 2021/9/2.
//

#include "Vector.h"

struct Vector {
    int size;   // 元素个数
    int capacity;   // 实际容量
    void **data;
};

Vector *createVector() {
    return createVectorByInitCapacity(0);
}

Vector *createVectorByInitCapacity(int initialCapacity) {
    Vector *vec = (Vector*) malloc(sizeof(Vector));
    vec->size = 0;
    vec->capacity = initialCapacity;
    if (initialCapacity > 0)
        vec->data = (void **) malloc(sizeof(void *) * initialCapacity);
    else if (initialCapacity == 0)
        vec->data = NULL;
    return vec;
}

int vectorSize(Vector *vec) {
    return vec->size;
}

void vectorGrow(Vector *vec, int minCapacity) {
    int oldCapacity = vec->capacity;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity < minCapacity)
        newCapacity = minCapacity;
    void **newData = (void *) malloc(sizeof(void *) * newCapacity);
    void **oldData = vec->data;
//    arrayCopy(oldData, 0, newData, 0, vec->size);
    for (int i = 0; i < vec->size; i++)
        newData[i] = oldData[i];
    vec->data = newData;
    vec->capacity = newCapacity;
    if (vec->size != 0)
        free(oldData);
}

void vectorAdd(Vector *vec, void *item) {
    if (vec->size == vec->capacity)
        vectorGrow(vec, vec->size + 1);
    vec->data[vec->size++] = item;
}

void vectorAddByIndex(Vector *vec, int index, void *item) {
    if (index < 0 || index > vec->size) {
        printf("下标越界\n");
        return;
    }
    if (vec->size == vec->capacity)
        vectorGrow(vec, vec->size + 1);
//    arrayCopy(vec->data, index, vec->data, index + 1, vec->size - index);
    for (int i = ++vec->size; i > index; i--)
        vec->data[i] = vec->data[i - 1];
    vec->data[index] = item;
}

void *vectorGet(Vector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        printf("下标越界\n");
        return NULL;
    }
    return vec->data[index];
}

void *vectorRemove(Vector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        printf("下标越界\n");
        return -1;
    }
    void *item = vec->data[index];
    int numMoved = vec->size - index - 1;
    if (numMoved > 0)
//        arrayCopy(vec->data, index + 1, vec->data, index, numMoved);
        for (int i = index; i < vec->size - 1; i++)
            vec->data[i] = vec->data[i + 1];
    vec->size--;
    return item;
}

void vectorSet(Vector *vec, int index, void *item) {
    if (index < 0 || index >= vec->size) {
        printf("下标越界\n");
        return;
    }
    vec->data[index] = item;
}

//ElementType* vectorToArray(Vector vec) {
//    if (vec->size == 0)
//        return EMPTY_ELEMENT_DATA;
//    ElementType *arr = (ElementType *) malloc(sizeof(ElementType) * vec->size);
//    arrayCopy(vec->data, 0, arr, 0, vec->size);
//    return arr;
//}

//void printVector(Vector *vec) {
//    printf("[");
//    for (int i = 0; i < vec->size - 1; i++) {
//        printf("%d, ", vec->data[i]);
//    }
//    if (vec->size != 0)
//        printf("%d", vec->data[vec->size - 1]);
//    printf("]\n");
//}