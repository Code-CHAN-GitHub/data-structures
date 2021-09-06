//
// Created by chen on 2021/9/4.
//

#ifndef DATA_STRUCTURES_BSTREE_H
#define DATA_STRUCTURES_BSTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../queue/Queue.h"


typedef struct TreeNode TreeNode;
struct TreeNode {
    void *val;
    TreeNode *left;
    TreeNode *right;
};

typedef struct BSTree BSTree;
struct BSTree {
    int size;
    TreeNode *root;
    int (*compare)(void *, void *);
};

/*
 * 返回一个空的二叉查找树
 */
BSTree *createBSTree(int (*compare)(void *, void *));

/*
 * 判断树是否为空
 */
int bstIsEmpty(BSTree *bst);

/*
 * 向树中添加元素
 */
void bstAdd(BSTree *bst, void *val);

/*
 * 查找树中最小的元素
 */
void *bstFindMin(BSTree *bst);

/*
 * 查找树中最大的元素
 */
void *bstFindMax(BSTree *bst);

/*
 * 删除树中元素
 */
void bstRemove(BSTree *bst, void *val);

#endif //DATA_STRUCTURES_BSTREE_H
