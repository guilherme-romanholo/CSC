#include <stdio.h>

int main(int argc, char *argv[]) {
  int matriz[5][5] = {{0, -1, -1, 1, 1},
                      {1, 0, -1, -1, 1},
                      {1, 1, 0, -1, -1},
                      {-1, 1, 1, 0, -1},
                      {-1, -1, 1, 1, 0}}; // coluna

  int n, d, x, cd = 0, cx = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &d, &x);
    if (matriz[d][x] == 1) {
      cx++;
    } else if (matriz[d][x] == -1) {
      cd++;
    } else if (matriz[d][x] == 0) {
      cx += 0;
    }
  }
  if (cx > cd) {
    printf("xerxes\n");
  } else {
    printf("dario\n");
  }
  return 0;
}
