#include <stdio.h>

int inverso(int n) {
  int inv = 0;
  while (n != 0) {
    inv = n % 10 + inv * 10;
    n = n / 10;
  }
  return inv;
}

int main(int argc, char *argv[]) {
  int num, invnum, cont = 0, soma;
  scanf("%d", &num);
  invnum = inverso(num);
  while (num - invnum != 0) {
    cont++;
    num = num + invnum;
    invnum = inverso(num);
  }
  printf("%d\n", cont);
  return 0;
}
