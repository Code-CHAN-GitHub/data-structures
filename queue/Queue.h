//
// Created by chen on 2021/9/2.
//

#ifndef DATA_STRUCTURES_queue_H
#define DATA_STRUCTURES_queue_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct queue queue;

/**
 * 获取一个空队列
 */
queue *new_queue();

/*
 * 队列大小
 */
size_t queue_size(queue *q);

/**
 * 判断队列是否为空
 */
int queue_empty(queue *q);

/**
 * 向队列尾部添加元素
 */
void queue_push(queue *q, void *item);

/**
 * 弹出队列头部元素
 */
void *queue_pop(queue *q);

/**
 * 获取队列头部元素，但不弹出
 */
void *queue_front(queue *q);

#endif //DATA_STRUCTURES_queue_H
