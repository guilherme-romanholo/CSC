#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 20, *ponteiro;
  ponteiro = &i;
  printf("O valor da variável i é: %d\n", i);
  printf("Endereço de memória da variável i: %p\n", &i);
  printf("O ponteiro aponta para o valor: %d\n", *ponteiro);
  printf("O ponteiro aponta para o endereço: %p\n", ponteiro);
  // Obs: Quando colocamos o * estamos mechendo no endereço de memória quando
  // não colocamos alteramos o ponteiro
  return 0;
}
