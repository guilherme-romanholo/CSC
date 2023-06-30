#include <stdio.h>

void ValorTroca(int valor) { ++valor; }

void pValorTroca(int *p) { ++*p; }

int main(int argc, char *argv[]) {
  int var = 1, *pont, opc;
  pont = &var;
  printf("Escolha a opção:\n(1)Acréscimo sem ponteiro\n(2)Acréscimo com "
         "ponteiro\n");
  scanf("%d", &opc);
  if (opc == 1) {
    ValorTroca(var);
  } else {
    pValorTroca(pont);
  }
  printf("Valor de var é igual a: %d\n", var);
  return 0;
}
