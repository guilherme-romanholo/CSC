#include "tree.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  root arvore = newRoot(12);
  int *vet = NULL;

  insert(arvore, 14);
  insert(arvore, 10);
  insert(arvore, 18);
  insert(arvore, 13);

  preOrder(arvore);

  vet = lessThanN(arvore, 14);

  return 0;
}
