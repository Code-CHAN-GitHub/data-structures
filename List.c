//
// Created by chen on 2021/8/31.
//

#include "List.h"

struct Node {
    ElementType val;
    PtrToNode prev;
    PtrToNode next;
};

struct ListStruct {
    int size;
    PtrToNode first;
    PtrToNode last;
};

PtrToNode createNode(ElementType val, PtrToNode prev, PtrToNode next) {
    PtrToNode newNode = (PtrToNode) malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
}

List createList() {
    List list = (List) malloc(sizeof(struct ListStruct));
    list->size = 0;
    list->first = list->last = NULL;
    return list;
}

int listSize(List l) {
    return l->size;
}

void listAddLast(List list, ElementType val) {
    const PtrToNode last = list->last;
    const PtrToNode newNode = createNode(val, last, NULL);
    list->last = newNode;
    if (last == NULL)
        list->first = newNode;
    else
        last->next = newNode;
    list->size++;
}

void listAdd(List list, ElementType val) {
    listAddLast(list, val);
}

int listIsEmpty(List l) {
    return l == NULL || l->size == 0;
}

void listAddFirst(List list, ElementType val) {
    const PtrToNode first = list->first;
    const PtrToNode newNode = createNode(val, NULL, first);
    list->first = newNode;
    if (first == NULL)
        list->last = newNode;
    else
        first->prev = newNode;
    list->size++;
}

void listAddOnIndex(List list, int index, ElementType val) {
    if (index > listSize(list) || index < 0) {
        printf("坐标越界!\n");
    } else if (index == listSize(list)) {
        listAddLast(list, val);
    } else if (index == 0) {
        listAddFirst(list, val);
    } else {
        PtrToNode first = list->first;
        const PtrToNode dummy = createNode(0, NULL, first);
        PtrToNode p = dummy;
        while (index-- > 0) {
            p = p->next;
        }
        const PtrToNode newNode = createNode(0, p, p->next);
        p->next->prev = newNode;
        p->next = newNode;
    }
}

void printList(List l) {
    if (listIsEmpty(l)) {
        printf("链表为空!\n");
        return;
    }
    PtrToNode first = l->first;
    const PtrToNode dummy = createNode(0, NULL, first);
    PtrToNode p = dummy->next;
    while (p->next != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("%d\n", p->val);
}



