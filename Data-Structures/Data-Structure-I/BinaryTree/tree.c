#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

root newRoot(int value) {
  root r = malloc(sizeof(tree_t));

  r->l = NULL;
  r->r = NULL;
  r->value = value;

  return r;
}

void insert(root r, int value) {
  if (value > r->value) {
    if (r->r == NULL)
      r->r = newRoot(value);
    else
      insert(r->r, value);
  } else {
    if (r->l == NULL)
      r->l = newRoot(value);
    else
      insert(r->l, value);
  }
}

void preOrder(root r) {
  if (r != NULL) {
    printf("%d\n", r->value);
    preOrder(r->l);
    preOrder(r->r);
  }
}

int numberOfLeafs(root r) {
  if (r == NULL)
    return 0;
  else if (!r->l && !r->r)
    return 1;
  else
    return numberOfLeafs(r->l) + numberOfLeafs(r->r);
}

int largest(root r){
  if (!r)
    return -1;

  int left = largest(r->l);
  int right = largest(r->r);

  if (r->value > left && r->value > right)
    return r->value;
  else 
    return (left > right) ? left : right;
}










