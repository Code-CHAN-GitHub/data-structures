//
// Created by chen on 2021/9/2.
//

#include "Vector.h"

struct VectorStruct {
    int size;   // 元素个数
    int capacity;   // 实际容量
    ElementType *data;
};

ElementType EMPTY_ELEMENT_DATA[];

Vector createVector() {
    return createVectorByInitCapacity(0);
}

Vector createVectorByInitCapacity(int initialCapacity) {
    Vector vec = (Vector) malloc(sizeof(struct VectorStruct));
    vec->size = 0;
    vec->capacity = initialCapacity;
    if (initialCapacity > 0)
        vec->data = (ElementType *) malloc(sizeof(ElementType) * initialCapacity);
    else if (initialCapacity == 0)
        vec->data = EMPTY_ELEMENT_DATA;
    else {
        printf("初始化容量不能小于0!\n");
        free(vec);
        return NULL;
    }
    return vec;
}

void arrayCopy(ElementType *src, int srcPos, ElementType *dest, int destPos, int length) {
    if (src != dest) {
        for (int i = 0; i < length; i++)
            dest[destPos + i] = src[srcPos + i];
    } else {
        int tmp[length];
        for (int i = 0; i < length; i++)
            tmp[i] = src[srcPos + i];
        for (int i = 0; i < length; i++)
            dest[destPos + i] = tmp[i];
    }
}

void grow(Vector vec, int minCapacity) {
    int oldCapacity = vec->capacity;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity < minCapacity)
        newCapacity = minCapacity;
    ElementType *newData = (ElementType *) malloc(sizeof(ElementType) * newCapacity);
    ElementType *oldData = vec->data;
    arrayCopy(oldData, 0, newData, 0, vec->size);
    vec->data = newData;
    vec->capacity = newCapacity;
    if (vec->size != 0)
        free(oldData);
}

void vectorAdd(Vector vec, ElementType val) {
    if (vec->size == vec->capacity)
        grow(vec, vec->size + 1);
    vec->data[vec->size++] = val;
}

void vectorAddByIndex(Vector vec, ElementType val, int index) {
    if (index < 0 || index > vec->size) {
        printf("下标越界\n");
        return;
    }
    if (vec->size == vec->capacity)
        grow(vec, vec->size + 1);
    arrayCopy(vec->data, index, vec->data, index + 1, vec->size - index);
    vec->data[index] = val;
    vec->size++;
}

void printVector(Vector vec) {
    printf("[");
    for (int i = 0; i < vec->size - 1; i++) {
        printf("%d, ", vec->data[i]);
    }
    if (vec->size != 0)
        printf("%d", vec->data[vec->size - 1]);
    printf("]\n");
}