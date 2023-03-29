#include <stdio.h>
#include <math.h>

typedef struct {
  int quant;
  unsigned long res;
} exemplo;

unsigned long funcao(int n);

int main() {
  exemplo logica;

  printf("Quantas madeiras têm para mover?: ");
  scanf("%d", &logica.quant);

  logica.res = funcao(logica.quant);

  printf("\nA quantidade de movimentos é de: %lu", logica.res);

  return 0;
}

unsigned long funcao(int n) {

  int res_2;
  
  if (n == 0) {
    return 0;
  }
  else {
    res_2 = (2 * funcao(n - 1)) + 1;
    return res_2;
  }
}