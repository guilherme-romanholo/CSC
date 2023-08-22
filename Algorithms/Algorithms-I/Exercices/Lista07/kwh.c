#include <stdio.h>

int main(int argc, char *argv[]) {
  float valor;
  char apos;

  printf("Digite a quantidade de kWh gastos: \n");
  scanf("%f", &valor);
  printf("Você é aposentado? [S/N]\n");
  scanf(" %c", &apos);

  if (apos == 'S' || apos == 's') {
    valor = valor * 0.1 * 0.85;
  } else {
    valor = valor * 0.1;
  }

  printf("O valor da energia em kWh é: R$ %.2f \n", valor);

  return 0;
}
