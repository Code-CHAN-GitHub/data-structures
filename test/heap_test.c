//
// Created by chen on 2021/9/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../heap/Heap.h"

int __int_compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int*)b);
}

void __test_new_heap() {
    heap *heap = new_heap(__int_compare);
    if (heap)
        printf("heap address ==> %p", heap);
}

void __test_heap_operator() {
    heap *heap = new_heap(__int_compare);
    int **a;
    a = malloc(sizeof(int *) * 10);
    srand((unsigned ) time(NULL));
    for (int i = 0; i < 10; i++) {
        a[i] = (int *) malloc(sizeof(int));
        *a[i] = rand() % 100;
    }
    printf("arr ==> ");
    for (int i = 0; i < 10; i++)
        printf("%d ", *a[i]);
    printf("\n");

    printf("*************************\n");
    for (int i = 0; i < 10; i++) {
        heap_push(heap, a[i]);
        printf("push ==> %d top ==> %d\n", *a[i], *(int *) heap_top(heap));
    }

    printf("*************************\n");
    while (heap_size(heap) > 1) {
        printf("pop ==> %d top ==> %d\n",*(int *) heap_pop(heap), *(int *) heap_top(heap));
    }
    printf("pop ==> %d\n", *(int *) heap_pop(heap));
}

int main() {
//    __test_new_heap();
    __test_heap_operator();
}