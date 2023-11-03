#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  root raiz = newRoot(12);
  int c = 0;

  insert(raiz, 15);
  insert(raiz, 10);
  insert(raiz, 9);
  insert(raiz, 11);
  insert(raiz, 14);
  insert(raiz, 17);

  preOrder(raiz);

  printf("%d\n", numberOfLeafs(raiz));
  printf("%d\n", largest(raiz));

  return EXIT_SUCCESS;
}
