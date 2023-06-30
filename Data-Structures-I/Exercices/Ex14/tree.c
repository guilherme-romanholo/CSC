#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

struct tree {
  int info;
  struct tree *right;
  struct tree *left;
};

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

void lessThanNBackend(root node, int n, int **vet, int *i) {
  if (node != NULL) {
    if (node->info < n) {
      (*i)++;
      if (*vet == NULL)
        *vet = malloc(sizeof(int));
      else
        *vet = realloc(*vet, sizeof(int) * (*i));
      (*vet)[*i - 1] = node->info;
    }

    lessThanNBackend(node->left, n, vet, i);
    lessThanNBackend(node->right, n, vet, i);
  }
}

int *lessThanN(root node, int n) {
  int *vet = NULL, i = 0;

  lessThanNBackend(node, n, &vet, &i);

  for (int j = 0; j < i; j++) {
    printf("%d ", vet[j]);
  }
  printf("\n");

  return vet;
}
