#include "tree.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  root arvore = newRoot(12);

  insert(arvore, 14);
  insert(arvore, 10);
  insert(arvore, 18);
  insert(arvore, 13);

  preOrder(arvore);

  isFull(arvore) ? printf("É cheia\n") : printf("Não é cheia\n");

  return 0;
}
