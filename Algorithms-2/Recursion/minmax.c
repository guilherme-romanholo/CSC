#include <stdio.h>
#define n 8

int difrecursivo(int *vetor, int tam) {
  if (tam == 1) {
    return vetor[0];
  } else {
    int max, min;
    min = max = vetor[0];

    if (max < vetor[tam - 1])
      max = vetor[tam - 1];
    if (min > vetor[tam - 1])
      min = vetor[tam - 1];

    return max - min;
  }
}

int main(int argc, char *argv[]) {
  int vet[n], i, min = 0, max = 0;

  for (i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }

  printf("%d", difrecursivo(vet, n));

  return 0;
}
