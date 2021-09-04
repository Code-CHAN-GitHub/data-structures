//
// Created by chen on 2021/9/4.
//

#ifndef DATA_STRUCTURES_BSTREE_H
#define DATA_STRUCTURES_BSTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct TreeNodeStruct;
typedef struct TreeNodeStruct *TreeNode;

struct BSTreeStruct;
typedef struct BSTreeStruct *BSTree;

/*
 * 返回一个空的二叉查找树
 */
BSTree createBSTree();

/*
 * 判断树是否为空
 */
int bstIsEmpty(BSTree bst);

/*
 * 向树中添加元素
 */
void bstAdd(BSTree bst, ElementType val);

/*
 * 打印树
 */
void printTree(BSTree bst);
#endif //DATA_STRUCTURES_BSTREE_H
