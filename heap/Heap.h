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
 */
Heap createHeap();

/**
 * 判断堆是否为空
 */
int heapIsEmpty(Heap heap);

/**
 * 将元素压入堆中
 */
void heapAdd(Heap heap, int val);

/**
 * 获取堆顶的元素，并不删除
 */
int heapPeek(Heap heap);

/**
 * 弹出堆顶元素
 */
int heapPoll(Heap heap);

void printHeap(Heap heap);

#endif //DATA_STRUCTURES_HEAP_H
