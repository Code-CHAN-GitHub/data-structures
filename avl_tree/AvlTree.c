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

