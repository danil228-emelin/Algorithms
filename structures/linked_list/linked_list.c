#include "linked_list.h"
struct list *node_create(int64_t value) {
  struct list *node = malloc(sizeof(struct list));
  if (!node)
    return NULL;
  node->value = value;
  node->next = NULL;
  return node;
}
void list_add_front(struct list **old, int64_t value) {
  if (!old)
    return;
  struct list *new_node = node_create(value);
  if (!new_node)
    return;
  new_node->next = *old;
  *old = new_node;
}
size_t list_length(const struct list *list) {
  size_t length = 0;
  while (list) {
    length++;
    list = list->next;
  }
  return length;
}
void list_destroy(struct list **list_ref) {
  if (!list_ref)
    return;
  struct list *list = *list_ref;
  struct list *copy = NULL;
  while (list->next) {
    copy = list;
    list = list->next;
    free(copy);
  }
  *list_ref = NULL;
}

struct list *list_last(struct list *list) {
  if (!list)
    return NULL;
  while (list->next) {
    list = list->next;
  }
  return list;
}
void list_add_back(struct list **old, int64_t value) {
  if (!old)
    return;
  struct list *first = *old;
  while (first->next) {
    first = first->next;
  }
  struct list *new_node = node_create(value);
  first->next = new_node;
}
void list_print(struct list const *first) {
  puts("Printing list");
  puts("-------------------------");
  while (first) {
    printf("%" PRId64 "\n", first->value);
    first = first->next;
  }
  puts("-------------------------");
}
struct list *list_reverse(const struct list *list) {
  if (!list)
    return NULL;
  struct list *first = NULL;
  while (list) {
    if (!first) {
      first = node_create(list->value);
    } else {
      struct list *el = node_create(list->value);
      el->next = first;
      first = el;
    }
    list = list->next;
  }
  return first;
}

int main(void) {

  struct list *first = node_create(25);
  list_add_front(&first, 16);
  list_add_back(&first, 32);
  list_print(first);
  struct list *first_reverse = list_reverse(first);
  list_print(first_reverse);

  printf("List length %zu\n", list_length(first));
  list_destroy(&first);
  list_print(first);
}