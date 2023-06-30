#include <stdio.h>
#include "tree.h"

int main(int argc, char *argv[])
{
  root tree = newRoot(12);

  insertTree(tree, 18);
  insertTree(tree, 10);
  insertTree(tree, 14);
  insertTree(tree, 22);
  
  printf("Pós ordem recursivo:\n");
  posOrder(tree);
  printf("Pós ordem iterativo:\n");
  posOrderIterative(tree);
  

  return 0;
}
