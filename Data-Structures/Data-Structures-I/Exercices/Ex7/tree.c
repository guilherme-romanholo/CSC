#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

struct tree {
  int info;
  struct tree *right;
  struct tree *left;
};

void checkLevel(root node, int level, int *height, int *result);
int checkChild(root node);
void numberOfNodes(root node, int *result);

void checkLevel(root node, int level, int *height, int *result) {
  if (node == NULL)
    return;

  if (node->left == NULL && node->right == NULL) {
    if (*height == -1)
      *height = level;
    else if (*height != level)
      *result = 0;
    return;
  }

  checkLevel(node->left, level + 1, height, result);
  checkLevel(node->right, level + 1, height, result);
}

int checkChild(root node) {
  if (node->right && node->left)
    return 2;
  else if (!node->right && !node->left)
    return 0;
  else
    return 1;
}

void numberOfNodes(root node, int *result) {
  if (node != NULL) {
    if (checkChild(node) % 2)
      *result = 0;
    numberOfNodes(node->left, result);
    numberOfNodes(node->right, result);
  }
}

int isFull(root node) {
  int height = -1, resultLevel = 1, resultNodes = 1;

  checkLevel(node, 0, &height, &resultLevel);
  numberOfNodes(node, &resultNodes);

  return (resultLevel && resultNodes);
}

void insert(root node, int value) {
  if (value > node->info) {
    if (node->right)
      insert(node->right, value);
    else
      node->right = newRoot(value);
  } else {
    if (node->left)
      insert(node->left, value);
    else
      node->left = newRoot(value);
  }
}

root newRoot(int value) {
  root r = malloc(sizeof(tree_t));

  r->right = NULL;
  r->left = NULL;
  r->info = value;

  return r;
}

void preOrder(root node) {
  if (node != NULL) {
    printf("%d\n", node->info);
    preOrder(node->left);
    preOrder(node->right);
  }
}
