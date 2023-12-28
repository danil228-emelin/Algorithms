// add enum describing error
// add more function
// add cmake
// why only int ??generic
// why only sum?? function programming
// make size_t constant
// functionality
// copy value from one array to another
// make copy of array
// set the value
// add the value to the end
// add the value in the front
// platform-independent type
//возвращение ошибок
// foreach для функция высшего порядка
//сверкту сделать.
// Сгенерировать список длины sz с помощью значения init и функции f
//поменять имя методов назвваниеСТр_действие
#include "dynamic_array.h"
#include <stdio.h>

static enum dynamic_array_enum

dynamic_array_create(const size_t size, struct dynamic_array  ** ref) {
  *ref = malloc(sizeof(struct dynamic_array));

  if (!(*ref))
    return REF_NULL;
  struct dynamic_array *dynamic_array = *ref;

  dynamic_array->size = size;
  dynamic_array->array = malloc(sizeof(int) * size);
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
    array_free(*ref);
    *ref = NULL;
    return result;
  }

  puts("read array");
  puts("-----------------------------");
  int *array = (*ref)->array;
  for (size_t i = 0; i < size; i++) {
    int result_read = scanf("%d", array + i);
    if (!result_read) {
      array_free(*ref);
      *ref = NULL;
      return INVALID_READ;
    }
  }
  puts("-----------------------------");

  return OK;
}
void array_print(struct dynamic_array const *const dynamic_array) {
  if (!dynamic_array) {
    return;
  }
  int *const array = dynamic_array->array;
  puts("print array");
  puts("-----------------------------");
  for (size_t i = 0; i < dynamic_array->size; i++) {
    printf("%d\n", array[i]);
  }
  puts("-----------------------------");
}
int array_operation(struct dynamic_array const *array,
                    int(func)(int const *const, const size_t size)) {
  if (!array)
    return 0;
  return func(array->array, array->size);
}
void array_free(struct dynamic_array *dynamic_array) {
  if (!dynamic_array)
    return;
  free(dynamic_array->array);
  free((void *)dynamic_array);
}
int array_sum(int const *const a, const size_t size) {
  int sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += a[i];
  }
  return sum;
}

int main(void) {
  size_t a = 4;
  struct dynamic_array *ref = NULL;
  enum dynamic_array_enum res = dynamic_array_read(a, &ref);
  if (res != OK) {
    puts("SOME ERROR OCCURRED");
    return -1;
  }
  array_print(ref);
}