
// REALIZATION WITH STRUCTURES
#ifndef SANDBOX_TWO_DIM_ARR_H
#define SANDBOX_TWO_DIM_ARR_H
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../common.h"
struct array_int {
  int64_t *data;
  size_t size;
};

struct maybe_int64 {
  int64_t value;
  bool valid;
};
const struct maybe_int64 EMPTY_MAYBE_INT64 = {0};

void array_int_fill(int64_t *const array, const size_t sz, const size_t index);
struct array_int array_int_read(const size_t index);

struct maybe_int64 array_int_min(struct array_int array);
void array_int_free(struct array_int a);

struct array_array_int {
  struct array_int *data;
  size_t size;
};

struct array_array_int array_array_int_read();

void array_array_int_print(struct array_array_int array);

struct maybe_int64 array_array_int_min(struct array_array_int);
void foreach (struct array_array_int, void(struct array_int));

void array_array_int_free(struct array_array_int array);
#endif // SANDBOX_TWO_DIM_ARR_H
