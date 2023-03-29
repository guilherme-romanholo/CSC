#include <stdio.h>
#include <unistd.h>
// É possível declarar um if no pré-processador ifdef, por exemplo para incluir
// bibliotecas para diferente plataformas, linux ou windows

void troca(int *n1, int *n2) {
  int aux;
  aux = *n1;
  *n1 = *n2;
  *n2 = aux;
}

int main(int argc, char *argv[]) {
  int num1, num2;
  printf("Digite o valor de num1:\n");
  scanf("%d", &num2);
  ;
  printf("Digite o valor de num2:\n");
  scanf("%d", &num2);
  printf("Aqui temos que:\nnum1 = %d\nnum2 = %d\n", num1, num2);
  printf("Trocando os valores por ponteiros...\n");
  sleep(2);
  troca(&num1, &num2);
  printf("Agora temos que:\nnum1 = %d\nnum2 = %d\n", num1, num2);
  return 0;
}
