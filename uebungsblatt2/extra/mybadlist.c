#include "mylist.h"
#include "stdlib.h"

static node *freelist = NULL;

static node *get_node() {
  if (freelist == NULL) {
    return malloc(sizeof(node));
  }
  node *n = freelist;
  freelist = freelist->next;
  return n;
}

static void free_node(node *n) {
  n->next = freelist;
  freelist = n;
}

void init() {
  freelist = malloc(sizeof(node));
}

void cleanup() {
  for (node *n = freelist; n != NULL; n = n->next) {
    free(n);
  }
}

node *add_first(node *lis, int val) {
  node *n = get_node();
  n->val = val;
  n->next = lis;
  return n;
}

node *add_last(node *lis, int val) {
  node *n = get_node();
  n->val = val;
  node *p;
  for (p = lis; p->next != NULL; p = p->next);
  p->next = n;
  return lis;
}

node *remove_first(node *lis) {
  free_node(lis);
  return lis->next;
}

node *remove_last(node *lis) {
  if (lis == NULL) return NULL;
  node *n = lis;
  while (n->next != NULL) n = n->next;
  free_node(n->next);
  n->next = NULL;
  return lis;
}

void clear(node *lis) {
  while (lis != NULL) {
    lis = remove_last(lis);
  }
}
