/**
 * List 使用双向链表实现
 */

#ifndef TMP_LIST_H
#define TMP_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct List List;

/**
 * 创建一个空链表
 * @return - 空链表
 */
List *createList();

/**
 * 判断链表是否为空
 * @param l - 链表
 * @return 1 为空，0 为非空
 */
int listIsEmpty(List *l);

/**
 * 返回链表大小
 * @param l - 链表
 * @return size - 大小
 */
int listSize(List *l);

/**
 * 从链表尾部插入元素
 * @param l - 链表
 * @param val - 元素
 */
void listAdd(List *l, void *item);

/**
 * 从链表尾部插入元素
 * @param l - 链表
 * @param val - 元素
 */
void listAddLast(List *l, void *item);

/**
 * 从链表头部插入元素
 * @param l - 链表
 * @param val - 元素
 */
void listAddFirst(List *l, void *item);

/**
 * 在此链表指定位置插入元素，将当前位置的节点（如果有）和任何后续节点向后移动，索引位置加 1
 * @param l - 链表
 * @param index - 索引
 * @param val 元素
 */
void listAddOnIndex(List *l, int index, void *item);

/**
 * 获取链表的头节点的值
 * @param l - 链表
 * @return val - 元素
 */
void *listGetFirst(List *l);

/**
 * 获取链表尾部节点的值
 * @param l - 链表
 * @return val - 元素
 */
void *listGetLast(List *l) ;

/**
 * 根据索引获取元素
 * @param l - 链表
 * @param index - 索引
 * @return val - 元素
 */
void *listGet(List *l, int index);

/**
 * 根据索引修改对应节点的元素值
 * @param l - 链表
 * @param val - 值
 * @param index - 索引
 */
void listSet(List *l, int index, void *item);

/**
 * 移除尾部节点
 * @param l - 链表
 * @return val - 移除前尾部元素
 */
void *listRemoveLast(List *l) ;

/**
 * 移除头部节点
 * @param l - 链表
 * @return val - 移除前头部元素
 */
void *listRemoveFirst(List *l);

/**
 * 根据索引移除节点，将当前位置的下一节点（如果有）和任何后续节点向前移动，索引位置减 1
 * @param l
 * @param index
 * @return val - 元素
 */
void *listRemove(List *l, int index);

#endif //TMP_LIST_H
