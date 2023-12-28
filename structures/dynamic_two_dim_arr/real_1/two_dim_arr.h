
// REALIZATION WITHOUT STRUCTURES
#ifndef SANDBOX_TWO_DIM_ARR_H
#define SANDBOX_TWO_DIM_ARR_H
#include "stdlib.h"
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
size_t read_size();
int64_t *array_int_fill(const size_t, const size_t);
int64_t const **array_create(const size_t, size_t **const);
void array_print(int64_t const **const, const size_t *const, const size_t);
void array_free(int64_t const **, const size_t);
int64_t const *array_int_min(int64_t const **const, size_t const *const,
                             const size_t);
#endif // SANDBOX_TWO_DIM_ARR_H
