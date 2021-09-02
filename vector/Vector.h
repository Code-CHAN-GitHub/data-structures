/**
 * Vector 动态数组实现
 */

#ifndef DATA_STRUCTURES_VECTOR_H
#define DATA_STRUCTURES_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include "../util/Arrays.h"

// 元素类型
typedef int ElementType;

struct VectorStruct;
typedef struct VectorStruct *Vector;

/**
 * 创建一个空的 vector
 * @return vector
 */
Vector createVector();

/**
 * 指定初始化容量创建 vector
 * @param initialCapacity
 * @return vector
 */
Vector createVectorByInitCapacity(int initialCapacity);

/**
 * 返回 vector 大小
 * @param vec - vector
 * @return size - 大小
 */
int vectorSize(Vector vec);

/**
 * 向 vector 尾部插入元素
 * @param vec - vector
 * @param val - 元素
 */
void vectorAdd(Vector vec, ElementType val);

/**
 * 根据索引插入元素，并将当前位置的元素（如果有）和任何后续元素向后移动，索引位置加 1
 * @param vec - vector
 * @param val - 元素
 * @param index - 索引
 */
void vectorAddByIndex(Vector vec, ElementType val, int index);

/**
 * 根据索引获取元素
 * @param vec - vector
 * @param index - 索引
 * @return val - 元素
 */
ElementType vectorGet(Vector vec, int index);

/**
 * 根据索引移除元素，将当前位置的下一元素（如果有）和任何后续元素向前移动，索引位置减 1
 * @param vec - vector
 * @param index - 索引
 * @return val - 移除前该位置的元素
 */
ElementType vectorRemove(Vector vec, int index);

/**
 * 根据索引修改对应元素的值
 * @param vec - vector
 * @param val - 元素
 * @param index - 索引
 */
void vectorSet(Vector vec, ElementType val, int index);

/**
 * 生成对应的数组
 * @param vec - vector
 * @return val[] - 元素数组
 */
ElementType* vectorToArray(Vector vec);

/**
 * 打印 vector
 * @param vec - vector
 */
void printVector(Vector vec);

#endif //DATA_STRUCTURES_VECTOR_H
