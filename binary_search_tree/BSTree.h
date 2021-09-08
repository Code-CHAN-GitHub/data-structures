//
// Created by chen on 2021/9/4.
//

#ifndef DATA_STRUCTURES_BSTREE_H
#define DATA_STRUCTURES_BSTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../queue/Queue.h"

typedef struct binary_search_tree binary_search_tree;

/*
 * 返回一个空的二叉查找树
 */
binary_search_tree *new_bs_tree(int (*compare)(void *, void *));

/*
 * 判断树是否为空
 */
int bs_tree_empty(binary_search_tree *bs_tree);

/*
 * 向树中添加元素
 */
void bs_tree_push(binary_search_tree *bs_tree, void *val);

/*
 * 查找树中最小的元素
 */
void *bs_tree_min(binary_search_tree *bs_tree);

/*
 * 查找树中最大的元素
 */
void *bs_tree_max(binary_search_tree *bs_tree);

/**
 * 判断树中是否含有元素，利用 compare 函数比较，若两元素的 compare 返回值为 0，则判断是该元素
 */
int bs_tree_contain(binary_search_tree *bs_tree, void *val);

/*
 * 删除树中元素
 */
void bs_tree_remove(binary_search_tree *bs_tree, void *val);

/**
 * 打印树结构
 */
void bs_tree_print(binary_search_tree *bs_tree, char *(element_to_str)(char s[], const void*));

#endif //DATA_STRUCTURES_BSTREE_H
