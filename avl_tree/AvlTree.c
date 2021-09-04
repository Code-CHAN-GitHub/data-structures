//
// Created by chen on 2021/9/4.
//

#include "AvlTree.h"

struct AvlTreeNodeStruct {
    ElementType val;
    AvlTreeNode left;
    AvlTreeNode right;
    int height;
};

struct AvlTreeStruct {
    int size;
    AvlTreeNode root;
};

AvlTree createAvlTree() {
    AvlTree avlTree = (AvlTree) malloc(sizeof(struct AvlTreeStruct));
    avlTree->size = 0;
    avlTree->root = NULL;
    return avlTree;
}

int avlIsEmpty(AvlTree avl) {
    assert(avl);
    return avl->size == 0;
}

