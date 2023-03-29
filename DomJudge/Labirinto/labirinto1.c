#include <stdio.h>
#include <stdlib.h>

int **alloc(int);
void scan_mat(int **, int **, int);
int valid_point(int **, int, int, int);
void DFS(int **, int **, int, int, int, int);
int check_ans(int **, int);

int resp;
// Time limit, tentar sem alocação dinâmica
int main(int argc, char *argv[]) {
  int N, I, C, **mat, **vis;

  scanf("%d %d %d", &N, &I, &C);

  mat = alloc(N);
  vis = alloc(N);

  scan_mat(mat, vis, N);

  DFS(mat, vis, 0, I, N, C);

  printf("-1\n");

  return 0;
}

void DFS(int **mat, int **vis, int i, int j, int N, int C) {
  if (i == N - 1 && j == C && mat[i][j] == 0) {
    vis[i][j] = 1;
    resp = check_ans(vis, N);
    printf("%d\n", resp);
    exit(0);
  }

  if (valid_point(mat, i, j, N)) {
    if (vis[i][j] != 0)
      return;

    vis[i][j] = 1;

    DFS(mat, vis, i + 1, j, N, C);
    DFS(mat, vis, i, j + 1, N, C);
    DFS(mat, vis, i, j - 1, N, C);

    vis[i][j] = 0;
    return;
  }
  return;
}

int check_ans(int **vis, int N) {
  int count = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (vis[i][j] != 0)
        count++;
    }
  }
  return count;
}

int valid_point(int **mat, int i, int j, int N) {
  if (i >= 0 && i < N && j >= 0 && j < N && mat[i][j] == 0)
    return 1;
  else
    return 0;
}

void scan_mat(int **mat, int **vis, int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &mat[i][j]);
      vis[i][j] = 0;
    }
  }
}

int **alloc(int N) {
  int **mat;
  mat = malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++)
    mat[i] = malloc(N * sizeof(int));
  return mat;
}
