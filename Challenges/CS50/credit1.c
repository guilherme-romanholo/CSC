#include <stdio.h>

int main(int argc, char *argv[]) {
  char card[100];
  int sum = 0, aux, sum2 = 0, sum3 = 0;
  scanf(" %s", card);
  for (int i = 0; card[i] != '\0'; i++) {
    if (!(i % 2)) {
      if ((card[i] - '0') * 2 >= 10) {
        aux = (card[i] - '0') * 2;
        while (aux > 0) {
          sum2 += aux % 10;
          aux = aux / 10;
        }
        sum += sum2;
      } else {
        sum += 2 * (card[i] - '0');
      }
    } else {
      sum3 += card[i] - '0';
    }
  }
  if ((sum + sum3) % 10 == 0) {
    printf("Valid!\n");
  } else {
    printf("Invalid!\n");
  }
  return 0;
}
