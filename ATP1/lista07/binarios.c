#include <stdio.h>

int main(int argc, char *argv[]) {
  int res;
  for (int i = 32; i < 128; i++) {
    if (i % 2) { // quando colocamos essa condição se i % 2 tiver resto 1 = true
                 // se tiver resto 0 = false
      printf("%c ",
             i); // quando fazemos a divisão i % 2 ele sempre vai retornar o
                 // ultimo resto, o qual é o primeiro digito do binario
    }
  }

  printf("\n");
  return 0;
}
