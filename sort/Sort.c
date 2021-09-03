//
// Created by chen on 2021/9/2.
//

#include "Sort.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * 快速排序中，三数中值分割
 * @param arr
 * @param left
 * @param right
 * @return pivot - 中枢值
 */
int media3(int *arr, int left, int right) {
    int mid = left + ((right - left) >> 1);

    if (arr[left] > arr[mid])
        swap(&arr[left], &arr[mid]);
    if (arr[left] > arr[right])
        swap(&arr[left], &arr[right]);
    if (arr[mid] > arr[right])
        swap(&arr[mid], &arr[right]);

    /* arr[left] <= arr[mid] <= arr[right] */
    swap(&arr[mid], &arr[right - 1]);
    return arr[right - 1]; /* return pivot */
}

void quickSort(ElementType *arr, int left, int right) {
    if (left >= right)
        return;
    if (left + 1 == right) {
        int a = arr[left] > arr[right] ? arr[left] : arr[right];
        int b = arr[left] > arr[right] ? arr[right] : arr[left];
        arr[left] = b; arr[right] = a;
        return;
    }

    int pivot = media3(arr, left, right);
    int i = left, j = right - 1;
    while (1) {
        while (arr[++i] < pivot) {};
        while (arr[--j] > pivot) {};
        if (i >= j)
            break;
        swap(&arr[i], &arr[j]);
    }
    /* restore pivot */
    swap(&arr[i], &arr[right - 1]);

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
