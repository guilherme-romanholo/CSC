#include <stdio.h>

int main(int argc, char *argv[]) {
  int height, n = 2, s, p;
  printf("Height:\n");
  scanf("%d", &height);
  s = height;
  p = n - 2;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < s - 1; k++) {
        if (j == 0)
          printf(" ");
      }
      if (j == n - 2) {
        printf("#  ");
        for (int l = 0; l < p; l++) {
          printf("#");
        }
        p++;
      } else {
        printf("#");
      }
    }
    s--;
    n++;
    printf("\n");
  }
  return 0;
}
