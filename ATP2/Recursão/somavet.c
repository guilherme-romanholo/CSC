#include <stdio.h>
#define tam 5

int soma(int *vet, int n) {
  if (n == 0) {
    return *vet;
  } else {
    return *vet + soma(vet + 1, n - 1);
  }
}

int main(int argc, char *argv[]) {
  int vet[tam];

  for (int i = 0; i < tam; i++)
    scanf("%d", &vet[i]);

  printf("%d\n", soma(vet, tam));

  return 0;
}
