#include "./linked_list/linked_list.h"
#include "./dynamic_array/dynamic_array.h"
#include "./dynamic_two_dim_arr/real_2/two_dim_arr.h"

static void dynamic_array_sum(int32_t *storage, int32_t value) { *storage += value; }


int main (void){
    struct list *list=list_node_create(11);
    list_add_front(&list,14);
    list_print(list,"linked_list");
    list_destroy(&list);

    size_t dynamic_array_initial_length = 4;
    struct dynamic_array *ref = NULL;
    enum dynamic_array_enum res = dynamic_array_read(dynamic_array_initial_length, &ref);
    if (res != OK) {
        puts("SOME ERROR OCCURRED");
        return -1;
    }
    dynamic_array_print(ref);
    int32_t sum = dynamic_array_foreach(ref, dynamic_array_sum, 10);
    printf("sum-%d\n", sum);
    dynamic_array_free(ref);

    struct array_array_int arrayArrayInt = array_array_int_read();
    array_array_int_print(arrayArrayInt);
    struct maybe_int64 min = array_array_int_min(arrayArrayInt);
    if (min.valid) {
        printf("MIN OF ARRAY %" PRId64 "\n", min.value);
    } else {
        puts("CAN'T FIND MIN ");
    }
    array_array_int_free(arrayArrayInt);

    return 0;
}