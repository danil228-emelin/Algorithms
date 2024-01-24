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
struct list *node_create(int64_t);
void list_add_front(struct list **, int64_t);
size_t list_length(const struct list *);
void list_destroy(struct list **);
struct list *list_last(struct list *);
void list_print(struct list const *,char const *);
void list_add_back(struct list **, int64_t);
void foreach (struct list const *, void(int64_t));
void map(struct list const *, int64_t(int64_t), struct list **);
void map_mut(struct list  *, int64_t(int64_t));
struct list *list_reverse(const struct list *);
#endif // SANDBOX_LINKED_LIST_H
