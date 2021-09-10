
#include "map.h"

typedef struct __map_node __map_node;

struct __map_node {
    int hash;
    void *key;
    void *value;
    __map_node *next;
};

struct map {
    size_t size;
    size_t capacity;
    size_t threshold;
    __map_node **tab;
    int (*hash)(const void *key);
    int (*equals)(const void *, const void *);
};

size_t __DEFAUT_TAB_CAPACITY = 16;
double __DEFAULT_LOAD_FACTOR = 0.75;

/**
 * 对 tab 进行扩容，扩容后的容量为原来的二倍，并修改 map->capacity 为新的容量，
 * 重新计算阀值 threshold = load_factor * capacity
 * @param map
 * @return 扩容后的 tab
 */
__map_node **__map_resize(map *map);

__map_node *__new_map_node(int hash, void *key, void *value, __map_node *next) {
    __map_node *node = malloc(sizeof(__map_node));
    node->hash = hash;
    node->key = key;
    node->value = value;
    node->next = next;
    return node;
}

map *new_map(int (*hash)(const void *), int (*equals)(const void *, const void *)) {
    map *map = malloc(sizeof(struct map));
    map->size = 0;
    map->capacity = 0;
    map->hash = hash;
    map->equals = equals;
    map->tab = NULL;
    return map;
}

int map_empty(map *map) {
    assert(map);
    return map->size == 0;
}

size_t map_size(map *map) {
    assert(map);
    return map->size;
}

void map_put(map *map, void *key, void *value) {
    assert(map && key);
    if (map->tab == NULL || map->capacity == 0)
        map->tab = __map_resize(map);
    int hash = map->hash(key);
    size_t i;
    if (map->tab[i = (hash & (map->capacity - 1))] == NULL)
        map->tab[i] = __new_map_node(hash, key, value, NULL);
    else {
        __map_node *node = map->tab[i];
        while (node != NULL) {
            if (hash == node->hash && (key == node->key || map->equals(key, node->key))) {
                node->value = value;
                break;
            } else if (node->next == NULL) {
                node->next = __new_map_node(hash, key, value, NULL);
            }
            node = node->next;
        }
    }
    if (++map->size > map->threshold)
        map->tab = __map_resize(map);
}

__map_node **__map_resize(map *map) {
    size_t old_cap = map->capacity;
    size_t new_cap;
    if (old_cap == 0)
        new_cap = __DEFAUT_TAB_CAPACITY;
    else
        new_cap = old_cap << 1;
    map->threshold = (size_t) (__DEFAULT_LOAD_FACTOR * (int) new_cap);
    __map_node **old_tab = map->tab;
    __map_node **new_tab = malloc(sizeof(__map_node *) * new_cap);
    map->tab = new_tab;
    map->capacity = new_cap;
    for (size_t i = 0; i < new_cap; i++)
        map->tab[i] = NULL;
    if (old_cap > 0) {
        for (size_t i = 0; i < old_cap; i++) {
            __map_node *node;
            if ((node = old_tab[i]) != NULL) {
                old_tab[i] = NULL;
                if (node->next == NULL)
                    new_tab[node->hash & (new_cap - 1)] = node;
                else {
                    __map_node *lo_head = NULL, *lo_tail = NULL;
                    __map_node *hi_head = NULL, *hi_tail = NULL;
                    __map_node *next;
                    do {
                        next = node->next;
                        if ((node->hash & old_cap) == 0) {
                            if (lo_tail == NULL)
                                lo_head = node;
                            else
                                lo_tail->next = node;
                            lo_tail = node;
                        } else {
                            if (hi_tail == NULL)
                                hi_head = node;
                            else
                                hi_tail->next = node;
                            hi_tail = node;
                        }
                    } while ((node = next) != NULL);

                    if (lo_tail != NULL) {
                        lo_tail->next =  NULL;
                        new_tab[i] = lo_head;
                    }
                    if (hi_tail != NULL) {
                        hi_tail->next = NULL;
                        new_tab[i + old_cap] = hi_head;
                    }
                }
            }
        }
    }
    free(old_tab);
    return new_tab;
}

void *map_get(map *map, void *key) {
    if (!map_empty(map)) {
        size_t i;
        int hash = map->hash(key);
        if (map->tab[i = (hash & (map->capacity - 1))] != NULL) {
            __map_node *node = map->tab[i];
            while (node) {
                if (hash == node->hash && (key == node->key || map->equals(key, node->key)))
                    return node->value;
                node = node->next;
            }
        }
    }
    return NULL;
}

void map_print(map *map, char *(key_to_string)(char *, const void *), char *(value_to_string)(char *, const void *)) {
    for (size_t i = 0; i < map->capacity; i++) {
        printf("%4zu : ", i);
        if (map->tab[i] == NULL)
            printf("null\n");
        else {
            __map_node *node = map->tab[i];
            char key_tmp[100];
            char value_tmp[100];
            printf("[%s, %s]", key_to_string(key_tmp, node->key), value_to_string(value_tmp, node->value));
            while ((node = node->next)) {
                printf(" -> [%s, %s]", key_to_string(key_tmp, node->key), value_to_string(value_tmp, node->value));
            }
            printf("\n");
        }
    }
}