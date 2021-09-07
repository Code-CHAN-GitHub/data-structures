//
// Created by chen on 2021/9/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../avl_tree/AvlTree.h"
#include "../binary_search_tree/BSTree.h"

int __int_compare2(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

char *__int_to_str1(char s[], void *val) {
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

void __test_new_avl_tree() {
    avl_tree *avl = new_avl_tree(__int_compare2);
    if (avl)
        printf("avl address ==> %p", avl);
}

void __test_avl_operator() {
    avl_tree *avl = new_avl_tree(__int_compare2);
    for (int i = 0; i < 10; i++) {
        int *x = malloc(sizeof(int));
        *x = i;
        avl_tree_push(avl, x);
    }
    avl_tree_print(avl, __int_to_str1);
}

/**
 * 比较 avl_tree 和 bs_tree 在插入一段顺序数列
 * 两者生成树的结构和树的高度
 */
void __test_avl_bs_tree_height() {
    avl_tree *avl = new_avl_tree(__int_compare2);
    binary_search_tree *bs_tree = new_bs_tree(__int_compare2);
    for (int i = 0; i < 15; i++) {
        int *x = malloc(sizeof(int));
        *x = i;
        avl_tree_push(avl, x);
        bs_tree_push(bs_tree, x);
    }
    printf("bs_tree ==> ");
    bs_tree_print(bs_tree, __int_to_str1);
    printf("avl_tree ==> ");
    avl_tree_print(avl, __int_to_str1);
}

void __test_avl_tree_contain() {
    avl_tree *avl = new_bs_tree(__int_compare2);
    int *a[10];
    srand((unsigned ) time(NULL));

    for (int i = 0; i < 10; i++) {
        a[i] = malloc(sizeof(int));
        *a[i] = rand() % 100;
        avl_tree_push(avl, a[i]);
    }
    avl_tree_print(avl, __int_to_str1);

    int *x = malloc(sizeof(int));
    *x = 200;
    printf("contain %d ==> %s\n", *x, avl_tree_contain(avl, x) ? "true" : "false");

    for (int i = 0; i < 10; i++) {
        printf("contain %d ==> %s\n", *a[i], avl_tree_contain(avl, a[i]) ? "true" : "false");
    }
}

int main() {
//    __test_new_avl_tree();
//    __test_avl_operator();
//    __test_avl_bs_tree_height();
    __test_avl_tree_contain();
}