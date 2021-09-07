//
// Created by chen on 2021/9/2.
//

#include "Vector.h"

struct vector {
    size_t size;   // 元素个数
    size_t capacity;   // 实际容量
    void **data;
};

/**
 * vector 扩容
 */
void __vector_grow(vector *vec, size_t min_capacity);

/**
 *  判断是否为 vector 的索引
 */
int __vector_index(vector *vec, size_t index);

vector *new_vector() {
    return new_vector_with_capacity(0);
}

vector *new_vector_with_capacity(int initialCapacity) {
    vector *vec = (vector*) malloc(sizeof(vector));
    vec->size = 0;
    vec->capacity = initialCapacity;
    if (initialCapacity > 0)
        vec->data = (void **) malloc(sizeof(void *) * initialCapacity);
    else if (initialCapacity == 0)
        vec->data = NULL;
    return vec;
}

size_t vector_size(vector *vec) {
    assert(vec);
    return vec->size;
}

int vector_empty(vector *vec) {
    return vector_size(vec) == 0;
}

void vector_insert(vector *vec, size_t index, void *item) {
    assert(index >= 0 && index <= vector_size(vec));

    if (vec->size == vec->capacity)
        __vector_grow(vec, vec->size + 1);

    for (size_t i = ++vec->size; i > index; i--)
        vec->data[i] = vec->data[i - 1];
    vec->data[index] = item;
}

void vector_push_back(vector *vec, void *item) {
    vector_insert(vec, vector_size(vec), item);
}

void vector_push_front(vector *vec, void *item) {
    vector_insert(vec, 0, item);
}

void *vector_get(vector *vec, size_t index) {
    if (__vector_index(vec, index)) {
        return vec->data[index];
    }
    return NULL;
}

void *vector_front(vector *vec) {
    return vector_get(vec, 0);
}

void *vector_back(vector *vec) {
    return vector_get(vec, vector_size(vec) - 1);
}

void *vector_remove(vector *vec, size_t index) {
    assert(__vector_index(vec, index));

    void *item = vec->data[index];
    for (size_t i = index; i < vec->size - 1; i++)
        vec->data[i] = vec->data[i + 1];
    vec->data[vec->size--] = NULL;
    return item;
}

void *vector_pop_front(vector *vec) {
    return vector_remove(vec, 0);
}

void *vector_pop_back(vector *vec) {
    return vector_remove(vec, vector_size(vec) - 1);
}

void vector_set(vector *vec, size_t index, void *item) {
    assert(__vector_index(vec, index));
    vec->data[index] = item;
}

int __vector_index(vector *vec, size_t index) {
    return index >= 0 && index < vector_size(vec);
}

void __vector_grow(vector *vec, size_t min_capacity) {
    size_t old_capacity = vec->capacity;
    size_t new_capacity = old_capacity + (old_capacity >> 1);
    if (new_capacity < min_capacity)
        new_capacity = min_capacity;

    void **new_data = (void *) malloc(sizeof(void *) * new_capacity);
    void **old_data = vec->data;
    vec->data = new_data;
    vec->capacity = new_capacity;
    if (old_data != NULL) {
        for (int i = 0; i < vec->size; i++)
            new_data[i] = old_data[i];
        free(old_data);
    }
}