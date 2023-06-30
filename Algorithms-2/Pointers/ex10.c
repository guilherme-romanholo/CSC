#include <stdio.h>

int main(int argc, char *argv[]) {
  int vet[5];

  for (int i = 0; i < 5; i++) {
    scanf("%d", (vet + i));
  }
  printf("\n");
  for (int i = 0; i < 5; i++) {
    printf("Vet[%d] = %d\n", i, *(vet + i));
    printf("Posição = %p\n", (vet + i));
    printf("\n");
  }

  return 0;
}
