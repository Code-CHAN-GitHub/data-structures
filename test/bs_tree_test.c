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
    if (x == 0) {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

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

void __test_bs_tree_pushr() {
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

void __test_bs_tree_remove() {
    binary_search_tree *bs_tree = new_bs_tree(__int_compare1);
    int *a[10];
    srand((unsigned ) time(NULL));

    for (int i = 0; i < 10; i++) {
        a[i] = malloc(sizeof(int));
        *a[i] = rand() % 100;
        bs_tree_push(bs_tree, a[i]);
    }
    bs_tree_print(bs_tree, __int_to_str);

    printf("remove x = %d ==> ", *a[0]);
    bs_tree_remove(bs_tree, a[0]);
    bs_tree_print(bs_tree, __int_to_str);

    printf("remove x = %d ==> ", *a[3]);
    bs_tree_remove(bs_tree, a[3]);
    bs_tree_print(bs_tree, __int_to_str);

    printf("remove x = %d ==> ", *a[9]);
    bs_tree_remove(bs_tree, a[9]);
    bs_tree_print(bs_tree, __int_to_str);
}

void __test_bs_tree_contain() {
    binary_search_tree *bs_tree = new_bs_tree(__int_compare1);
    int *a[10];
    srand((unsigned ) time(NULL));

    for (int i = 0; i < 10; i++) {
        a[i] = malloc(sizeof(int));
        *a[i] = rand() % 100;
        bs_tree_push(bs_tree, a[i]);
    }
    bs_tree_print(bs_tree, __int_to_str);

    int *x = malloc(sizeof(int));
    *x = 200;
    printf("contain %d ==> %s\n", *x, bs_tree_contain(bs_tree, x) ? "true" : "false");

    for (int i = 0; i < 10; i++) {
        printf("contain %d ==> %s\n", *a[i], bs_tree_contain(bs_tree, a[i]) ? "true" : "false");
    }
}

int main() {
//    __test_new_bs_tree();
//    __test_bs_tree_push();
//    __test_bs_tree_remove();
    __test_bs_tree_contain();
}