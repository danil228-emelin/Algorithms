#include "two_dim_arr.h"

static struct array_array_int *
array_array_int_create(const size_t amount_of_rows) {
  struct array_array_int *array = malloc(sizeof(struct array_array_int));
  if (!array)
    return NULL;
  array->data = malloc(sizeof(struct array_int) * amount_of_rows);
  if (!array->data)
    return NULL;
  array->size = amount_of_rows;
  return array;
}
void array_int_fill(int64_t *const array, const size_t sz, const size_t index) {
  puts("--------------------------");
  printf("fill %zu elements of array %zu \n", sz, index);
  for (size_t i = 0; i < sz; i++) {

    scanf("%" SCNd64, array + i);
  }
  puts("--------------------------");
}

struct array_int array_int_read(const size_t index) {
  printf("Write amount of elements in array %zu\n", index);

  size_t amount_of_elements = read_size();
  int64_t *data = malloc(sizeof(int64_t) * amount_of_elements);
  if (!data)
    return (struct array_int){0};
  array_int_fill(data, amount_of_elements, index);
  return (struct array_int){.data = data, .size = amount_of_elements};
}
void array_array_int_print(struct array_array_int array) {
  for (size_t i = 0; i < array.size; i++) {
    struct array_int data = array.data[i];
    puts("--------------------------");
    printf("array %zu\n", i);
    for (size_t j = 0; j < data.size; j++) {
      printf("%" PRId64 "\n", data.data[j]);
    }
    puts("--------------------------");
  }
}

struct array_array_int array_array_int_read() {
  puts("Write amount of rows in array");
  size_t amount_of_rows = read_size();
  struct array_array_int *array_array_int =
      array_array_int_create(amount_of_rows);
  if (!array_array_int)
    return (struct array_array_int){0};
  struct array_int *data = array_array_int->data;
  for (size_t i = 0; i < amount_of_rows; i++) {
    data[i] = array_int_read(i);
  }
  return *array_array_int;
}
struct maybe_int64 array_array_int_min(struct array_array_int array) {
  if (!array.data || array.size <= 0)
    return EMPTY_MAYBE_INT64;
  struct array_int *data = array.data;
  int64_t min = INT64_MAX;
  for (size_t i = 0; i < array.size; i++) {
    struct array_int array_one_dim = data[i];
    struct maybe_int64 min_from_row = array_int_min(array_one_dim);
    if (!min_from_row.valid)
      continue;
    min = min > min_from_row.value ? min_from_row.value : min;
  }
  if (min == INT64_MAX)
    return EMPTY_MAYBE_INT64;
  return (struct maybe_int64){.value = min, .valid = true};
}
struct maybe_int64 array_int_min(struct array_int array) {
  if (!array.data || array.size <= 0)
    return EMPTY_MAYBE_INT64;
  int64_t min = INT64_MAX;
  int64_t *data = array.data;
  for (size_t i = 0; i < array.size; i++) {
    min = min > data[i] ? data[i] : min;
  }
  if (min == INT64_MAX)
    return EMPTY_MAYBE_INT64;
  return (struct maybe_int64){.value = min, .valid = true};
}
void array_int_free(struct array_int a) {
  if (!a.data)
    return;
  free(a.data);
}
void array_array_int_free(struct array_array_int array) {
  if (!array.data || array.size <= 0)
    return;
  foreach (array, array_int_free)
    ;
  free(array.data);
}
void foreach (struct array_array_int arrayArrayInt,
              void(func)(struct array_int arrayInt)) {
  if (!arrayArrayInt.data || arrayArrayInt.size <= 0)
    return;
  struct array_int *arrays = arrayArrayInt.data;
  for (size_t i = 0; i < arrayArrayInt.size; i++) {
    func(arrays[i]);
  }
}
