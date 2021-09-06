/**
 * list 使用双向链表实现
 */

#ifndef TMP_list_H
#define TMP_list_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list list;

/**
 * 创建一个空链表
 */
list *new_list();

/**
 * 判断链表是否为空
 */
int list_empty(list *l);

/**
 * 返回链表大小
 */
int list_size(list *l);

/**
 * 从链表尾部插入元素
 */
void list_push_back(list *l, void *item);

/**
 * 从链表头部插入元素
 */
void list_push_front(list *l, void *item);

/**
 * 在此链表指定位置插入元素，将当前位置的节点（如果有）和任何后续节点向后移动，索引位置加 1
 * 索引从 0 开始，到 list_size(l) - 1，若索引不在合法范围，则会产生异常
 */
void list_insert(list *l, size_t index, void *item);

/**
 * 获取链表的头节点的值
 * 若链表为空则返回 NULL
 */
void *list_front(list *l);

/**
 * 获取链表尾部节点的值
 * 若链表为空则返回 NULL
 */
void *list_back(list *l) ;

/**
 * 根据索引获取元素，索引从 0 开始，到 list_size(l) - 1
 * 若索引不在合法范围，则会产生异常
 */
void *list_get(list *l, size_t index);

/**
 * 根据索引修改对应节点的元素值，索引从 0 开始，到 list_size(l) - 1
 * 若索引不在合法范围，则会产生异常
 */
void list_set(list *l, size_t index, void *item);

/**
 * 移除尾部节点，若链表为空，则会产生异常
 */
void *list_pop_back(list *l) ;

/**
 * 移除头部节点，若链表为空，则会产生异常
 */
void *list_pop_front(list *l);

/**
 * 根据索引移除节点，将当前位置的下一节点（如果有）和任何后续节点向前移动，索引位置减 1
 * 索引从 0 开始，到 list_size(l) - 1，若索引不在合法范围，则会产生异常
 */
void *list_remove(list *l, size_t index);

#endif //TMP_list_H
