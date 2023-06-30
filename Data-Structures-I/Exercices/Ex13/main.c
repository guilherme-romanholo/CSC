#include "tree.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  root r = newRoot(12);

  insert(r, 10);
  insert(r, 8);
  insert(r, 18);
  insert(r, 14);
  insert(r, 22);

  printf("%d\n", search_min(r));

  return 0;
}
