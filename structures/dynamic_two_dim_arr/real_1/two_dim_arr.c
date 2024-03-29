// make constants+issues.
#include "two_dim_arr.h"
#include "../common.h"
void print_arrays_sizes(size_t *sizes, size_t amount) {
  puts("------------------------------------------");
  puts("Array lengths");
  for (size_t i = 0; i < amount; i++) {
    printf("%zu\n", sizes[i]);
  }
  puts("------------------------------------------");
}
int64_t *array_int_fill(const size_t size, const size_t index) {
  puts("--------------------------");
  printf("fill %zu array\n", index);

  printf("fill %zu elements of array \n", size);
  int64_t *array = malloc(sizeof(int64_t) * size);
  for (size_t i = 0; i < size; i++) {
    int64_t h = 0;
    scanf("%" SCNd64, &h);
    array[i] = h;
  }
  puts("--------------------------");
  return array;
}
int64_t const **array_create(const size_t rows, size_t **const sizes) {

  *sizes = calloc(rows, sizeof(size_t));
  int64_t **arrays_refs = calloc(rows, sizeof(int64_t *));

  for (size_t i = 0; i < rows; i++) {
    printf("Write size of array %zu\n", i);
    size_t array_size = read_size();
    (*sizes)[i] = array_size;

    arrays_refs[i] = array_int_fill(array_size, i);
  }

  return arrays_refs;
}
void array_print(int64_t const **const array, const size_t *const sizes,
                 const size_t rows) {

  for (size_t i = 0; i < rows; i++) {
    int64_t const *array_one_d = array[i];

    size_t size_array_one_d = sizes[i];
    puts("-----------------");
    printf("Print array %zu\n", i);
    for (size_t j = 0; j < size_array_one_d; j++) {
      printf("%" PRId64 "\n", array_one_d[j]);
    }
    puts("-----------------");
  }
}
void array_free(int64_t const **array, size_t rows) {
  if (!array)
    return;
  for (size_t i = 0; i < rows; i++) {
    free((void *)array[i]);
  }
  free(array);
}
int64_t const *array_int_min(int64_t const **const array,
                             size_t const *const sizes, const size_t rows) {

  int64_t min = INT64_MAX;
  int64_t const *address_min = NULL;

  for (size_t i = 0; i < rows; i++) {
    int64_t const *one_dim_array = array[i];
    for (size_t j = 0; j < sizes[i]; j++) {
      if (min > one_dim_array[j]) {
        min = one_dim_array[j];
        address_min = one_dim_array + j;
      }
    }
  }
  return address_min;
}
