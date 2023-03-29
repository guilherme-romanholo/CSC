#include <stdio.h>

int hiperfat(int num) {
  int aux = 1;
  if (num == 0) {
    return 1;
  } else {
    for (int i = 0; i < num; i++)
      aux = aux * num;
    return aux * hiperfat(num - 1);
  }
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d\n", hiperfat(n));
  return 0;
}
