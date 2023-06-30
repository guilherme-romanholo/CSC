#include <stdio.h>

int main(int argc, char *argv[]) {
  int cash = 0, count = 0;
  do {
    if (cash < 0) {
      printf("Chage owed: foo\n");
    }
    printf("Chage owed: ");
    scanf("%d", &cash);
  } while (cash < 0);

  while (cash != 0) {
    if (cash >= 25) {
      cash -= 25;
      count++;
    } else if (cash >= 10) {
      cash -= 10;
      count++;
    } else if (cash >= 5) {
      cash -= 5;
      count++;
    } else if (cash >= 1) {
      cash -= 1;
      count++;
    }
  }
  printf("%d\n", count);

  return 0;
}
