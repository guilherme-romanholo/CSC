#include <math.h>
#include <stdio.h>

int decimal(int n, int i) {
  if (n == 0)
    return 0;
  else
    return pow(2, i) * (n % 10) + decimal(n / 10, i + 1);
}

void binario(int n) {
  if (n / 2 != 0)
    binario(n / 2);
  printf("%d", n % 2);
}

int main(int argc, char *argv[]) {
  int n, op;
  printf("(1)Binário para decimal\n(2)Decimal para binário\n");
  scanf("%d", &op);
  printf("Digite o número:\n");
  scanf("%d", &n);
  if (op == 1)
    printf("%d", decimal(n, 0));
  else if (op == 2)
    binario(n);
  printf("\n");
  return 0;
}
