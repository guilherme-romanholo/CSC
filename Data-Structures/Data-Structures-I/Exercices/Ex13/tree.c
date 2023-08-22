#include "tree.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct tree {
  int val;
  struct tree *right;
  struct tree *left;
};

root newRoot(int value) {
  root r = malloc(sizeof(tree_t));

  r->right = NULL;
  r->left = NULL;
  r->val = value;

  return r;
}

void insert(root tree, int value) {
  if (value > tree->val) {
    if (tree->right == NULL)
      tree->right = newRoot(value);
    else
      insert(tree->right, value);
  } else {
    if (tree->left == NULL)
      tree->left = newRoot(value);
    else
      insert(tree->left, value);
  }
}

int search_min(root r) {
  if (r->left == NULL) {
    return r->val;
  } else {
    return search_min(r->left);
  }
}

void preOrder(root tree) {
  if (tree != NULL) {
    printf("%d\n", tree->val);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}
