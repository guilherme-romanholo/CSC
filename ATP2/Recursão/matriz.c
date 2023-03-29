#include <stdio.h>

int main(int argc, char *argv[]) {
  int num, i, j, n = 1, aux;

  scanf("%d", &num);
  aux = num;

  int matriz[num][num];

  while (n != num) {
    for (i = n - 1; i < aux; i++) {
      for (j = n - 1; j < aux; j++) {
        matriz[i][j] = n;
      }
    }
    n++;
    aux--;
  }
  for (i = 0; i < num; i++) {
    for (j = 0; j < num; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  return 0;
}
