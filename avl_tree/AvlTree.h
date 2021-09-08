//
// Created by chen on 2021/9/4.
//

#ifndef DATA_STRUCTURES_avl_tree_H
#define DATA_STRUCTURES_avl_tree_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../queue/Queue.h"

typedef struct avl_tree avl_tree;

/*
 * 创建一个空树
 */
avl_tree *new_avl_tree(int (*compare)(void *, void *));

/*
 * 判断树是否为空
 */
int avl_tree_empty(avl_tree *avl);

/**
 *  返回树的大小
 */
size_t avl_tree_size(avl_tree *avl);

/*
 * 向树中添加元素
 */
void avl_tree_push(avl_tree *avl, void *val);

/**
 * 判断树中是否含有元素，利用 compare 函数比较，若两元素的 compare 返回值为 0，则判断是该元素
 */
int avl_tree_contain(avl_tree *avl, void *val);


/**
 * 删除树中元素
 */
void avl_tree_reomve(avl_tree *avl, void *val);

/**
 * 打印树的结构
 */
void avl_tree_print(avl_tree *avl, char *(element_to_str)(char s[], const void*));

#endif //DATA_STRUCTURES_avl_tree_H
