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
    q->size = q->capacity = 0;
    q->front = 0;
    q->rear = -1;
    q->arr = EMPTY_ARR;
    return q;
}

int queueIsEmpty(Queue q) {
    return q->size == 0;
}

void queueGrow(Queue q, int minCapacity) {
    int oldCapacity = q->capacity;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity < minCapacity)
        newCapacity = minCapacity;
    ElementType *oldArr = q->arr;
    ElementType *newArr = (ElementType *) malloc(sizeof(ElementType) * newCapacity);
    q->arr = newArr;
    q->capacity = newCapacity;
    if (oldCapacity > 0) {
        arrayCopy(oldArr, 0, newArr, 0, oldCapacity);
        free(oldArr);
    }
}

void queueAdd(Queue q, ElementType val) {
    if (q->size == q->capacity)
        queueGrow(q, q->size + 2);
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

ElementType queuePoll(Queue q) {
    if (queueIsEmpty(q)) {
        printf("队列为空!\n");
        return -1;
    }
    ElementType oldVal = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return oldVal;
}

ElementType queuePeek(Queue q) {
    if (queueIsEmpty(q)) {
        printf("队列为空!\n");
        return -1;
    }
    return q->arr[q->front];
}

void printQueue(Queue q) {
    printf("[");
    for (int i = 0; i < q->size - 1; i++) {
        printf("%d, ", q->arr[(q->front + i) % q->capacity]);
    }
    if (q->size > 0)
        printf("%d", q->arr[(q->front + q->size - 1) % q->capacity]);
    printf("]\n");
}