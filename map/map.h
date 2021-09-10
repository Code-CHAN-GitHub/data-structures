/**
 * map 哈希表
 */

#ifndef DATA_STRUCTURES_MAP_H
#define DATA_STRUCTURES_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct map map;

/**
 * 创建一个空的哈希表
 * @param hash 计算 key 的 hash 函数
 * @param equals 比较 key 是否相等的函数
 * @return hash_map
 */
map *new_map(int (*hash)(const void *), int (*equals)(const void *, const void *)) ;

/*
 * 判读哈希表是否为空
 */
int map_empty(map *map);

/*
 * 返回哈希表的大小
 */
size_t map_size(map *map);

/*
 * 将 <key,value> 放入表中
 */
void map_put(map *map, void *key, void *value);

/*
 * 根据 key 获取 value，若 key 不存在则返回 NULL
 */
void *map_get(map *map, void *key);

void map_remove(map *map, void *key);

/**
 * 打印表结构
 * @param map
 * @param key_to_string 将 key 转为字符串
 * @param value_to_string 将 value 转为字符串
 */
void map_print(map *map, char *(key_to_string)(char *, const void *), char *(value_to_string)(char *, const void *));

#endif //DATA_STRUCTURES_MAP_H
