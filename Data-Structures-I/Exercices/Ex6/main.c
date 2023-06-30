#include <stdio.h>
#include "tree.h"

int main(int argc, char *argv[])
{
  root tree = newRoot(-5);

  insert(tree, -6);
  insert(tree, -10);
  insert(tree, -14);
  insert(tree, -22);
  
  preOrder(tree);
  
  printf("Folhas: %d\n",numberOfLeaves(tree));
  printf("Maior elemento: %d\n", largest(tree));

  return 0;
}
