#include <stdio.h>

int superfat(int n, int m) {
  int fat;
  if (m == 1) {
    return 1;
  }
  if (n == 1) {
    return superfat(m - 1, m - 1);
  }
  return n * superfat(n - 1, m);
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d\n", superfat(n, n));
  return 0;
}
