#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  typedef struct molduras {
    int x;
    int y;
  } mol;
  int a, l, n, ind = -2;
  float menor = INFINITY;
  scanf("%d %d", &a, &l);
  scanf("%d", &n);
  mol mold[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &mold[i].x, &mold[i].y);
  }
  for (int i = 0; i < n; i++) {
    if (mold[i].x * mold[i].y >= a * l && mold[i].x * mold[i].y < menor) {
      menor = mold[i].x * mold[i].y;
      ind = i;
    }
  }
  printf("%d\n", ind + 1);
  return 0;
}
