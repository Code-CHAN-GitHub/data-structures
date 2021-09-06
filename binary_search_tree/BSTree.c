//
// Created by chen on 2021/9/4.
//

#include "BSTree.h"

//typedef struct TreeNode TreeNode;
//struct TreeNode {
//    void *val;
//    TreeNode *left;
//    TreeNode *right;
//};

//struct BSTree {
//    int size;
//    TreeNode *root;
//    int (*compare)(void *, void *);
//};

TreeNode *createTreeNode(void *val) {
    TreeNode *node = (TreeNode *) malloc(sizeof (TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BSTree *createBSTree(int (*compare)(void *, void *)) {
    BSTree *bst = (BSTree *) malloc(sizeof (BSTree));
    bst->size = 0;
    bst->root = NULL;
    bst->compare = compare;
    return bst;
}

int bstIsEmpty(BSTree *bst) {
    assert(bst);
    return bst->size == 0;
}

TreeNode *insertNode(TreeNode *root, void *val, int (*compare)(void *, void *)) {
    if (root == NULL)
        root = createTreeNode(val);
    else if (compare(val, root->val) < 0)
        root->left = insertNode(root->left, val, compare);
    else if (compare(val, root->val) > 0)
        root->right = insertNode(root->right, val, compare);
    return root;
}

void bstAdd(BSTree *bst, void *val) {
    bst->root = insertNode(bst->root, val, bst->compare);
    bst->size++;
}

void *findMinNode(TreeNode *root) {
    if (root->left == NULL)
        return root->val;
    return findMinNode(root->left);
}

void *bstFindMin(BSTree *bst) {
    if (!bstIsEmpty(bst))
        return findMinNode(bst->root);
    return 0;
}

void *findMaxNode(TreeNode *root) {
    if (root->right == NULL)
        return root->val;
    return findMaxNode(root->right);
}

void *bstFindMax(BSTree *bst) {
    if (!bstIsEmpty(bst))
        return findMaxNode(bst->root);
    return 0;
}

TreeNode *removeNode(TreeNode *root, void *val, int (*compare)(void *, void *)) {
    if (root == NULL)
        return root;
    else if (compare(val, root->val) < 0)
        root->left = removeNode(root->left, val, compare);
    else if (compare(val, root->val) > 0)
        root->right = removeNode(root->right, val, compare);
    else if (root->left && root->right) {
        root->val = findMinNode(root->right);
        root->right = removeNode(root->right, root->val, compare);
    } else {
        TreeNode *tmp = root;
        if (root->left == NULL)
            root = root->right;
        else
            root = root->left;
        free(tmp);
    }
    return root;
}

void bstRemove(BSTree *bst, void *val) {
    removeNode(bst->root, val, bst->compare);
}
