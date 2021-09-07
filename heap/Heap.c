//
// Created by chen on 2021/9/3.
//

#include "Heap.h"

struct heap {
    size_t size;
    size_t capacity;
    void **data;
    int (*compare)(const void*, const void*);
};

heap *new_heap(int (*compare)(const void*, const void*)) {
    heap *heap = malloc(sizeof(struct heap));
    heap->size = heap->capacity = 0;
    heap->data = NULL;
    heap->compare = compare;
    return heap;
}

int heap_empty(heap *heap) {
    assert(heap);
    return heap->size == 0;
}

size_t heap_size(heap *heap) {
    assert(heap);
    return heap->size;
}

void __heap_grow(heap *heap, size_t minCapacity) {
    size_t old_capacity = heap->capacity;
    size_t new_capacity = old_capacity + ((old_capacity < 64) ?
                                     (old_capacity + 2) :
                                     (old_capacity >> 1));
    if (new_capacity < minCapacity)
        new_capacity = minCapacity;
    void **old_data = heap->data;
    void **new_data = (void **)malloc(sizeof(void *) * (new_capacity + 1));

    heap->capacity = new_capacity;
    heap->data = new_data;
    if (heap->size > 0) {
        for (size_t i = 1; i <= old_capacity; i++)
            new_data[i] = old_data[i];
        free(old_data);
    }
}

void heap_push(heap *heap, void *val) {
    assert(heap);
    if (heap->size == heap->capacity) {
        __heap_grow(heap, heap->capacity + 2);
    }

    size_t i;
    for (i = ++heap->size; i > 1 && heap->data[i / 2] && heap->compare(heap->data[i / 2], val) > 0; i /= 2)
        heap->data[i] = heap->data[i / 2];
    heap->data[i] = val;
}

void *heap_top(heap *heap) {
    if (!heap_empty(heap))
        return heap->data[1];
    return NULL;
}

void *heap_pop(heap *heap) {
    if (!heap_empty(heap)) {
        void *min = heap->data[1];
        void *last = heap->data[heap->size--];
        size_t i, child;
        for (i = 1; i * 2 <= heap->size; i = child) {
            child = i * 2;
            if (child < heap->size &&
                    heap->data[child + 1] &&
                    heap->compare(heap->data[child + 1], heap->data[child]) < 0)
                child++;
            if (heap->compare(last, heap->data[child]) > 0)
                heap->data[i] = heap->data[child];
            else
                break;
        }
        heap->data[i] = last;
        return min;
    }
    return NULL;
}