#include <stdio.h>
#include <stdlib.h>

void check(int *, int, int, int);

int main(int argc, char *argv[]) {
  int *mat, N, M, A, B;

  scanf("%d %d", &N, &M);

  mat = malloc(N * N * sizeof(int));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &mat[(i * N) + j]);
    }
  }

  for (int i = 0; i < M; i++) {
    scanf("%d %d", &A, &B);
    check(mat, A - 1, B - 1, N);
  }

  free(mat);

  return 0;
}

void check(int *mat, int alfa, int beta, int N) {
  int min = 2 * N * N + 1;

  for (int i = alfa; i <= beta; i++) {
    for (int j = alfa; j <= beta; j++) {
      if (min > mat[(N * i) + j]) {
        min = mat[(i * N) + j];
      }
    }
  }

  printf("%d\n", min);
}
