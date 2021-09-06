//
// Created by chen on 2021/9/4.
//

#ifndef DATA_STRUCTURES_AVLTREE_H
#define DATA_STRUCTURES_AVLTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../util/Math.h"

typedef struct AvlTreeNode AvlTreeNode;
struct AvlTreeNode {
    void *val;
    AvlTreeNode *left;
    AvlTreeNode *right;
    int height;
};

struct AvlTree {
    int size;
    AvlTreeNode* root;
    int (*compare)(void *, void *);
};

typedef struct AvlTree AvlTree;

/*
 * 创建一个空树
 */
AvlTree *createAvlTree(int (*compare)(void *, void *));

/*
 * 判断树是否为空
 */
int avlIsEmpty(AvlTree *avl);

/*
 * 向树中添加元素
 */
void avlAdd(AvlTree *avl, void *val);

/*
 * 打印树
 */
void printAvl(AvlTree avl);
#endif //DATA_STRUCTURES_AVLTREE_H
