//
// Created by chen on 2021/9/8.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../map/map.h"

int __str_hash(const void *key) {
    char *s = (char *) key;
    int h = 0;
    while (*s != '\0') {
        h = 31 * h + *s++;
    }
    return h;
}

int __str_equals(const void *s1, const void *s2) {
    return strcmp(s1, s2) == 0;
}

void __test_new_map() {
    map *map = new_map(__str_hash, __str_equals);
    if (map)
        printf("map address ==> %p", map);
}

char *__void_to_str(char *s, const void *p) {
    return strcpy(s, p);
}

void __test_map_put() {
    map *map = new_map(__str_hash, __str_equals);
    map_print(map, __void_to_str, __void_to_str);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                char *key = malloc(sizeof(char) * 10);
                char *value = malloc(sizeof(char) * 10);
                key[0] = 'k', key[1] = (char) ('0' + i);
                key[2] = (char) ('0' + j);
                key[3] = (char) ('0' + k);
                key[4] = '\0';
                value[0] = 'v';
                value[1] = (char) ('0' + i);
                value[2] = (char) ('0' + j);
                value[3] = (char) ('0' + k);
                value[4] = '\0';
                map_put(map, key, value);
            }
        }
    }

    srand((unsigned )time(NULL));
    for (int i = 0; i < 10000; i++) {
        int x = rand() % 1000;
        int a = x / 100;
        int b = (x % 100) / 10;
        int c = x % 10;
        char key[10] = {'k', (char)('0' + a), (char)('0' + b), (char)('0' + c)};
        printf("get key = %s ==> value = %s\n", key, (char *) map_get(map, key));
        map_remove(map, key);
    }

    map_print(map, __void_to_str, __void_to_str);
}

//int main() {
////    __test_new_map();
//    __test_map_put();
//}