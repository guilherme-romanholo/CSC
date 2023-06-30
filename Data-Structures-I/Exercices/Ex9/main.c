#include "tree.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  root tree = newRoot(12);

  insertTree(tree, 18);
  insertTree(tree, 10);
  insertTree(tree, 14);
  insertTree(tree, 22);

  printf("BFS:\n");
  BFS(tree);

  return 0;
}
