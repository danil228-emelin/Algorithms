
// REALIZATION WITHOUT STRUCTURES
#ifndef SANDBOX_TWO_DIM_ARR_H
#define SANDBOX_TWO_DIM_ARR_H
#include "stdlib.h"
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
size_t read_size();
int64_t *array_int_fill(size_t, size_t);
int64_t **array_create(size_t rows, size_t **sizes);
void array_print(int64_t **array, size_t *sizes, size_t rows);
void array_free(int64_t **marray, size_t rows);
int64_t *int64_ptr_min(int64_t *x, int64_t *y);
int64_t *array_int_min(int64_t **array, size_t *sizes, size_t rows);
#endif // SANDBOX_TWO_DIM_ARR_H
