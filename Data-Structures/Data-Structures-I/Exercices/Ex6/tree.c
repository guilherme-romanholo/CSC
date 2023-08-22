#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree {
  int val;
  struct tree *right;
  struct tree *left;
};

int empty(root tree) { return (tree == NULL); }

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

void preOrder(root tree) {
  if (tree != NULL){
    printf("%d\n",tree->val);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

int numberOfLeaves(root tree) {
  if (tree == NULL)
    return 0;
  else if (tree->right == NULL && tree->left == NULL)
    return 1;
  else
    return numberOfLeaves(tree->left) + numberOfLeaves(tree->right);
}

int largest(root tree) {
  if (tree == NULL)
    return INT_MIN;

  int largL = largest(tree->left);
  int largR = largest(tree->right);

  if (largL > largR)
    return (largL > tree->val) ? largL : tree->val; 
  else
    return (largR > tree->val) ? largR : tree->val; 
}

