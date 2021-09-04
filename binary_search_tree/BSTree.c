//
// Created by chen on 2021/9/4.
//

#include "BSTree.h"

struct TreeNodeStruct {
    ElementType val;
    TreeNode left;
    TreeNode right;
};

struct BSTreeStruct {
    int size;
    TreeNode root;
};

TreeNode createTreeNode(ElementType val) {
    TreeNode node = (TreeNode) malloc(sizeof (struct TreeNodeStruct));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BSTree createBSTree() {
    BSTree bst = (BSTree) malloc(sizeof (struct BSTreeStruct));
    bst->size = 0;
    bst->root = NULL;
    return bst;
}

int bstIsEmpty(BSTree bst) {
    return bst->size == 0;
}

TreeNode insertNode(TreeNode root, ElementType val) {
    if (root == NULL)
        root = createTreeNode(val);
    else if (val < root->val)
        root->left = insertNode(root->left, val);
    else if (val > root->val)
        root->right = insertNode(root->right, val);
    return root;
}

void bstAdd(BSTree bst, ElementType val) {
    bst->root = insertNode(bst->root, val);
}

void printPreTree(TreeNode root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    printPreTree(root->left);
    printPreTree(root->right);
}

void printTree(BSTree bst) {
    printPreTree(bst->root);
}
