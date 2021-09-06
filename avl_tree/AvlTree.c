//
// Created by chen on 2021/9/4.
//

#include "AvlTree.h"

//typedef struct AvlTreeNode AvlTreeNode;
//struct AvlTreeNode {
//    void *val;
//    AvlTreeNode *left;
//    AvlTreeNode *right;
//    int height;
//};
//
//struct AvlTree {
//    int size;
//    AvlTreeNode* root;
//    int (*compare)(void *, void *);
//};

AvlTree *createAvlTree(int (*compare)(void *, void *)) {
    AvlTree *avlTree = (AvlTree *) malloc(sizeof(AvlTree));
    avlTree->size = 0;
    avlTree->root = NULL;
    avlTree->compare = compare;
    return avlTree;
}

AvlTreeNode *createAvlTreeNode(void *val) {
    AvlTreeNode *node = (AvlTreeNode *) malloc(sizeof(AvlTreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int avlIsEmpty(AvlTree *avl) {
    assert(avl);
    return avl->root != NULL;
}

int avlNodeHeight(AvlTreeNode *node) {
    return node == NULL ? -1 : node->height;
}

AvlTreeNode *singleRotateWithLeft(AvlTreeNode *k2) {
    AvlTreeNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(avlNodeHeight(k2->left), avlNodeHeight(k2->right)) + 1;
    k1->height = max(avlNodeHeight(k1->left), k2->height) + 1;
    return k1;
}

AvlTreeNode *singleRotateWithRight(AvlTreeNode *k2) {
    AvlTreeNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(avlNodeHeight(k2->left), avlNodeHeight(k2->right)) + 1;
    k1->height = max(avlNodeHeight(k1->left), k2->height) + 1;
    return k1;
}

AvlTreeNode *doubleRotateWithLeft(AvlTreeNode *k3) {
    k3->left = singleRotateWithRight(k3->left);
    return singleRotateWithLeft(k3);
}

AvlTreeNode *doubleRotateWithRight(AvlTreeNode *k3) {
    k3->right = singleRotateWithLeft(k3->right);
    return singleRotateWithRight(k3);
}

AvlTreeNode *avlNodeAdd(AvlTreeNode *root, void *val, int (*compare)(void *, void *)) {
    if (root == NULL) {
        root = createAvlTreeNode(val);
    } else if (compare(val, root->val) < 0) {
        root->left = avlNodeAdd(root->left, val, compare);
        if (avlNodeHeight(root->left) - avlNodeHeight(root->right) > 1) {
            if (compare(val, root->left->val) < 0)
                root = singleRotateWithLeft(root);
            else
                root = doubleRotateWithLeft(root);
        }
    } else if (compare(val, root->val) > 0) {
        root->right = avlNodeAdd(root->right, val, compare);
        if (avlNodeHeight(root->right) - avlNodeHeight(root->left) > 1) {
            if (compare(val, root->right->val) > 0)
                root = singleRotateWithRight(root);
            else
                root = doubleRotateWithRight(root);
        }
    }
    root->height = max(avlNodeHeight(root->left), avlNodeHeight(root->right)) + 1;
    return root;
}

void avlAdd(AvlTree *avl, void *val) {
    assert(avl);
    avl->root = avlNodeAdd(avl->root, val, avl->compare);
}
