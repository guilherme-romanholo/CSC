#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void guardarArray() {}

void percorreArquivos(FILE *cod, FILE *pal, FILE *lin, char arr[5][50]) {
  int num, i, cont;
  char string[50];

  while (!feof(cod) && !feof(pal)) {
    fscanf(cod, "%d ", &num);
    if (num > 0) {
      for (i = 0; i < num; i++) {
        fscanf(pal, "%s ", string);
        strcpy(arr[cont % 5], string); // func pra guardar no array
        cont++;
        fprintf(lin, "%s ", string);
      }
    } else if (num < 0) {
      cont += num;
      for (i = 0; i < abs(num); i++) {
        fprintf(lin, "%s ", arr[cont % 5]);
        cont++;
      }
    } else {
      fprintf(lin, "0");
    }
    fprintf(lin, "\n");
  }
}

int main(int argc, char *argv[]) {
  FILE *cod, *pal, *lin;
  int num, i, cont = 0;
  char arr[5][50];

  cod = fopen("codigos.dat", "r");
  pal = fopen("palavras.dat", "r");
  lin = fopen("linhas.dat", "w");
  if (cod == NULL || pal == NULL || lin == NULL) {
    printf("Não foi possível abrir os arquivos necessários!\n");
    exit(0);
  }

  percorreArquivos(cod, pal, lin, arr);

  if (!feof(pal) && feof(cod)) { // simplificar esse if, pode tirar o &&
    i = 1;
    while (!feof(pal)) {
      fscanf(pal, "%s ", string);
      fprintf(lin, "%s ", string);
      if (!(i % 5)) { // simplificar esse if
        fprintf(lin, "\n");
      }
      i++;
    }
  } else if (feof(pal) && !feof(cod)) {
    while (!feof(cod)) {
      fscanf(cod, "%d ", &num);
      fprintf(lin, "%d ", num);
    }
  }

  fclose(cod);
  fclose(pal);
  fclose(lin);
  return 0;
}
