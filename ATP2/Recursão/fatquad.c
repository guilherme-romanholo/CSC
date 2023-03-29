#include <stdio.h>

int fatquad(int num, int aux) {
  if (aux == num) {
    return 1;
  } else {
    return aux * fatquad(num, aux - 1);
  }
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d\n", fatquad(n, n * 2));
  return 0;
}
