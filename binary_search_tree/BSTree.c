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
    if (root->left == NULL)
        return root->val;
    return __find_min_bs_tree_node(root->left);
}

void *bs_tree_min(binary_search_tree *bs_tree) {
    if (!bs_tree_empty(bs_tree))
        return __find_min_bs_tree_node(bs_tree->root);
    return 0;
}

void *__find_max_bs_tree_node(__bs_tree_node *root) {
    if (root->right == NULL)
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

void bs_treeRemove(binary_search_tree *bs_tree, void *val) {
    __remove_bs_tree_node(bs_tree->root, val, bs_tree->compare);
}

void bs_tree_print(binary_search_tree *bs_tree, char *(element_to_str)(char s[], const void*)) {
    printf("[");
    if (!bs_tree_empty(bs_tree)) {
        queue *queue = new_queue();
        __bs_tree_node *root = bs_tree->root;
        queue_push(queue, root);

        size_t cnt_not_null = 1;
        char *str = malloc(sizeof(char) * 100);
        while (!queue_empty(queue) && cnt_not_null) {
            size_t sz = queue_size(queue);
            for (size_t i = 0; i < sz; i++) {
                __bs_tree_node *node = queue_pop(queue);
                if (!node) {
                    printf("null, ");
                } else {
                    cnt_not_null--;

                    printf("%s, ", element_to_str(str, node->val));
                    queue_push(queue, node->left);
                    queue_push(queue, node->right);
                    cnt_not_null += node->left == NULL ? 0 : 1;
                    cnt_not_null += node->right == NULL ? 0 : 1;
                }
                if (!cnt_not_null)
                    break;
            }
        }
        free(str);
        printf("\b\b");
    }
    printf("]\n");
}
