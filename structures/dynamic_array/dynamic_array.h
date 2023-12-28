// one-dimensional dynamic array
#ifndef SANDBOX_DYNAMIC_ARRAY_H
#define SANDBOX_DYNAMIC_ARRAY_H
#include "stdlib.h"
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
enum dynamic_array_enum { REF_NULL, OK, INVALID_SIZE, INVALID_READ };
struct dynamic_array {
  int *array;
  size_t size;
};
enum dynamic_array_enum dynamic_array_read(const size_t size,
                                           struct dynamic_array **const ref);
void array_print(struct dynamic_array const * const);
int array_operation(struct dynamic_array const * const,
                    int(int const *const, const size_t));
void array_free(struct dynamic_array  *);
#endif // SANDBOX_DYNAMIC_ARRAY_H
