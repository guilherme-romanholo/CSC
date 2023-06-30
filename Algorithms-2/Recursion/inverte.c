#include <stdio.h>

int inverte(int num, int tot) {
  if (num == 0)
    return tot;
  else
    return inverte(num / 10, tot * 10 + num % 10);
}

int main(int argc, char *argv[]) {
  int num;

  scanf("%d", &num);

  num = inverte(num, 0);

  printf("%d\n", num);
  return 0;
}
