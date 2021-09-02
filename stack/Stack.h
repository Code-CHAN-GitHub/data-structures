//
// Created by chen on 2021/9/2.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../vector/Vector.h"

typedef int ElementType;

typedef Vector Stack;

Stack createStack();

int stackSize(Stack stk);

int stackIsEmpty(Stack stk);

void stackPush(Stack stk, ElementType val);

ElementType stackPop(Stack stk);

ElementType stackPeek(Stack stk);

void printStack(Stack stk);

#endif //DATA_STRUCTURES_STACK_H
