//
// Created by chen on 2021/8/31.
//

#ifndef TMP_LIST_H
#define TMP_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;

struct ListStruct;
typedef struct ListStruct *List;

List createList();
int listIsEmpty(List l);
int listSize(List l);

/**
 * 链表元素插入
 */
void listAdd(List list, ElementType val);
void listAddLast(List list, ElementType val);
void listAddFirst(List list, ElementType val);
void listAddOnIndex(List list, int index, ElementType val);

/**
 * 链表元素获取
 */
ElementType listGetFirst(List l);
ElementType listGetLast(List l);
ElementType listGet(List l, int index);

/**
 * 链表元素删除
 */
ElementType listRemoveLast(List l);
ElementType listRemoveFirst(List l);
ElementType listRemove(List l); // 删除头节点
ElementType listRemoveByIndex(List l, int index);

void printList(List l);

#endif //TMP_LIST_H
