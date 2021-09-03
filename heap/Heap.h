/**
 * 堆
 */

#ifndef DATA_STRUCTURES_HEAP_H
#define DATA_STRUCTURES_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../util/Arrays.h"

struct HeapStruct;
typedef struct HeapStruct *Heap;

/**
 * 返回一个空的堆
 * @return
 */
Heap createHeap();

/**
 * 将元素压入堆中
 */
void heapAdd(Heap heap, int val);

void printHeap(Heap heap);

#endif //DATA_STRUCTURES_HEAP_H
