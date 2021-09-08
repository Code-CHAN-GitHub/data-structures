//
// Created by chen on 2021/9/4.
//

#include "BSTree.h"

typedef struct __bs_tree_node __bs_tree_node;
struct __bs_tree_node {
    void *val;
    __bs_tree_node *left;
    __bs_tree_node *right;
};

struct binary_search_tree {
    int size;
    __bs_tree_node *root;
    int (*compare)(void *, void *);
};

__bs_tree_node *__new__bs_tree_node(void *val) {
    __bs_tree_node *node = (__bs_tree_node *) malloc(sizeof (__bs_tree_node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

binary_search_tree *new_bs_tree(int (*compare)(void *, void *)) {
    binary_search_tree *bs_tree = (binary_search_tree *) malloc(sizeof (binary_search_tree));
    bs_tree->size = 0;
    bs_tree->root = NULL;
    bs_tree->compare = compare;
    return bs_tree;
}

int bs_tree_empty(binary_search_tree *bs_tree) {
    assert(bs_tree);
    return bs_tree->size == 0;
}

__bs_tree_node *__insert_bs_tree_node(__bs_tree_node *root, void *val, int (*compare)(void *, void *)) {
    if (root == NULL)
        root = __new__bs_tree_node(val);
    else if (compare(val, root->val) < 0)
        root->left = __insert_bs_tree_node(root->left, val, compare);
    else if (compare(val, root->val) > 0)
        root->right = __insert_bs_tree_node(root->right, val, compare);
    return root;
}

void bs_tree_push(binary_search_tree *bs_tree, void *val) {
    assert(bs_tree);
    bs_tree->root = __insert_bs_tree_node(bs_tree->root, val, bs_tree->compare);
    bs_tree->size++;
}

void *__find_min_bs_tree_node(__bs_tree_node *root) {
    if (root == NULL || root->left == NULL)
        return root->val;
    return __find_min_bs_tree_node(root->left);
}

void *bs_tree_min(binary_search_tree *bs_tree) {
    if (!bs_tree_empty(bs_tree))
        return __find_min_bs_tree_node(bs_tree->root);
    return 0;
}

void *__find_max_bs_tree_node(__bs_tree_node *root) {
    if (root == NULL || root->right == NULL)
        return root->val;
    return __find_max_bs_tree_node(root->right);
}

void *bs_tree_max(binary_search_tree *bs_tree) {
    if (!bs_tree_empty(bs_tree))
        return __find_max_bs_tree_node(bs_tree->root);
    return 0;
}

__bs_tree_node *__remove_bs_tree_node(__bs_tree_node *root, void *val, int (*compare)(void *, void *)) {
    if (root == NULL)
        return root;
    else if (compare(val, root->val) < 0)
        root->left = __remove_bs_tree_node(root->left, val, compare);
    else if (compare(val, root->val) > 0)
        root->right = __remove_bs_tree_node(root->right, val, compare);
    else if (root->left && root->right) {
        root->val = __find_min_bs_tree_node(root->right);
        root->right = __remove_bs_tree_node(root->right, root->val, compare);
    } else {
        __bs_tree_node *tmp = root;
        if (root->left == NULL)
            root = root->right;
        else
            root = root->left;
        free(tmp);
    }
    return root;
}

__bs_tree_node *__find_bs_tree_node(__bs_tree_node *root, void *val, int (*compare)(const void *, const void *)) {
    if (root == NULL)
        return 0;
    else if (compare(val, root->val) < 0)
        return __find_bs_tree_node(root->left, val, compare);
    else if (compare(val, root->val) > 0)
        return __find_bs_tree_node(root->right, val, compare);
    else
        return root;
}

int bs_tree_contain(binary_search_tree *bs_tree, void *val) {
    if (!bs_tree_empty(bs_tree))
        return __find_bs_tree_node(bs_tree->root, val, bs_tree->compare) != NULL;
    return 0;
}

void bs_tree_remove(binary_search_tree *bs_tree, void *val) {
    if (!bs_tree_empty(bs_tree))
        bs_tree->root = __remove_bs_tree_node(bs_tree->root, val, bs_tree->compare);
}


void __bs_tree_pretty_print_dfs(__bs_tree_node *node, char *prefix, int is_left, char *(to_string)(char s[], const void*)) {
    if (node == NULL) {
        printf("Empty tree\n");
        return;
    }

    if (node->right != NULL) {
        char tmp[1000];
        strcpy(tmp, prefix);
        __bs_tree_pretty_print_dfs(node->right, strcat(tmp, (is_left ? "│   " : "    ")), 0, to_string);
    }

    char tmp[1000];
    strcpy(tmp, prefix);
    char tmp2[100] = {'\0'};
    printf("%s\n", strcat(strcat(tmp, (is_left ? "└── " : "┌── ")) , to_string(tmp2, node->val)));

    if (node->left != NULL) {
        char tmp2[1000];
        strcpy(tmp2, prefix);
        __bs_tree_pretty_print_dfs(node->left, strcat(tmp2, (is_left ? "    " : "│   ")), 1, to_string);
    }
}

void __bs_tree_pretty_print(__bs_tree_node *node, char *(to_string)(char s[], const void*)) {
    char prefix[1000] = {'\0'};
    __bs_tree_pretty_print_dfs(node,  prefix, 1, to_string);
}

void bs_tree_print(binary_search_tree *bs_tree, char *(to_string)(char s[], const void*)) {
    __bs_tree_pretty_print(bs_tree->root, to_string);
}
