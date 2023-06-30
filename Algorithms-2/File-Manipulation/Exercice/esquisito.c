#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *ler, *escrever;
  int num, i = 0;
  char c;
  char letras[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  ler = fopen("pares.dat", "r");
  escrever = fopen("esquisito.dat", "w");

  while (fscanf(ler, "%d%c", &num, &c) != EOF) {
    c = letras[i % 26];
    i++;
    fprintf(escrever, "%d%c", num, c);
  }

  fclose(ler);
  fclose(escrever);
  return 0;
}
