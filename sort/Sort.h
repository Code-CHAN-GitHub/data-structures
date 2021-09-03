//
// Created by chen on 2021/9/2.
//

#ifndef DATA_STRUCTURES_SORT_H
#define DATA_STRUCTURES_SORT_H

#include <stdio.h>
#include "../util/Arrays.h"

typedef int ElementType;

/**
 * 快速排序
 * @param arr
 * @param left
 * @param right
 */
void quickSort(ElementType *arr, int left, int right);

/**
 * 归并排序
 * @param arr
 * @param left
 * @param right
 */
void mergeSort(ElementType *arr, int left, int right);

#endif //DATA_STRUCTURES_SORT_H
