//
// Created by chen on 2021/9/7.
//

#include <stdio.h>
#include "../stack/Stack.h"

void __test_new_stack() {
    stack *stk = new_stack();
    if (stk)
        printf("stack address ==> %p", stk);
}

void __test_stack_operator() {
    stack *stk = new_stack();
    int *a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(sizeof(int));
        *a[i] = i;
        stack_push(stk, a[i]);
    }
    printf("push [0, 9] top = %d size = %d\n", *(int *)stack_top(stk), stack_size(stk));

    printf("pop all ==> ");
    while (!stack_empty(stk)) {
        printf("%d ", *(int *) stack_pop(stk));
    }
}

//int main() {
////    __test_new_stack();
////    __test_stack_operator();
//}