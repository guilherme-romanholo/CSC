#include <stdio.h>

int somarVetor(int arr[], const int n) {
  int soma = 0;
  int *ponteiro;
  int *const finalVetor = arr + n;

  for (ponteiro = arr; ponteiro < finalVetor; ++ponteiro) {
    soma += *ponteiro;
  }

  return soma;
}

int main(int argc, char *argv[]) {
  int vetor[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  printf("A soma dos membros do vetor é: %d\n", somarVetor(vetor, 10));
  return 0;
}
