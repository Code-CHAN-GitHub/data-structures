//
// Created by chen on 2021/9/4.
//

#include "Integer.h"

Integer *int2Integer(int val) {
    Integer *item = malloc(sizeof(int));
    item->val = val;
    return item;
}

int voidPoint2int(void *item) {
    assert(item);
    return ((Integer *) item)->val;
}

int integerCompare(void *item1, void *item2) {
    return voidPoint2int(item1) - voidPoint2int(item2);
}