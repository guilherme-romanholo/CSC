#include <stdio.h>

int somadgt(int num) {
  if (!num) {
    return 0;
  } else {
    return num % 10 + somadgt(num / 10);
  }
}

int main(int argc, char *argv[]) {
  int n;

  scanf("%d", &n);

  printf("%d\n", somadgt(n));
  return 0;
}
