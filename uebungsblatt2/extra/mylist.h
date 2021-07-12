#ifndef MYLIST_H
#define MYLIST_H

typedef struct node {
  int val;
  struct node *next;
} node;

void init(); // call before any list function
void cleanup(); // call after last list function

node *add_first(node *, int val);
node *add_last(node *, int val);
node *remove_first(node *);
node *remove_last(node *);
void clear(node *);

#endif 
