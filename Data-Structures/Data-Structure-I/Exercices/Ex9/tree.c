#include "tree.h"
#include "queue.h"
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

void preOrder(root tree) {
  if (tree != NULL) {
    printf("%d\n", tree->val);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

void BFS(root tree) {
  queue_t *queue = newQueue(tree);
  queue_t *out = NULL;

  while (queue != NULL) {
    tree_t *curr = popQueue(&queue);
    pushQueue(&out, curr);

    if (curr->left)
      pushQueue(&queue, curr->left);

    if (curr->right)
      pushQueue(&queue, curr->right);
  }

  while (out != NULL) {
    tree_t *curr = popQueue(&out);
    printf("%d\n", curr->val);
  }
}
