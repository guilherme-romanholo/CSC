#include <stdio.h>

int main(int argc, char *argv[]) {

  int num, U, D, C;

  printf("Digite um número de 3 algarismos: \n");
  scanf("%d", &num);

  U = num % 10;
  D = (num % 100) / 10;
  C = (num % 1000) / 100;

  printf("%d%d%d \n", U, D, C);

  return 0;
}
