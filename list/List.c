#include "List.h"

typedef struct ListNode ListNode;
struct ListNode {
    void *item;
    ListNode *prev;
    ListNode *next;
};

struct List {
    int size;
    ListNode *first;
    ListNode *last;
};

/*
 * 创建 ListNode
 */
ListNode *createListNode(void *item, ListNode *prev, ListNode *next);

/*
 * 根据索引查找 ListNode
 */
ListNode *findListNode(List *l, int index);

/*
 * 判断是否为 list 的索引
 */
int isListIndex(List *l, int index);


List *createList() {
    List *l = (List*) malloc(sizeof(List));
    l->size = 0;
    l->first = l->last = NULL;
    return l;
}

int listIsEmpty(List *l) {
    assert(l);
    return l->size == 0;
}

int listSize(List *l) {
    if (!listIsEmpty(l))
        return l->size;
    return 0;
}

void listAddLast(List *l, void *item) {
    ListNode *last = l->last;
    ListNode *newNode = createListNode(item, last, NULL);
    l->last = newNode;
    if (last == NULL)
        l->first = newNode;
    else
        last->next = newNode;
    l->size++;
}

void listAdd(List *l, void *item) {
    listAddLast(l, item);
}

void listAddFirst(List *l, void *item) {
    ListNode *first = l->first;
    ListNode *newNode = createListNode(item, NULL, first);
    l->first = newNode;
    if (first == NULL)
        l->last = newNode;
    else
        first->prev = newNode;
    l->size++;
}

void listAddOnIndex(List *l, int index, void *item) {
    // 此处不用 isListIndex 判断，因为可以向 index == listSize (即尾部) 添加元素
    assert(l != NULL && index >= 0 && index <= listSize(l));

    if (index == listSize(l)) {
        listAddLast(l, item);
    } else if (index == 0) {
        listAddFirst(l, item);
    } else {
        ListNode *p = findListNode(l, index);
        ListNode *newNode = createListNode(item, p, p->next);
        p->prev->next = newNode;
        p->prev = newNode;
        l->size++;
    }
}

void *listGetFirst(List *l) {
    if (!listIsEmpty(l))
        return l->first->item;
    return NULL;
}

void *listGetLast(List *l) {
    if (!listIsEmpty(l))
        return l->last->item;
    return NULL;
}

void *listGet(List *l, int index) {
    assert(l != NULL && isListIndex(l, index));

    ListNode *first = l->first;
    ListNode *p = first;
    while (index-- > 0) {
        p = p->next;
    }
    return p->item;
}

void listSet(List *l, int index, void *item) {
    assert(l != NULL && isListIndex(l, index));

    ListNode *node = findListNode(l, index);
    node->item = item;
}

void *listRemoveLast(List *l) {
    assert(l != NULL && !listIsEmpty(l));

    ListNode *last = l->last;
    void *item = last->item;
    l->last = last->prev;
    if (l->last == NULL)
        l->first = NULL;
    else
        l->last->next = NULL;
    l->size--;
    ListNode *tmp = last;
    free(last);
    return item;
}

void *listRemoveFirst(List *l) {
    assert(l != NULL && !listIsEmpty(l));

    ListNode *first = l->first;
    ListNode *item = first->item;
    l->first = first->next;
    if (l->first == NULL)
        l->last = NULL;
    else
        l->first->prev = NULL;
    l->size--;
    return item;
}

void *listRemove(List *l, int index) {
    assert(l != NULL && isListIndex(l, index));

    if (index == 0) {
        return listRemoveFirst(l);
    } else if (index == l->size - 1) {
        return listRemoveLast(l);
    }
    ListNode *node = findListNode(l, index);
    void *item = node->item;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    l->size--;
    free(node);
    return item;
}

ListNode *createListNode(void *item, ListNode *prev, ListNode *next) {
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->item = item;
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
}

ListNode *findListNode(List *l, int index) {
    // 双向链表查找最坏情况时间复杂度为 O(N/2)
    if (index < (l->size >> 1)) {
        ListNode *p = l->first;
        for (int i = 0; i < index; i++)
            p = p->next;
        return p;
    } else {
        ListNode *p = l->last;
        for (int i = l->size - 1; i > index; i--)
            p = p->prev;
        return p;
    }
}

int isListIndex(List *l, int index) {
    return index >= 0 && index < l->size;
}


