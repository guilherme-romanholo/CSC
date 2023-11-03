#include "avl.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  avl_t *tree = NULL;

  tree = insert(tree, 3);
  tree = insert(tree, 1);
  tree = insert(tree, 2);
  tree = insert(tree, 4);
  tree = insert(tree, 5);
  tree = insert(tree, 6);

  preOrder(tree);

  printf("===========\n");

  tree = remocao(tree, 2);

  preOrder(tree);

  printf("===========\n");

  tree = remocao(tree, 3);

  preOrder(tree);

  printf("===========\n");

  tree = remocao(tree, 1);

  preOrder(tree);

  return 0;
}
