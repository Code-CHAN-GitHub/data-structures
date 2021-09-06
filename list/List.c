#include "List.h"

typedef struct __list_node __list_node;
struct __list_node {
    void *item;
    __list_node *prev;
    __list_node *next;
};

struct list {
    int size;
    __list_node *first;
    __list_node *last;
};

/*
 * 创建 __list_node
 */
__list_node *__new_list_node(void *item, __list_node *prev, __list_node *next);

/*
 * 根据索引查找 __list_node
 */
__list_node *__find_list_node(list *l, size_t index);

/*
 * 判断是否为 list 的合法索引
 */
int __is_list_index(list *l, size_t index);


list *new_list() {
    list *l = (list*) malloc(sizeof(list));
    l->size = 0;
    l->first = l->last = NULL;
    return l;
}

int list_empty(list *l) {
    assert(l);
    return l->size == 0;
}

int list_size(list *l) {
    if (!list_empty(l))
        return l->size;
    return 0;
}

void list_push_back(list *l, void *item) {
    __list_node *last = l->last;
    __list_node *new_node = __new_list_node(item, last, NULL);
    l->last = new_node;
    if (last == NULL)
        l->first = new_node;
    else
        last->next = new_node;
    l->size++;
}

void list_push_front(list *l, void *item) {
    __list_node *first = l->first;
    __list_node *new_node = __new_list_node(item, NULL, first);
    l->first = new_node;
    if (first == NULL)
        l->last = new_node;
    else
        first->prev = new_node;
    l->size++;
}

void list_insert(list *l, size_t index, void *item) {
    /* 此处不使用 __is_list_index 判断，是因为允许向 index 等于 list_size 处(即尾部) 添加元素 */
    assert(l != NULL && index >= 0 && index <= list_size(l));

    if (index == list_size(l)) {
        list_push_back(l, item);
    } else if (index == 0) {
        list_push_front(l, item);
    } else {
        __list_node *p = __find_list_node(l, index);
        __list_node *new_node = __new_list_node(item, p->prev, p);
        p->prev->next = new_node;
        p->prev = new_node;
        l->size++;
    }
}

void *list_front(list *l) {
    if (!list_empty(l))
        return l->first->item;
    return NULL;
}

void *list_back(list *l) {
    if (!list_empty(l))
        return l->last->item;
    return NULL;
}

void *list_get(list *l, size_t index) {
    assert(l != NULL && __is_list_index(l, index));

    return __find_list_node(l, index)->item;
}

void list_set(list *l, size_t index, void *item) {
    assert(l != NULL && __is_list_index(l, index));

    __list_node *node = __find_list_node(l, index);
    node->item = item;
}

void *list_pop_back(list *l) {
    assert(l != NULL && !list_empty(l));

    __list_node *last = l->last;
    void *item = last->item;
    l->last = last->prev;
    if (l->last == NULL)
        l->first = NULL;
    else
        l->last->next = NULL;
    l->size--;
    __list_node *tmp = last;
    free(last);
    return item;
}

void *list_pop_front(list *l) {
    assert(l != NULL && !list_empty(l));

    __list_node *first = l->first;
    __list_node *item = first->item;
    l->first = first->next;
    if (l->first == NULL)
        l->last = NULL;
    else
        l->first->prev = NULL;
    l->size--;
    return item;
}

void *list_remove(list *l, size_t index) {
    assert(l != NULL && __is_list_index(l, index));

    if (index == 0) {
        return list_pop_front(l);
    } else if (index == l->size - 1) {
        return list_pop_back(l);
    }
    __list_node *node = __find_list_node(l, index);
    void *item = node->item;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    l->size--;
    free(node);
    return item;
}

__list_node *__new_list_node(void *item, __list_node *prev, __list_node *next) {
    __list_node *new_node = (__list_node *) malloc(sizeof(__list_node));
    new_node->item = item;
    new_node->prev = prev;
    new_node->next = next;
    return new_node;
}

__list_node *__find_list_node(list *l, size_t index) {
    // 双向链表查找最坏情况时间复杂度为 O(N/2)
    if (index < (l->size >> 1)) {
        __list_node *p = l->first;
        for (size_t i = 0; i < index; i++)
            p = p->next;
        return p;
    } else {
        __list_node *p = l->last;
        for (size_t i = l->size - 1; i > index; i--)
            p = p->prev;
        return p;
    }
}

int __is_list_index(list *l, size_t index) {
    return index >= 0 && index < l->size;
}


