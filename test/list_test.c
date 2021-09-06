//
// Created by chen on 2021/9/6.
//

#include <stdio.h>
#include "../list/List.h"

void __test_new_list() {
    list *l = new_list();
    if (l)
        printf("list address ==> %p\n", l);
}

/*
 *
 */
list *__create_list(int start, int end) {
    list *l = new_list();
    for (int i = start; i <= end; i++) {
        int *x = malloc(sizeof(int));
        *x = i;
        list_push_back(l, x);
    }
    return l;
}

/*
 * 打印链表
 */
void __print_list(list *l) {
    for (size_t ii = 0; ii < list_size(l); ii++) {
        printf("%d ", *(int *)list_get(l, ii));
    }
    printf("\n");
}

void __test_list_push() {
    list *l = __create_list(0, 10);
    printf("push_back [0,10] ==> ");
    __print_list(l);

    for (int i = 9; i >= 0; i--) {
        int *x = malloc(sizeof(int));
        *x = i;
        list_push_front(l, x);
    }
    printf("push_front [0, 10) ==> ");
    __print_list(l);
}

void __test_list_pop() {
    list *l = __create_list(0, 9);
    printf("pop_front ==> ");
    while (!list_empty(l)) {
        printf("%d ", *(int *)(list_pop_front(l)));
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        int *x = malloc(sizeof(int));
        *x = i;
        list_push_back(l, x);
    }
    printf("pop_back ==> ");
    while (!list_empty(l)) {
        printf("%d ", *(int *)(list_pop_back(l)));
    }
}

void __test_list_insert() {
    list *l = __create_list(0, 10);
    __print_list(l);

    int *x = malloc(sizeof(int));
    *x = 100;
    list_insert(l, 0, x);
    printf("insert index = %d, x = %d ==> ", 0, *x);
    __print_list(l);

    int *y = malloc(sizeof(int));
    *y = 200;
    list_insert(l, 3, y);
    printf("insert index = %d, y = %d ==> ", 3, *y);
    __print_list(l);

    int *z = malloc(sizeof(int));
    *z = 300;
    list_insert(l, list_size(l), z);
    printf("insert index = %d, z = %d ==> ", list_size(l) - 1, *z);
    __print_list(l);
}

void __test_list_set() {
    list *l = __create_list(0, 10);
    __print_list(l);


    int *x = malloc(sizeof(int));
    *x = 100;
    list_set(l, 0, x);
    printf("set index = %d, x = %d ==> ", 0, *x);
    __print_list(l);

    int *y = malloc(sizeof(int));
    *y = 200;
    list_set(l, 2, y);
    printf("set index = %d, y = %d ==> ", 2, *y);
    __print_list(l);

    int *z = malloc(sizeof(int));
    *z = 300;
    list_set(l, list_size(l) - 1, z);
    printf("set index = %d, z = %d ==> ", list_size(l) - 1, *z);
    __print_list(l);
}

void __test_list_remove() {
    list *l = __create_list(0, 10);
    __print_list(l);

    printf("remove index = %d ==> ", 0);
    list_remove(l, 0);
    __print_list(l);

    printf("remove index = %d ==> ", 9);
    list_remove(l, 9);
    __print_list(l);

    printf("remove index = %d ==> ", 3);
    list_remove(l, 3);
    __print_list(l);
}

/**
 * 使用非法索引、对空链表获取元素
 */
void __test_list_err() {
    list *l = __create_list(0, 10);
    __print_list(l);

    printf("get index = %d ==> ", -1);
//    list_get(l, -1);
    printf("throw Assertion failed: (l != NULL && __is_list_index(l, index)), function list_get\n");

    printf("get index = %d ==> ", list_size(l));
//    list_get(l, list_size(l));
    printf("throw Assertion failed: (l != NULL && __is_list_index(l, index)), function list_get\n");

    printf("front ==> %d  back ==> %d\n", *(int *)list_front(l), *(int *)list_back(l));

    printf("list clear ... ");
    while (!list_empty(l)) {
        list_pop_back(l);
    }
    printf("size ==> %d\n", list_size(l));

    printf("front ==> %s back ==> %s\n", list_front(l) == NULL ? "NULL" : "not null", list_back(l) == NULL ? "NULL" : "not null");
}

int main() {
//    __test_new_list();
//    __test_list_push();
//    __test_list_pop();
//    __test_list_insert();
//    __test_list_set();
//    __test_list_remove();
    __test_list_err();
}
