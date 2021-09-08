//
// Created by chen on 2021/9/4.
//

#include "AvlTree.h"

#define __max(x, y) ((x > y) ? (x) : (y))

typedef struct __avl_tree_node __avl_tree_node;
struct __avl_tree_node {
    void *val;
    __avl_tree_node *left;
    __avl_tree_node *right;
    int height;
};

struct avl_tree {
    size_t size;
    __avl_tree_node* root;
    int (*compare)(void *, void *);
};

avl_tree *new_avl_tree(int (*compare)(void *, void *)) {
    avl_tree *avl_tree = malloc(sizeof(struct avl_tree));
    avl_tree->size = 0;
    avl_tree->root = NULL;
    avl_tree->compare = compare;
    return avl_tree;
}

__avl_tree_node *new_avl_tree_node(void *val) {
    __avl_tree_node *node = (__avl_tree_node *) malloc(sizeof(__avl_tree_node));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int avl_tree_empty(avl_tree *avl) {
    assert(avl);
    return avl->size == 0;
}

size_t avl_tree_size(avl_tree *avl) {
    assert(avl);
    return avl->size;
}

int __avl_tree_node_height(__avl_tree_node *node) {
    return node == NULL ? -1 : node->height;
}

__avl_tree_node *__single_rotate_with_left(__avl_tree_node *k2) {
    __avl_tree_node *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = __max(__avl_tree_node_height(k2->left), __avl_tree_node_height(k2->right)) + 1;
    k1->height = __max(__avl_tree_node_height(k1->left), k2->height) + 1;
    return k1;
}

__avl_tree_node *__single_rotate_with_right(__avl_tree_node *k2) {
    __avl_tree_node *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = __max(__avl_tree_node_height(k2->left), __avl_tree_node_height(k2->right)) + 1;
    k1->height = __max(__avl_tree_node_height(k1->left), k2->height) + 1;
    return k1;
}

__avl_tree_node *__double_rotate_with_left(__avl_tree_node *k3) {
    k3->left = __single_rotate_with_right(k3->left);
    return __single_rotate_with_left(k3);
}

__avl_tree_node *__double_rotate_with_right(__avl_tree_node *k3) {
    k3->right = __single_rotate_with_left(k3->right);
    return __single_rotate_with_right(k3);
}

__avl_tree_node *__avl_tree_push_node(__avl_tree_node *root, void *val, int (*compare)(void *, void *), avl_tree *avl) {
    if (root == NULL) {
        root = new_avl_tree_node(val);
        avl->size++;
    } else if (compare(val, root->val) < 0) {
        root->left = __avl_tree_push_node(root->left, val, compare, avl);
        if (__avl_tree_node_height(root->left) - __avl_tree_node_height(root->right) > 1) {
            if (compare(val, root->left->val) < 0)
                root = __single_rotate_with_left(root);
            else
                root = __double_rotate_with_left(root);
        }
    } else if (compare(val, root->val) > 0) {
        root->right = __avl_tree_push_node(root->right, val, compare, avl);
        if (__avl_tree_node_height(root->right) - __avl_tree_node_height(root->left) > 1) {
            if (compare(val, root->right->val) > 0)
                root = __single_rotate_with_right(root);
            else
                root = __double_rotate_with_right(root);
        }
    }
    root->height = __max(__avl_tree_node_height(root->left), __avl_tree_node_height(root->right)) + 1;
    return root;
}

void avl_tree_push(avl_tree *avl, void *val) {
    assert(avl);
    avl->root = __avl_tree_push_node(avl->root, val, avl->compare, avl);
}

__avl_tree_node *__find_avl_tree_node(__avl_tree_node *root, void *val, int (*compare)(const void *, const void *)) {
    if (root == NULL)
        return root;
    else if (compare(val, root->val) < 0)
        return __find_avl_tree_node(root->left, val, compare);
    else if (compare(val, root->val) > 0)
        return __find_avl_tree_node(root->right, val, compare);
    return root;
}

int avl_tree_contain(avl_tree *avl, void *val) {
    if (!avl_tree_empty(avl))
        return __find_avl_tree_node(avl->root, val, avl->compare) != NULL;
    return 0;
}

__avl_tree_node *__avl_tree_min_node(__avl_tree_node *root) {
    if (root == NULL || root->left == NULL)
        return root;
    return __avl_tree_min_node(root->left);
}

__avl_tree_node *__avl_tree_remove_node(__avl_tree_node *root, void *val, int (*compare)(const void *, const void *)) {
    if (root == NULL)
        return root;
    else if (compare(val, root->val) < 0)
        root->left = __avl_tree_remove_node(root->left, val, compare);
    else if (compare(val, root->val) > 0)
        root->right = __avl_tree_remove_node(root->right, val, compare);
    else if (root->left && root->right) {
        root->val = __avl_tree_min_node(root->right)->val;
        root->right = __avl_tree_remove_node(root->right, root->val, compare);
    } else {
        __avl_tree_node *tmp = root;
        if (tmp->left == NULL)
            root = root->right;
        else
            root = root->left;
        free(tmp);
    }
    if (root != NULL)
        root->height = __max(__avl_tree_node_height(root->left), __avl_tree_node_height(root->right)) + 1;
    return root;
}

void avl_tree_reomve(avl_tree *avl, void *val) {
    if (!avl_tree_empty(avl))
        avl->root = __avl_tree_remove_node(avl->root, val, avl->compare);
}

void __avl_tree_pretty_print_dfs(__avl_tree_node *node, char *prefix, int is_left, char *(to_string)(char s[], const void*)) {
    if (node == NULL) {
        printf("Empty tree\n");
        return;
    }

    if (node->right != NULL) {
        char tmp[1000];
        strcpy(tmp, prefix);
        __avl_tree_pretty_print_dfs(node->right, strcat(tmp, (is_left ? "│   " : "    ")), 0, to_string);
    }

    char tmp[1000];
    strcpy(tmp, prefix);
    char tmp2[100] = {'\0'};
    printf("%s\n", strcat(strcat(tmp, (is_left ? "└── " : "┌── ")) , to_string(tmp2, node->val)));

    if (node->left != NULL) {
        char tmp2[1000];
        strcpy(tmp2, prefix);
        __avl_tree_pretty_print_dfs(node->left, strcat(tmp2, (is_left ? "    " : "│   ")), 1, to_string);
    }
}

void __avl_tree_pretty_print(__avl_tree_node *node, char *(to_string)(char s[], const void*)) {
    char prefix[1000] = {'\0'};
    __avl_tree_pretty_print_dfs(node,  prefix, 1, to_string);
}

void avl_tree_print(avl_tree *avl, char *(to_string)(char s[], const void*)) {
    __avl_tree_pretty_print(avl->root, to_string);
}