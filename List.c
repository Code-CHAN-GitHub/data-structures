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

int listIsEmpty(List l) {
    return l == NULL || l->size == 0;
}

int listSize(List l) {
    if (listIsEmpty(l))
        return 0;
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

PtrToNode findNode(List l, int index) {
    if (index >= l->size || index < 0)
        return NULL;

    if (index < (l->size >> 1)) {
        PtrToNode p = l->first;
        for (int i = 0; i < index; i++)
            p = p->next;
        return p;
    } else {
        PtrToNode p = l->last;
        for (int i = l->size - 1; i > index; i--)
            p = p->prev;
        return p;
    }
}

void listAddOnIndex(List list, int index, ElementType val) {
    if (index > listSize(list) || index < 0) {
        printf("坐标越界!\n");
    } else if (index == listSize(list)) {
        listAddLast(list, val);
    } else if (index == 0) {
        listAddFirst(list, val);
    } else {
        const PtrToNode p = findNode(list, index);
        const PtrToNode newNode = createNode(val, p, p->next);
        p->prev->next = newNode;
        p->prev = newNode;
        list->size++;
    }
}

ElementType listGetFirst(List l) {
    if (listIsEmpty(l)) {
        printf("链表为空!\n");
        return -1;
    }
    return l->first->val;
}

ElementType listGetLast(List l) {
    if (listIsEmpty(l)) {
        printf("链遍为空!\n");
        return -1;
    }
    return l->last->val;
}

ElementType listGet(List l, int index) {
    if (index > listSize(l) || index < 0) {
        printf("坐标越界!\n");
    } else if (listIsEmpty(l)) {
        printf("链遍为空!\n");
    } else {
        const PtrToNode first = l->first;
        PtrToNode p = first;
        while (index-- > 0) {
            p = p->next;
        }
        return p->val;
    }
    return -1;
}

ElementType listRemoveLast(List l) {
    if (listIsEmpty(l)) {
        printf("链遍为空!\n");
        return -1;
    }
    const PtrToNode last = l->last;
    const ElementType val = last->val;
    l->last = last->prev;
    if (l->last == NULL)
        l->first = NULL;
    else
        l->last->next = NULL;
    l->size--;
    const PtrToNode tmp = last;
    free(last);
    return val;
}

ElementType listRemoveFirst(List l) {
    if (listIsEmpty(l)) {
        printf("链表为空!\n");
        return -1;
    }
    const PtrToNode first = l->first;
    const ElementType val = first->val;
    l->first = first->next;
    if (l->first == NULL)
        l->last = NULL;
    else
        l->first->prev = NULL;
    l->size--;
    return val;
}

ElementType listRemove(List l) {
    return listRemoveFirst(l);
}

ElementType listRemoveByIndex(List l, int index) {
    if (index >= l->size || index < 0) {
        printf("下标越界!\n");
        return -1;
    } else if (index == 0) {
        return listRemoveFirst(l);
    } else if (index == l->size - 1) {
        return listRemoveLast(l);
    }
    const PtrToNode node =findNode(l, index);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    l->size--;
    free(node);
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
    free(dummy);
}



