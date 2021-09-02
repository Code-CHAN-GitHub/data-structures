//
// Created by chen on 2021/9/2.
//

#ifndef DATA_STRUCTURES_VECTOR_H
#define DATA_STRUCTURES_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct VectorStruct;
typedef struct VectorStruct *Vector;

Vector createVector();
Vector createVectorByInitCapacity(int initialCapacity);

void vectorAdd(Vector vec, ElementType val);
void vectorAddByIndex(Vector vec, ElementType val, int index);

ElementType vectorGet(Vector vec, int index);

ElementType vectorRemove(Vector vec, int index);

void vectorSet(Vector vec, ElementType val, int index);

void printVector(Vector vec);

#endif //DATA_STRUCTURES_VECTOR_H
