//
// Created by chen on 2021/9/3.
//

#include "Heap.h"

struct HeapStruct {
    int size;
    int capacity;
    int *data;
};

int EMPTY_DATA[];

Heap createHeap() {
    Heap heap = (Heap) malloc(sizeof(struct HeapStruct));
    heap->size = heap->capacity = 0;
    heap->data = EMPTY_DATA;
    return heap;
}

void heapGrow(Heap heap, int minCapacity) {
    int oldCapacity = heap->capacity;
    int newCapacity = oldCapacity + ((oldCapacity < 64) ?
                                     (oldCapacity + 2) :
                                     (oldCapacity >> 1));
    if (newCapacity < minCapacity)
        newCapacity = minCapacity;
    int *oldData = heap->data;
    int *newData = (int *) malloc(sizeof(int ) * newCapacity);
    arrayCopy(oldData, 1, newData, 1, oldCapacity);
    heap->capacity = newCapacity;
    heap->data = newData;
    if (heap->size != 0)
        free(oldData);
}

void heapAdd(Heap heap, int val) {
    if (heap->size == heap->capacity)
        heapGrow(heap, heap->capacity + 2);

    int i;
    for (i = ++heap->size; i > 1 && heap->data[i / 2] > val; i /= 2)
        heap->data[i] = heap->data[i / 2];
    heap->data[i] = val;
}

int heapPeek(Heap heap) {
    if (heap->size == 0) {
        printf("堆为空!\n");
        return -1;
    }
    return heap->data[1];
}

void printHeap(Heap heap) {
    printf("[");
    for (int i = 1; i < heap->size; i++)
        printf("%d, ", heap->data[i]);
    if (heap->size > 0)
        printf("%d", heap->data[heap->size]);
    printf("]\n");
}