//
// Created by chen on 2021/9/8.
//

#include "map.h"

typedef struct __map_node __map_node;
typedef struct __map_tab __map_tab;


struct __map_node {
    const int hash;
    const void *key;
    void *value;
    __map_node *next;
};

struct map {
    size_t size;
    size_t capacity;
    __map_node **tab;
    int (*hash)(const void *key);
};

size_t __DEFAUT_TAB_CAPACITY = 16;

map *new_map(int (*hash)(const void *)) {
    map *map = malloc(sizeof(struct map));
    map->size = 0;
    map->capacity = 0;
    map->hash = hash;
    return map;
}
