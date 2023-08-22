#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *p = (int *)malloc(1 * sizeof(int));
  if (p == NULL) {
    printf("Malloc não funcionou.\n"); // caso o S.O. não consiga alocar memória
  }
  // A função malloc retorna o endereço onde a memória foi alocada, por isso
  // o ponteiro recebe ela
  *p = 1000; // jogamos o valor 1000 para o espaço alocado, se não ele usa lixo
             // de memória
  printf("%d\n", *p);
  return 0;
}
