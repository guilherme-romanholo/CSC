#include <stdio.h>

void copiarString(char *origem, char *destino) {
  while (*origem != '\0') {
    *destino = *origem;
    ++origem;
    ++destino;
  }
  *destino = '\0';
}

int main(int argc, char *argv[]) {
  char string1[] = "Teste da função";
  char string2[20];
  copiarString(string1, string2);
  printf("%s\n", string2);
  return 0;
}
