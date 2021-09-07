//
// Created by chen on 2021/9/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../binary_search_tree/BSTree.h"

int __int_compare1(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

char *__int_to_str(char s[], void *val) {
    int x = *(int *)val;
    size_t i = 0;
    while (x > 0) {
        s[i++] = (char) ('0' + (x % 10));
        x /= 10;
    }
    size_t j = 0;
    while (j < i / 2) {
        char t = s[i - j - 1];
        s[i - j - 1] = s[j];
        s[j] = t;
        j++;
    }

    s[i] = '\0';
    return s;
}

void __test_new_bs_tree() {
    binary_search_tree *bs_tree = new_bs_tree(__int_compare1);
    if (bs_tree)
        printf("bs_tree address ==> %p", bs_tree);
}

void __test_bs_tree_operator() {
    binary_search_tree *bs_tree = new_bs_tree(__int_compare1);
    int *a[10];
    srand((unsigned ) time(NULL));
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(sizeof(int));
        *a[i] = rand() % 100;
        bs_tree_push(bs_tree, a[i]);
        printf("push ==> %d max ==> %d min ==> %d\n", *a[i], *(int *)bs_tree_max(bs_tree), *(int *)bs_tree_min(bs_tree));
    }
    printf("bs_tree ==> ");
    bs_tree_print(bs_tree, __int_to_str);
}

int main() {
//    __test_new_bs_tree();
    __test_bs_tree_operator();
}