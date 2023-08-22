#include <stdio.h>

int main(int argc, char *argv[]) {
  int vetor[3] = {1, 2, 3};
  int *ponteiro = vetor;
  *(ponteiro + 1) =
      10; // estamos adicionando 4 bytes ao ponteiro que aponta agora para o
          // segundo membro da lista que recebe o valor 10
  printf("%d\n", vetor[1]);
  return 0;
}
