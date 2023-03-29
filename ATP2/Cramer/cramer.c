#include <stdio.h>
#include <stdlib.h>

void insereMatriz(double mat[3][3], double res[3]);
void trocaMatriz(double mat[3][3], double res[3], double resp[3]);
double deteminante(double mat[3][3]);

int main(int argc, char *argv[]) {
  int i;
  double matriz[3][3], vet[3], resp[3], delta;
  insereMatriz(matriz, vet);
  delta = deteminante(matriz);
  system("clear");
  if (delta != 0) {
    trocaMatriz(matriz, vet, resp);
    for (i = 0; i < 3; i++) {
      resp[i] = resp[i] / delta;
    }
    printf("x = %.2lf\ny = %.2lf\nz = %.2lf\n", resp[0], resp[1], resp[2]);
  } else {
    printf("Sistema impossível!\n");
  }
  return 0;
}

void insereMatriz(double mat[3][3], double res[3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("Digite o elemento [%d][%d] do sistema linear:\n", i, j);
      scanf("%lf", &mat[i][j]);
    }
  }
  for (i = 0; i < 3; i++) {
    printf("Digite o resultado do sistema:\n");
    scanf("%lf", &res[i]);
  }
}

void trocaMatriz(double mat[3][3], double res[3], double resp[3]) {
  int ind = 0, i, j;
  double temp[3][3];
  for (ind = 0; ind < 3; ind++) {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        temp[i][j] = mat[i][j];
      }
    }
    for (i = 0; i < 3; i++) {
      temp[i][ind] = res[i];
    }
    resp[ind] = deteminante(temp);
  }
}

double deteminante(double mat[3][3]) {
  double det;
  det = mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] +
        mat[0][2] * mat[1][0] * mat[2][1] +
        -1 * mat[0][2] * mat[1][1] * mat[2][0] +
        -1 * mat[0][0] * mat[1][2] * mat[2][1] +
        -1 * mat[0][1] * mat[1][0] * mat[2][2];
  printf("%lf\n", det);
  return det;
}
