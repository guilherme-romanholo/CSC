#include <stdio.h>

int main(int argc, char *argv[]) {
  int soma = 0;
  for (int i = 0; i <= 500; i++) {
    if (!(i % 2)) {
      soma += i;
    }
  }
  printf("A soma é: %d\n", soma);

  return 0;
}
