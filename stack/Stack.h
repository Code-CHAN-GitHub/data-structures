/**
 * Stack 利用 Vector 实现栈
 */

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../vector/Vector.h"


// Stack 实际上就是 Vector
typedef Vector Stack;

/**
 * 创建一个空栈
 * @return stack - 栈
 */
Stack *createStack();

/**
 * 获取栈的大小
 * @param stk - 栈
 * @return size - 大小
 */
int stackSize(Stack *stk);

/**
 * 判断栈是否为空
 * @param stk - 栈
 * @return 0 为非空，1 为空
 */
int stackIsEmpty(Stack *stk);

/**
 * 将元素压入栈中
 * @param stk - 栈
 * @param val - 元素
 */
void stackPush(Stack *stk, void *item);

/**
 * 弹出顶部元素
 * @param stk - 栈
 * @return val - 元素
 */
void *stackPop(Stack *stk);

/**
 * 获取顶部元素值，但不弹出
 * @param stk - 栈
 * @return val - 元素
 */
void *stackPeek(Stack *stk);

/**
 * 打印 stack
 * @param stk
 */
//void printStack(Stack stk);

#endif //DATA_STRUCTURES_STACK_H
