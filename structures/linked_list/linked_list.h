//
// Created by danil on 12/28/23.
//

#ifndef SANDBOX_LINKED_LIST_H
#define SANDBOX_LINKED_LIST_H
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct list {
  int64_t value;
  struct list *next;
};
struct list *node_create(int64_t value);
void list_add_front(struct list **old, int64_t value);
size_t list_length(const struct list *list);
void list_destroy(struct list **list);
struct list *list_last(struct list *list);
void list_print(struct list const *first);
void list_add_back(struct list **old, int64_t value);
struct maybe_int64 list_at(const struct list *list, size_t idx);
struct list *list_reverse(const struct list *list);
#endif // SANDBOX_LINKED_LIST_H
