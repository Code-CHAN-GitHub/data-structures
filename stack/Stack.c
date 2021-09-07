//
// Created by chen on 2021/9/2.
//

#include "Stack.h"

struct stack {
    vector *vec;
};


stack *new_stack() {
    stack *stk = malloc(sizeof(stk));
    stk->vec = new_vector();
    return stk;
}

size_t stack_size(stack *stk) {
    assert(stk);
    return vector_size(stk->vec);
}

int stack_empty(stack *stk) {
    return stack_size(stk) == 0;
}

void stack_push(stack *stk, void *item) {
    vector_push_back(stk->vec, item);
}

void *stack_top(stack *stk) {
    if (!stack_empty(stk))
        return vector_back(stk->vec);
    return NULL;
}

void *stack_pop(stack *stk) {
    if (!stack_empty(stk))
        return vector_pop_back(stk->vec);
    return NULL;
}