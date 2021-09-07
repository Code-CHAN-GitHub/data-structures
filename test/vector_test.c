//
// Created by chen on 2021/9/7.
//

#include <stdio.h>
#include "../vector/Vector.h"

void __test_new_vector() {
    vector *vec = new_vector();
    if (vec)
        printf("vector address ==> %p", vec);
}

vector *__create_vector(int start, int end) {
    vector *vec = new_vector();
    for (int i = start; i <= end; i++) {
        int *x = malloc(sizeof(int));
        *x = i;
        vector_push_back(vec, x);
    }
    return vec;
}

void __print_vector(vector *vec) {
    size_t sz = vector_size(vec);
    for (size_t i = 0; i < sz; i++) {
        printf("%d ", *(int *)vector_get(vec, i));
    }
    printf("\n");
}

void __test_vector_push() {
    vector *vec = __create_vector(0, 10);
    printf("push back [0, 10] ==> ");
    __print_vector(vec);

    printf("push front [0, 10] ==> ");
    for (int i = 0; i <= 10; i++) {
        int *x = malloc(sizeof(int));
        *x = i;
        vector_push_front(vec,x);
    }
    __print_vector(vec);
}

void __test_vector_insert() {
    vector *vec = __create_vector(0, 10000000);
    __print_vector(vec);

    int *x = malloc(sizeof(int));
    *x = 100;
    printf("insert index = %zu, x = %d ==> ", 0, *x);
    vector_insert(vec, 0, x);
    __print_vector(vec);

    int *y = malloc(sizeof(int));
    *y = 200;
    printf("insert index = %zu, y = %d ==> ", 3, *y);
    vector_insert(vec, 3, y);
    __print_vector(vec);

    int *z = malloc(sizeof(int));
    *z = 300;
    printf("insert index = %zu, z = %d ==> ", vector_size(vec) - 1, *z);
    vector_insert(vec, vector_size(vec), z);
    __print_vector(vec);
}

void __test_vector_pop() {
    vector *vec = __create_vector(0, 10);
    __print_vector(vec);

    printf("pop back ==> ");
    while (!vector_empty(vec)) {
        printf("%d ", *(int *) vector_pop_back(vec));
    }
    printf("\n");

    vec = __create_vector(0, 10);

    printf("pop front ==> ");
    while (!vector_empty(vec)) {
        printf("%d ", *(int *) vector_pop_front(vec));
    }
}

void __test_vector_remove() {
    vector *vec = __create_vector(0, 10);
    __print_vector(vec);

    printf("remove index = %d ==> ", 0);
    vector_remove(vec, 0);
    __print_vector(vec);

    printf("remove index = %d ==> ", 9);
    vector_remove(vec, 9);
    __print_vector(vec);

    printf("remove index = %d ==> ", 3);
    vector_remove(vec, 3);
    __print_vector(vec);
}

void __test_vector_set() {
    vector *vec = __create_vector(0, 10);
    __print_vector(vec);

    int *x = malloc(sizeof(int));
    *x = 100;
    printf("set index = %d x = %d ==> ", 0, *x);
    vector_set(vec, 0, x);
    __print_vector(vec);

    int *y = malloc(sizeof(int));
    *y = 200;
    printf("set index = %d y = %d ==> ", 3, *y);
    vector_set(vec, 3, y);
    __print_vector(vec);

    int *z = malloc(sizeof(int));
    *z = 300;
    printf("set index = %d z = %d ==> ", vector_size(vec) - 1, *z);
    vector_set(vec, vector_size(vec) - 1, z);
    __print_vector(vec);
}

//int main() {
////    __test_new_vector();
////    __test_vector_push();
////    __test_vector_insert();
////    __test_vector_pop();
////    __test_vector_remove();
////    __test_vector_set();
//}