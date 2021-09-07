//
// Created by chen on 2021/9/7.
//
#include <stdio.h>
#include "../queue/Queue.h"

void __test_new_queue() {
    queue *q = new_queue();
    if (q)
        printf("queue address ==> %p", q);
}

void __test_queue_operator() {
    queue *stk = new_queue();
    int *a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(sizeof(int));
        *a[i] = i;
        queue_push(stk, a[i]);
    }
    printf("push [0, 9] front = %d size = %d\n", *(int *)queue_front(stk), queue_size(stk));

    printf("pop all ==> ");
    while (!queue_empty(stk)) {
        printf("%d ", *(int *) queue_pop(stk));
    }
}

int main() {
//    __test_new_queue();
    __test_queue_operator();
}