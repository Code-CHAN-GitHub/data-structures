//
// Created by chen on 2021/9/2.
//

#include "Stack.h"

Stack *createStack() {
    return createVector();
}

void stackPush(Stack *stk, void *item) {
    vectorAdd(stk, item);
}

void *stackPeek(Stack *stk) {
    return vectorGet(stk, stackSize(stk) - 1);
}

void *stackPop(Stack *stk) {
    return vectorRemove(stk, stackSize(stk) - 1);
}

int stackSize(Stack *stk) {
    return vectorSize(stk);
}

int stackIsEmpty(Stack *stk) {
    return stackSize(stk) == 0;
}