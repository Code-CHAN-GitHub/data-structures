//
// Created by chen on 2021/9/2.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../util/Arrays.h"

typedef int ElementType;

struct QueueStruct;
typedef struct QueueStruct *Queue;

/**
 * 获取一个空队列
 * @return queue - 队列
 */
Queue createQueue();

/**
 * 判断队列是否为空
 * @param q - 队列
 * @return 0 为非空，1 为空
 */
int queueIsEmpty(Queue q);

/**
 * 向队列尾部添加元素
 * @param q - 队列
 * @param val - 元素
 */
void queueAdd(Queue q, ElementType val);

/**
 * 弹出队列头部元素
 * @param q - 队列
 * @return val 元素
 */
ElementType queuePoll(Queue q);

/**
 * 打印 queue
 * @param q - 队列
 */
void printQueue(Queue q);

#endif //DATA_STRUCTURES_QUEUE_H
