//
// Created by chen on 2021/9/4.
//

#ifndef DATA_STRUCTURES_AVLTREE_H
#define DATA_STRUCTURES_AVLTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;

struct AvlTreeNodeStruct;
typedef struct AvlTreeNodeStruct *AvlTreeNode;

struct AvlTreeStruct;
typedef struct AvlTreeStruct *AvlTree;

/*
 * 创建一个空树
 */
AvlTree createAvlTree();

/*
 * 判断树是否为空
 */
int avlIsEmpty(AvlTree avl);

#endif //DATA_STRUCTURES_AVLTREE_H
