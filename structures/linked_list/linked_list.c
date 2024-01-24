#include "linked_list.h"
#include <errno.h>
#include <string.h>
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
void foreach (struct list const *list, void(func)(int64_t value)) {
  while (list) {
    func(list->value);
    list = list->next;
  }
}
void map(struct list const *base_list, int64_t(func)(int64_t),
         struct list **created_list) {
  if (!base_list || !func)
    return;
  struct list *node = node_create(func(base_list->value));
  if (!node) {
    return;
  }
  base_list = base_list->next;
  *created_list = node;
  struct list *first = node;
  while (base_list) {
    struct list *new_node = node_create(func(base_list->value));
    if (!new_node) {
      list_destroy(created_list);
      return;
    }
    first->next = new_node;
    first = new_node;
    base_list = base_list->next;
  }
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
void list_print(struct list const *first, char const *list_name) {
  if (!list_name) {
    puts("Printing list");
  } else {
    printf("Printing list %s\n", list_name);
  }
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
void map_mut(struct list *list, int64_t(function)(int64_t)) {
  if (!list || !function)
    return;
  while (list) {
    list->value = function(list->value);
    list = list->next;
  }
}
int64_t f(int64_t value) { return value + 1; }

int main(void) {
  struct list *first = node_create(25);
}