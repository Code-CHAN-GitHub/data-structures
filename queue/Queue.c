//
// Created by chen on 2021/9/2.
//

#include "Queue.h"

struct QueueStruct {
    int front;
    int rear;
    int size;
    int capacity;
    ElementType *arr;
};

ElementType EMPTY_ARR[];

Queue createQueue() {
    Queue q = (Queue) malloc(sizeof(struct QueueStruct));
    q->front = -1;
    q->rear = -1;
    q->arr = EMPTY_ARR;
    return q;
}