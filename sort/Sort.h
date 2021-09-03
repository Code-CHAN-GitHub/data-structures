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
 */
void quickSort(ElementType *arr, int left, int right);

/**
 * 归并排序
 */
void mergeSort(ElementType *arr, int left, int right);

/**
 * 插入排序
 */
void insertionSort(ElementType *arr, int left, int right);

/**
 * 希尔排序
 */
void shellSort(ElementType *arr, int left, int right);

/*
 * 堆排序
 */
void heapSort(ElementType *arr, int n);
#endif //DATA_STRUCTURES_SORT_H
