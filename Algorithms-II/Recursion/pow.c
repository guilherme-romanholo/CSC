#include <stdio.h>

int pot(int n, int k) {
  if (k == 0)
    return 1;
  else
    return n * pot(n, k - 1);
}

int main(int argc, char *argv[]) {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%d\n", pot(n, k));
  return 0;
}
