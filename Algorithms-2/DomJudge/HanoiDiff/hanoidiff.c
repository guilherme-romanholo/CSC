#include <stdio.h>
#include <stdlib.h>

int discos, vezes = 0, mov, mat[3][20] = {0};

void write() {
  int flag = 1;
  for (int i = 0; i < 3; i++) {
    flag = 1;
    for (int j = 0; j < discos; j++) {
      if (mat[i][j] == 1) {
        printf("%d ", j + 1);
        flag = 0;
      }
    }
    if (flag)
      printf("0");
    printf("\n");
  }
}

void move_disco(int n, int ori, int dest, int aux) {
  if (n >= 1) {
    move_disco(n - 1, ori, aux, dest);
    vezes++;
    mat[ori][n - 1]--;
    mat[dest][n - 1]++;
    if (vezes == mov) {
      write(); // função pra escrever os vetores
    }
    move_disco(n - 1, aux, dest, ori);
  }
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &discos, &mov);
  for (int i = 0; i < discos; i++) {
    mat[0][i] = 1;
  }
  if (mov == 0) {
    for (int i = 0; i < discos; i++)
      printf("%d ", i + 1);
    printf("\n0\n0\n");
    return 0;
  }
  move_disco(discos, 0, 2, 1);
  return 0;
}
