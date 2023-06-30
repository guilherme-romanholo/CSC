#include <stdio.h>

int count = 0;

void procura(int dim, int mat[dim][dim], int princ) {
  for (int i = 0; i < dim; i++) {
    if (mat[princ][i] > 0) {
      count++;
      for (int j = 0; j < dim; j++) {
        mat[princ][j] = 0;
      }
      procura(dim, mat, i);
    }
  }
}

int main(int argc, char *argv[]) {
  int s, t, p, aux1, aux2, resposta;
  scanf("%d %d %d", &s, &t, &p);
  int matriz[s][s], alt[s];
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      matriz[i][j] = 0;
    }
  }
  for (int i = 0; i < s; i++) {
    scanf("%d", &alt[i]);
  }
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &aux1, &aux2);
    matriz[aux1 - 1][aux2 - 1] = alt[aux1 - 1] - alt[aux2 - 1];
    matriz[aux2 - 1][aux1 - 1] = alt[aux2 - 1] - alt[aux1 - 1];
  }
  procura(s, matriz, p - 1);
  printf("%d\n", count);

  /*
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      printf("%d    ", matriz[i][j]);
    }
    printf("\n");
  }
  */
  return 0;
}
