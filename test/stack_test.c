//
// Created by chen on 2021/9/7.
//

#include <stdio.h>
#include "../stack/Stack.h"

void __test_new_stack() {
    stack *q = new_stack();
    if (q)
        printf("stack address ==> %p", q);
}

void __test_stack_operator() {
    stack *q = new_stack();
    int *a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(sizeof(int));
        *a[i] = i;
        stack_push(q, a[i]);
    }
    printf("push [0, 9] top = %d size = %d\n", *(int *)stack_top(q), stack_size(q));

    printf("pop all ==> ");
    while (!stack_empty(q)) {
        printf("%d ", *(int *) queue_pop(q));
    }
}

//int main() {
////    __test_new_stack();
////    __test_stack_operator();
//}