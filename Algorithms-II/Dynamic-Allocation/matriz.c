// Alocando uma matriz 4x3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

  int **matriz;

  matriz = malloc(4 * sizeof(int *)); // Cada linha é um ponteiro

  for (int i = 0; i < 4; i++) {
    matriz[i] = malloc(3 * sizeof(int)); // Alocando as colunas
  }

  srand(time(NULL));

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      matriz[i][j] = rand() % 100;
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 4; i++) {
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}
