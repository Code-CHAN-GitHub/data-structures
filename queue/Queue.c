//
// Created by chen on 2021/9/2.
//

#include "Queue.h"

struct queue {
    size_t front;
    size_t rear;
    size_t size;
    size_t capacity;
    void **arr;
};

/**
 * 队列扩容
 * @param min_capacity - 最小扩容量，即扩容后容量至少为 min_capacity
 */
void __queue_grow(queue *q, size_t min_capacity);

queue *new_queue() {
    queue *q = (queue*) malloc(sizeof(queue));
    q->size = q->capacity = 0;
    q->front = 0;
    q->rear = -1;
    q->arr = NULL;
    return q;
}

size_t queue_size(queue *q) {
    assert(q);
    return q->size;
}

int queue_empty(queue *q) {
    assert(q);
    return q->size == 0;
}

void queue_push(queue *q, void *val) {
    if (q->size == q->capacity)
        __queue_grow(q, q->size + 2);
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

void *queue_pop(queue *q) {
    if (!queue_empty(q)) {
        void *item = q->arr[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
        return item;
    }
    return NULL;
}

void *queue_front(queue *q) {
    if (!queue_empty(q))
        return q->arr[q->front];
    return NULL;
}

void __queue_grow(queue *q, size_t min_capacity) {
    size_t old_capacity = q->capacity;
    size_t new_capacity = old_capacity + (old_capacity >> 1);
    if (new_capacity < min_capacity)
        new_capacity = min_capacity;

    void **old_arr = q->arr;
    void **new_arr = (void *) malloc(sizeof(void *) * new_capacity);
    q->arr = new_arr;
    q->capacity = new_capacity;

    if (q->size > 0) {
        size_t i = q->front, t = 0;
        while (i != q->rear) {
            new_arr[t++] = old_arr[i];
            i = (i + 1) % old_capacity;
        }
        new_arr[t] = old_arr[i];
        q->front = 0;
        q->rear = q->size - 1;
        free(old_arr);
    }
}