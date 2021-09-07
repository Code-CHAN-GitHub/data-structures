/**
 * 堆
 */

#ifndef DATA_STRUCTURES_heap_H
#define DATA_STRUCTURES_heap_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct heap heap;

/**
 * 返回一个空的堆
 */
heap *new_heap(int (*compare)(const void*, const void*));

/**
 * 判断堆是否为空
 */
int heap_empty(heap *heap);

size_t heap_size(heap *heap);

/**
 * 将元素压入堆中
 */
void heap_push(heap *heap, void *val);

/**
 * 获取堆顶的元素，并不删除
 */
void *heap_top(heap *heap);

/**
 * 弹出堆顶元素
 */
void *heap_pop(heap *heap);

#endif //DATA_STRUCTURES_heap_H
