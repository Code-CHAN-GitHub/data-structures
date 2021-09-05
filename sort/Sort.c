//
// Created by chen on 2021/9/2.
//

#include "Sort.h"

void swap(void **arr, size_t i, size_t j) {
    void *tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void *media3(void **arr, size_t left, size_t right, int (*compare)(void *, void *)) {
    size_t mid = left + ((right - left) >> 1);

    if (compare(arr[left], arr[mid]) > 0)
        swap(arr, left, mid);
    if (compare(arr[left], arr[right]) > 0)
        swap(arr, left, right);
    if (compare(arr[mid], arr[right]) > 0)
        swap(arr, mid, right);

    /* arr[left] <= arr[mid] <= arr[right] */
    swap(arr, mid, right - 1);
    return arr[right - 1]; /* return pivot */
}

#define CUTOFF (8) /* 插入排序截止范围 */

void quickSortHelper(void **arr, size_t left, size_t right, int (*compare)(void *, void *)) {
    /* 如果长度小于 CUTOFF 则使用插入排序 */
    if (left + CUTOFF > right) {
        insertionSort(arr + left, right - left + 1, compare);
        return;
    }

    void *pivot = media3(arr, left, right, compare);
    size_t i = left, j = right - 1;
    while (1) {
        while (compare(arr[++i], pivot) < 0) {};
        while (compare(arr[--j], pivot) > 0) {};
        if (i >= j)
            break;
        swap(arr, i, j);
    }
    /* restore pivot */
    swap(arr, i, right - 1);

    quickSortHelper(arr, left, i - 1, compare);
    quickSortHelper(arr, i + 1, right, compare);
}

void quickSort(void **base, size_t nitems, int (*compar)(void *, void *)) {
    quickSortHelper(base, 0, nitems - 1, compar);
}

void mergeSortHelper(void **arr, void **tmpArr, size_t left, size_t right, int(*compar)(void *, void *)) {
    if (left >= right)
        return;

    /* divide */
    size_t mid = left + ((right - left) >> 1);
    mergeSortHelper(arr, tmpArr, left, mid, compar);
    mergeSortHelper(arr, tmpArr, mid + 1, right, compar);

    /* merge */
    size_t i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
        if (compar(arr[i], arr[j]) < 0)
            tmpArr[k++] = arr[i++];
        else
            tmpArr[k++] = arr[j++];
    while (i <= mid)
        tmpArr[k++] = arr[i++];
    while (j <= right)
        tmpArr[k++] = arr[j++];

    for (size_t ii = 0; ii < right - left + 1; ii++)
        arr[ii + left] = tmpArr[ii];
}

void mergeSort(void **base, size_t nitems, int(*compar)(void *, void *)) {
    void **tmp = (void **) malloc(sizeof(void *) * nitems);
    mergeSortHelper(base, tmp, 0, nitems - 1, compar);
    free(tmp);
}


void insertionSort(void **base, size_t nitems, int (*compar)(void *, void *)){
    for (size_t i = 1; i < nitems; i++) {
        size_t j;
        void *tmp = base[i];
        for (j = i; j > 0; j--) {
            if (compar(base[j - 1], tmp) <= 0)
                break;
            base[j] = base[j - 1];
        }
        base[j] = tmp;
    }
}

/*
 * 获取希尔排序过程中用到的 Hibbard 增量序列
 */
int* getHibbardStepArr(int n, int *arrSize) {
    int i = 1;
    while (1) {
        int t = (1 << i) - 1;
        if (t >= n)
            break;
        (*arrSize)++;
        i++;
    }
    int *res = (int *) malloc(sizeof(int) * (*arrSize));
    i = 1;
    while (1) {
        int t = (1 << i) - 1;
        if (t >= n)
            break;
        res[i - 1] = t;
        i++;
    }
    return res;
}

void shellSort(ElementType *arr, int left, int right) {
    if (left >= right)
        return;

    int len = right - left + 1;
    int arrSize = 0;
    int *stepArr = getHibbardStepArr(len, &arrSize);
    for (int k = arrSize - 1; k >= 0; k--) {
        int increment = stepArr[k];
        for (int i = increment; i <= right; i += increment) {
            int j, tmp = arr[i];
            for (j = i; j >= increment + left && arr[j - increment] > tmp; j -= increment)
                arr[j] = arr[j - increment];
            arr[j] = tmp;
        }
    }
    free(stepArr);
}

/**
 * 堆排序下浮操作
 */
void shiftDown(ElementType *arr, int i, int n) {
    int tmp = arr[i], child;
    for (; i * 2 + 1 < n; i = child) {
        child = i * 2 + 1;
        if (child < n - 1 && arr[child + 1] > arr[child])
            child++;
        if (tmp < arr[child])
            arr[i] = arr[child];
        else
            break;
    }
    arr[i] = tmp;
}

void heapSort(ElementType *arr, int n) {
    int i;
    for (i = n / 2; i >= 0; i--) /* build heap */
        shiftDown(arr, i, n);
    for (i = n - 1; i > 0; i--) {
//        swap(&arr[0], &arr[i]); /* poll max to last */
        shiftDown(arr, 0, i);
    }
}