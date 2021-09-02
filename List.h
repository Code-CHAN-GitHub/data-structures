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
void listAdd(List list, ElementType val);
void listAddLast(List list, ElementType val);
void listAddFirst(List list, ElementType val);


void printList(List l);

#endif //TMP_LIST_H
