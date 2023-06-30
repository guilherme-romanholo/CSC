#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *p = malloc(sizeof(int));
  *p = 1000;
  printf("%d\n", *p);
  free(p); // ela libera a alocação mas não apaga os dados
  return 0;
}
