#include <stdio.h>

int somatorio(int num) {
  if (num == 0)
    return 0;
  else
    return num + somatorio(num - 1);
}

int main(int argc, char *argv[]) {
  int n;

  scanf("%d", &n);

  printf("%d\n", somatorio(n));
  return 0;
}
