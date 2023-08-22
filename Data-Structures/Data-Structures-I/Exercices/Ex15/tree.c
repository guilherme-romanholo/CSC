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

void insert(root *tree, int value) {
  if (*tree == NULL) {
    *tree = newRoot(value);
    return;
  }
  if (value > (*tree)->val) {
    if ((*tree)->right == NULL)
      (*tree)->right = newRoot(value);
    else
      insert(&(*tree)->right, value);
  } else {
    if ((*tree)->left == NULL)
      (*tree)->left = newRoot(value);
    else
      insert(&(*tree)->left, value);
  }
}

void preOrder(root tree) {
  if (tree != NULL) {
    printf("%d\n", tree->val);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

void vetToTree(int *vet, int ini, int fim, root *r) {
  if (ini >= fim)
    return;

  insert(r, vet[(ini + fim) / 2]);

  vetToTree(vet, ini, (ini + fim) / 2, r);
  vetToTree(vet, ((ini + fim) / 2) + 1, fim, r);
}

void print2DUtil(root root, int space)
{
    if (root == NULL)
        return;
 
    space += 10;
 
    print2DUtil(root->right, space);
 
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);
 
    print2DUtil(root->left, space);
}
