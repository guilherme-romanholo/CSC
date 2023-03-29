#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int k, pot, num;
  FILE *fp = fopen("pares.dat", "w");

  do {
    printf("Digite um número entre 3 e 9:\n");
    scanf("%d", &k);
  } while (k < 1 || k > 9);

  pot = (int)pow(10, k);

  for (int i = 0; i < pot; i++) {
    num = (rand() / 2) * 2;
    fprintf(fp, "%d ", num);
  }

  fclose(fp);

  return 0;
}
