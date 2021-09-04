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

AvlTreeNode createAvlTreeNode(ElementType val) {
    AvlTreeNode node = (AvlTreeNode) malloc(sizeof(struct AvlTreeNodeStruct));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int avlIsEmpty(AvlTree avl) {
    assert(avl);
    return avl->size == 0;
}

int avlNodeHeight(AvlTreeNode node) {
    return node == NULL ? -1 : node->height;
}

AvlTreeNode singleRotateWithLeft(AvlTreeNode k2) {
    AvlTreeNode k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(avlNodeHeight(k2->left), avlNodeHeight(k2->right)) + 1;
    k1->height = max(avlNodeHeight(k1->left), avlNodeHeight(k2)) + 1;
    return k1;
}

AvlTreeNode singleRotateWithRight(AvlTreeNode k2) {
    AvlTreeNode k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(avlNodeHeight(k2->left), avlNodeHeight(k2->right)) + 1;
    k1->height = max(avlNodeHeight(k1->left), avlNodeHeight(k2)) + 1;
    return k1;
}

AvlTreeNode doubleRotateWithLeft(AvlTreeNode k3) {
    k3->left = singleRotateWithRight(k3->left);
    return singleRotateWithLeft(k3);
}

AvlTreeNode doubleRotateWithRight(AvlTreeNode k3) {
    k3->right = singleRotateWithLeft(k3->right);
    return singleRotateWithRight(k3);
}

AvlTreeNode avlNodeAdd(AvlTreeNode root, ElementType val) {
    if (root == NULL) {
        root = createAvlTreeNode(val);
    } else if (val < root->val) {
        root->left = avlNodeAdd(root->left, val);
        if (avlNodeHeight(root->left) - avlNodeHeight(root->right) > 1) {
            if (val < root->left->val)
                root = singleRotateWithLeft(root);
            else
                root = doubleRotateWithLeft(root);
        }
    } else if (val > root->val) {
        root->right = avlNodeAdd(root->right, val);
        if (avlNodeHeight(root->right) - avlNodeHeight(root->left) > 1) {
            if (val > root->right->val)
                root = singleRotateWithRight(root);
            else
                root = doubleRotateWithRight(root);
        }
    }
    root->height = max(avlNodeHeight(root->left), avlNodeHeight(root->right)) + 1;
    return root;
}

void avlAdd(AvlTree avl, ElementType val) {
    assert(avl);
    avl->root = avlNodeAdd(avl->root, val);
}

void dfs(AvlTreeNode root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    dfs(root->left);
    dfs(root->right);
}

void printAvl(AvlTree avl) {
    assert(avl);
    dfs(avl->root);
}