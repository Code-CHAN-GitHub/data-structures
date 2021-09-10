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
    queue *q = new_queue();
    int *a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(sizeof(int));
        *a[i] = i;
        queue_push(q, a[i]);
    }
    printf("push [0, 9] front = %d size = %d\n", *(int *)queue_front(q), queue_size(q));

    printf("pop all ==> ");
    while (!queue_empty(q)) {
        printf("%d ", *(int *) queue_pop(q));
    }
}

//int main() {
////    __test_new_queue();
////    __test_queue_operator();
//}