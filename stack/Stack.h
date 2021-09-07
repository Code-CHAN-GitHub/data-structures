/**
 * Stack 利用 Vector 实现栈
 */

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../vector/Vector.h"


typedef struct stack stack;

/**
 * 创建一个空栈
 * @return stack - 栈
 */
stack *new_stack();

/**
 * 获取栈的大小
 * @param stk - 栈
 * @return size - 大小
 */
size_t stack_size(stack *stk);

/**
 * 判断栈是否为空
 * @param stk - 栈
 * @return 0 为非空，1 为空
 */
int stack_empty(stack *stk);

/**
 * 将元素压入栈中
 * @param stk - 栈
 * @param val - 元素
 */
void stack_push(stack *stk, void *item);

/**
 * 弹出顶部元素
 * @param stk - 栈
 * @return val - 元素
 */
void *stack_pop(stack *stk);

/**
 * 获取顶部元素值，但不弹出
 * @param stk - 栈
 * @return val - 元素
 */
void *stack_top(stack *stk);
#endif //DATA_STRUCTURES_STACK_H
