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

void __quick_sort_helper(void **arr, size_t left, size_t right, int (*compare)(void *, void *)) {
    /* 如果长度小于 CUTOFF 则使用插入排序 */
    if (left + CUTOFF > right) {
        insertion_sort(arr + left, right - left + 1, compare);
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

    __quick_sort_helper(arr, left, i - 1, compare);
    __quick_sort_helper(arr, i + 1, right, compare);
}

void quick_sort(void **base, size_t nitems, int (*compar)(void *, void *)) {
    __quick_sort_helper(base, 0, nitems - 1, compar);
}

void __merge_sort_helper(void **arr, void **tmpArr, size_t left, size_t right, int(*compar)(void *, void *)) {
    if (left >= right)
        return;

    /* divide */
    size_t mid = left + ((right - left) >> 1);
    __merge_sort_helper(arr, tmpArr, left, mid, compar);
    __merge_sort_helper(arr, tmpArr, mid + 1, right, compar);

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

void merge_sort(void **base, size_t nitems, int(*compar)(void *, void *)) {
    void **tmp = (void **) malloc(sizeof(void *) * nitems);
    __merge_sort_helper(base, tmp, 0, nitems - 1, compar);
    free(tmp);
}


void insertion_sort(void **base, size_t nitems, int (*compar)(void *, void *)){
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

vector *__hibbard_step_vec(size_t nitems) {
    vector *vec = new_vector();
    size_t i = 1;
    while (1) {
        size_t *x = malloc(sizeof(size_t));
        *x = (1 << i) - 1;
        if (*x >= nitems)
            break;
        vector_push_back(vec, x);
        i++;
    }
    return vec;
}

void shell_sort(void **base, size_t nitems, int (*compare)(void *, void *)) {
    vector *stepVec = __hibbard_step_vec(nitems);
    while (!vector_empty(stepVec)) {
        size_t increment = *(size_t *) vector_pop_back(stepVec);
        for (size_t i = increment; i <= nitems - 1; i += increment) {
            size_t j;
            void *tmp = base[i];
            for (j = i; j >= increment && compare(base[j - increment], tmp) > 0; j -= increment)
                base[j] = base[j - increment];
            base[j] = tmp;
        }
    }
    free(stepVec);
}

void __shift_down(void **arr, size_t i, size_t n, int (*compare)(void *, void *)) {
    void *tmp = arr[i];
    size_t child;
    for (; i * 2 + 1 < n; i = child) {
        child = i * 2 + 1;
        if (child < n - 1 && compare(arr[child + 1], arr[child]) > 0)
            child++;
        if (compare(tmp, arr[child]) >= 0)
            break;
        arr[i] = arr[child];
    }
    arr[i] = tmp;
}

void heap_sort(void **base, size_t nitems, int (*compare)(void *, void *)) {
    size_t i;
    for (i = nitems / 2; ; i--) { /* build heap */
        __shift_down(base, i, nitems, compare);
        /* 注意 size_t 类型无符号 */
        if (i == 0)
            break;
    }
    for (i = nitems - 1; i > 0; i--) {
        /* 将堆顶元素移到尾部 */
        swap(base, 0, i);
        __shift_down(base, 0, i, compare);
    }
}