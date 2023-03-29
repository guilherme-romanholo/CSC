#include <stdio.h>

int ocorr(int n, int k) {
  if (n == 0) {
    return 0;
  } else {
    if (n % 10 == k)
      return ocorr(n / 10, k) + 1;
    else
      return ocorr(n / 10, k);
  }
}

int main(int argc, char *argv[]) {
  int num, k;
  scanf("%d %d", &num, &k);
  printf("%d\n", ocorr(num, k));
  return 0;
}
