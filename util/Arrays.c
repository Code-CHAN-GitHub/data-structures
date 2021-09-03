//
// Created by chen on 2021/9/2.
//

#include "Arrays.h"

void arrayCopy(ElementType *src, int srcPos, ElementType *dest, int destPos, int length) {
    if (src != dest) {
        for (int i = 0; i < length; i++)
            dest[destPos + i] = src[srcPos + i];
    } else {
        int tmp[length];
        for (int i = 0; i < length; i++)
            tmp[i] = src[srcPos + i];
        for (int i = 0; i < length; i++)
            dest[destPos + i] = tmp[i];
    }
}

void arrayPrint(ElementType *arr, int start, int end) {
    printf("[");
    for (int i = start; i <= end - 1; i++) {
        printf("%d, ", arr[i]);
    }
    if (end - start + 1 > 0)
        printf("%d", arr[end]);
    printf("]\n");
}