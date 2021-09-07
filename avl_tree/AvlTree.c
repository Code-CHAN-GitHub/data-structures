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


void avl_tree_print(avl_tree *avl, char *(element_to_str)(char s[], const void*)) {
    printf("[");
    if (!avl_tree_empty(avl)) {
        queue *queue = new_queue();
        __avl_tree_node *root = avl->root;
        queue_push(queue, root);

        size_t cnt_not_null = 1;
        char *str = malloc(sizeof(char) * 100);
        while (!queue_empty(queue) && cnt_not_null) {
            size_t sz = queue_size(queue);
            for (size_t i = 0; i < sz; i++) {
                __avl_tree_node *node = queue_pop(queue);
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