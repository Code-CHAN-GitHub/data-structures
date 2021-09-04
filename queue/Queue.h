//
// Created by chen on 2021/9/2.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;

typedef struct Queue Queue;

/**
 * 获取一个空队列
 */
Queue *createQueue();

/*
 * 队列大小
 */
int queueSize(Queue *q);

/**
 * 判断队列是否为空
 */
int queueIsEmpty(Queue *q);

/**
 * 向队列尾部添加元素
 */
void queueAdd(Queue *q, void *item);

/**
 * 弹出队列头部元素
 */
void *queuePoll(Queue *q);

/**
 * 获取队列头部元素，但不弹出
 */
void *queuePeek(Queue *q);

#endif //DATA_STRUCTURES_QUEUE_H
