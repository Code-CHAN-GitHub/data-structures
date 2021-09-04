//
// Created by chen on 2021/9/2.
//

#include "Queue.h"

struct Queue {
    int front;
    int rear;
    int size;
    int capacity;
    void **arr;
};

/*
 * 队列扩容
 */
void queueGrow(Queue *q, int minCapacity);

Queue *createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->size = q->capacity = 0;
    q->front = 0;
    q->rear = -1;
    q->arr = NULL;
    return q;
}

int queueSize(Queue *q) {
    return q->size;
}

int queueIsEmpty(Queue *q) {
    assert(q);

    return q->size == 0;
}

void queueAdd(Queue *q, void *val) {
    if (q->size == q->capacity)
        queueGrow(q, q->size + 2);
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

void *queuePoll(Queue *q) {
    if (!queueIsEmpty(q)) {
        void *item = q->arr[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
        return item;
    }
    return NULL;
}

void *queuePeek(Queue *q) {
    if (!queueIsEmpty(q)) {
        return q->arr[q->front];
    }
    return NULL;
}

void queueGrow(Queue *q, int minCapacity) {
    int oldCapacity = q->capacity;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity < minCapacity)
        newCapacity = minCapacity;
    void **oldArr = q->arr;
    void **newArr = (void *) malloc(sizeof(void *) * newCapacity);
    q->arr = newArr;
    q->capacity = newCapacity;
    if (q->size > 0) {
        int i = q->front, t = 0;
        while (i != q->rear) {
            newArr[t++] = oldArr[i];
            i = (i + 1) % oldCapacity;
        }
        newArr[t] = oldArr[i];
        q->front = 0;
        q->rear = q->size - 1;
        free(oldArr);
    }
}