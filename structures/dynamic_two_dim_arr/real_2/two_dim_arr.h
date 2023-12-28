
//REALIZATION WITH STRUCTURES
#ifndef SANDBOX_TWO_DIM_ARR_H
#define SANDBOX_TWO_DIM_ARR_H
#include <inttypes.h>
#include <stdio.h>
#include<stdbool.h>
size_t read_size();
struct array_int {
    int64_t* data;
    size_t size;
};
void array_int_fill( int64_t* array, size_t sz );
struct array_int array_int_read();
struct maybe_int64 array_int_get( struct array_int a, size_t i );
bool array_int_set( struct array_int a, size_t i, int64_t value );
void array_int_print( struct array_int array );
struct maybe_int64 array_int_min( struct array_int array );
void array_int_free( struct array_int a );

void array_int_normalize( struct array_int array, int64_t m );
struct maybe_array_int {
    struct array_int value;
    bool valid;
};

struct maybe_array_int some_array_int(struct array_int array);
const struct maybe_array_int none_array_int = { {NULL, 0}, false };


/*  ---- int[][] ---- */

struct array_array_int {
    struct array_int* data;
    size_t size;
};

/*  --- строки ---  */

struct maybe_array_int array_array_int_get_row( struct array_array_int a, size_t i );

bool array_array_int_set_row( struct array_array_int a, size_t i, struct array_int value );
/*  --- get/set ---  */

struct maybe_int64 array_array_int_get( struct array_array_int a, size_t i, size_t j );

bool array_array_int_set( struct array_array_int a, size_t i, size_t j, int64_t value );

/*  --- read/print ---  */

struct array_array_int array_array_int_read();


void array_array_int_print( struct array_array_int array);


/*  --- min/normalize ---  */

// найти минимальный элемент в массиве массивов
struct maybe_int64 array_array_int_min( struct array_array_int array );

// вычесть из всех элементов массива массивов число m
void array_array_int_normalize( struct array_array_int array, int64_t m);

void array_array_int_free( struct array_array_int array );
#endif // SANDBOX_TWO_DIM_ARR_H
