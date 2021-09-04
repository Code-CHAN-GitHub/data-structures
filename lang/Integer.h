//
// Created by chen on 2021/9/4.
//

#ifndef DATA_STRUCTURES_INTEGER_H
#define DATA_STRUCTURES_INTEGER_H

#include <stdlib.h>
#include <assert.h>

typedef struct Integer {
    int val;
} Integer;

Integer *int2Integer(int val);

int voidPoint2int(void *);

int integerCompare(void *item1, void *item2);

#endif //DATA_STRUCTURES_INTEGER_H
