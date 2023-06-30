#include <stdio.h>

int main(int argc, char *argv[]) {
  int x, y, *px, *py;

  scanf("%d %d", &x, &y);
  px = &x;
  py = &y;

  printf("X = %p\nY = %p\n\n", px, py);
  printf("Maior:\n");
  if (px > py) {
    printf("X = %p\n", px);
  } else {
    printf("Y = %p\n", py);
  }

  return 0;
}
