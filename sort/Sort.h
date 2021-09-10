//
// Created by chen on 2021/9/2.
//

#ifndef DATA_STRUCTURES_SORT_H
#define DATA_STRUCTURES_SORT_H

#include <stdio.h>
#include "../util/Arrays.h"
#include "../vector/Vector.h"
#include "../lang/Integer.h"

typedef int ElementType;

/**
 * 快速排序
 */
void quick_sort(void **base, size_t nitems, int (*compar)(void *, void *));

/**
 * 归并排序
 */
void merge_sort(void **base, size_t nitems, int(*compar)(void *, void *));

/**
 * 插入排序
 */
void insertion_sort(void **base, size_t nitems, int (*compar)(void *, void *));

/**
 * 希尔排序
 */
void shell_sort(void **base, size_t nitems, int (*compare)(void *, void *));

/*
 * 堆排序
 */
void heap_sort(void **base, size_t nitems, int (*compare)(void *, void *));
#endif //DATA_STRUCTURES_SORT_H
