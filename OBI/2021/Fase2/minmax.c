#include <stdio.h>

int soma(int n) {
  int soma = 0;
  while (n != 0) {
    soma += n % 10;
    n = n / 10;
  }
  return soma;
}

int main(int argc, char *argv[]) {
  int s, a, b, maior = -1, menor = 1000000;
  scanf("%d", &s);
  scanf("%d", &a);
  scanf("%d", &b);

  for (int i = a; i <= b; i++) {
    if (s == soma(i) && menor > i) {
      menor = i;
    } else if (s == soma(i) && i > maior) {
      maior = i;
    }
  }
  if (maior == -1) {
    maior = menor;
  }
  printf("%d\n", menor);
  printf("%d\n", maior);
  return 0;
}
