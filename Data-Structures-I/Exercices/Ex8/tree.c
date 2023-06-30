#include "tree.h"
#include "stack.h"
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

void insertTree(root tree, int value) {
  if (value > tree->val) {
    if (tree->right == NULL)
      tree->right = newRoot(value);
    else
      insertTree(tree->right, value);
  } else {
    if (tree->left == NULL)
      tree->left = newRoot(value);
    else
      insertTree(tree->left, value);
  }
}

void posOrder(root tree) {
  if (tree != NULL) {
    posOrder(tree->left);
    posOrder(tree->right);
    printf("%d\n", tree->val);
  }
}

void posOrderIterative(root tree) {
  stack_t *stack = newStack(tree);
  stack_t *out = NULL;

  while (stack != NULL) {
    tree_t *curr = popStack(&stack);

    pushStack(&out, curr);

    if (curr->left)
      pushStack(&stack, curr->left);

    if (curr->right)
      pushStack(&stack, curr->right);
  }

  while (out != NULL) {
    tree_t *cur = popStack(&out);
    printf("%d\n", cur->val);
  }
}
