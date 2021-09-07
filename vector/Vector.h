/**
 * vector 动态数组实现
 */

#ifndef DATA_STRUCTURES_vector_H
#define DATA_STRUCTURES_vector_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct vector vector;

/**
 * 创建一个空的 vector
 */
vector *new_vector();

/**
 * 指定初始化容量创建 vector
 */
vector *new_vector_with_capacity(int initialCapacity);

/**
 * 返回 vector 内元素数量
 */
size_t vector_size(vector *vec);

/**
 * 判断 vector 是否为空
 */
int vector_empty(vector *vec);

/**
 * 向 vector 尾部插入元素
 */
void vector_push_back(vector *vec, void *item);

/**
 * 向 vector 头部插入元素，并将原容器内所有元素的索引位置加 1
 */
void vector_push_front(vector *vec, void *item);

/**
 * 根据索引插入元素，并将当前位置的元素（如果有）和任何后续元素向后移动，索引位置加 1
 * @param index - 范围为 [0, vector_size]
 */
void vector_insert(vector *vec, size_t index, void *item);

/**
 * 根据索引获取元素
 * @param index - 范围为 [0, vector_size - 1]
 * @return 返回对应位置元素，若索引不在上述范围，则返回 NULL
 */
void *vector_get(vector *vec, size_t index);

/**
 * 获取头部元素
 * @return 返回元素，若容器为空，返回 NULL
 */
void *vector_front(vector *vec);

/**
 * 获取尾部元素
 * @return 返回元素，若容器为空，返回 NULL
 */
void *vector_back(vector *vec);

/**
 * 根据索引移除元素，将当前位置的下一元素（如果有）和任何后续元素向前移动，索引位置减 1
 * @param index - 范围为 [0, vector_size - 1]
 * @return 返回对应位置元素，若索引不在上述范围，则返回 NULL
 */
void *vector_remove(vector *vec, size_t index);

/**
 * 弹出头部元素
 * @return 容器不为空，返回元素。若为空，返回 NULL
 */
void *vector_pop_front(vector *vec);

/**
 * 弹出尾部元素
 * @return 容器不为空，返回元素。若为空，返回 NULL
 */
void *vector_pop_back(vector *vec);

/**
 * 根据索引修改对应元素的值
 * @param index - 范围为 [0, vector_size - 1]
 */
void vector_set(vector *vec, size_t index, void *item);

#endif //DATA_STRUCTURES_vector_H
