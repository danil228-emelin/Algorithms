#include "two_dim_arr.h"
size_t read_size() {
  size_t size = 0;
  int res = scanf("%zu", &size);
  if (res <= 0)
    return 0;
  return size;
}
static void print_arrays_sizes(size_t *sizes, size_t amount) {
  puts("------------------------------------------");
  puts("Array lengths");
  for (size_t i = 0; i < amount; i++) {
    printf("%zu\n", sizes[i]);
  }
  puts("------------------------------------------");
}
int64_t *array_int_fill(size_t size, size_t index) {
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

int64_t **array_create(size_t rows, size_t **sizes) {
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
void array_print(int64_t **array, size_t *sizes, size_t rows) {
  for (size_t i = 0; i < rows; i++) {
    int64_t *array_one_d = array[i];

    size_t size_array_one_d = sizes[i];
    puts("-----------------");
    printf("Print array %zu\n", i);
    for (size_t j = 0; j < size_array_one_d; j++) {
      printf("%" PRId64 "\n", array_one_d[j]);
    }
    puts("-----------------");
  }
}

int main(void) {
  int64_t **arrays = NULL;
  size_t *array_sizes = NULL;

  arrays = array_create(3, &array_sizes);
  print_arrays_sizes(array_sizes, 3);
  array_print(arrays, array_sizes, 3);
}