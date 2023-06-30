#include <stdio.h>
#define m 5

float media(int *vet, int tam) {
  if (tam == 0)
    return 0;
  else if (tam == m)
    return (vet[tam - 1] + media(vet, tam - 1)) / m;
  else
    return vet[tam - 1] + media(vet, tam - 1);
}

int main(int argc, char *argv[]) {
  int vet[m], len = m;
  for (int i = 0; i < m; i++) {
    scanf("%d", &vet[i]);
  }
  printf("%.2f\n", media(vet, len));
  return 0;
}
