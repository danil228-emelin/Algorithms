
#include "dynamic_array.h"
#include <stdio.h>

static enum dynamic_array_enum

dynamic_array_create(const size_t size, struct dynamic_array **ref) {
  *ref = malloc(sizeof(struct dynamic_array));

  if (!(*ref))
    return REF_NULL;
  struct dynamic_array *dynamic_array = *ref;

  dynamic_array->size = size;
  dynamic_array->array = malloc(sizeof(int32_t) * size);
  if (!dynamic_array->array) {
    return REF_NULL;
  }
  return OK;
}

enum dynamic_array_enum dynamic_array_read(const size_t size,
                                           struct dynamic_array **const ref) {

  if (!size)
    return INVALID_SIZE;
  enum dynamic_array_enum result = dynamic_array_create(size, ref);
  if (result != OK) {
    dynamic_array_free(*ref);
    *ref = NULL;
    return result;
  }

  puts("read array");
  puts("-----------------------------");
  int32_t *array = (*ref)->array;
  for (size_t i = 0; i < size; i++) {
    int result_read = scanf("%d", array + i);
    if (!result_read) {
      dynamic_array_free(*ref);
      *ref = NULL;
      return INVALID_READ;
    }
  }
  puts("-----------------------------");

  return OK;
}
void dynamic_array_print(struct dynamic_array const *const dynamic_array) {
  if (!dynamic_array) {
    return;
  }
  int32_t *const array = dynamic_array->array;
  puts("print array");
  puts("-----------------------------");
  for (size_t i = 0; i < dynamic_array->size; i++) {
    printf("%d\n", array[i]);
  }
  puts("-----------------------------");
}
int32_t dynamic_array_foreach (struct dynamic_array const *const dynamic_array,
                 void(func)(int32_t * storage, int32_t value),
                 size_t initial_value) {
  if (!dynamic_array)
    return 0;
  int32_t result = initial_value;
  int32_t *array = dynamic_array->array;
  for (size_t i = 0; i < dynamic_array->size; i++) {
    func(&result, array[i]);
  }
  return result;
}
enum dynamic_array_enum
dynamic_array_free(struct dynamic_array *dynamic_array) {
  if (!dynamic_array)
    return REF_NULL;
  free(dynamic_array->array);
  free((void *)dynamic_array);
  return OK;
}

