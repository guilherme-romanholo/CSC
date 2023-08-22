#include "tree.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int vet[10] = {1, 2, 4, 5, 7, 8, 10, 12, 20, 23};
  root r = NULL;

  vetToTree(vet, 0, 10, &r);

  preOrder(r);

  print2DUtil(r, 0);
  return 0;
}
