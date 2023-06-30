#include <stdio.h>

int fatduplo(int num) {
  if (num == 1) {
    return 1;
  } else {
    if (num % 2)
      return num * fatduplo(num - 1);
    else
      return fatduplo(num - 1);
  }
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d\n", fatduplo(n));
  return 0;
}
