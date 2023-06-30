#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define m 3

int cmp(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
  int n, borrado, palavra, l = 0, k = 0, cont = 0;
  scanf("%d %d %d", &n, &borrado, &palavra);
  char senha[n];
  char aux[n];
  char aux2[n];
  char teste[borrado][palavra + 1];
  char comb[borrado * palavra][palavra + 1];
  char senhas[borrado * palavra][n + 1];
  scanf(" %s", senha);

  for (int i = 0; i < borrado; i++) {
    scanf(" %s", teste[i]);
  }

  for (int i = 0; i < borrado; i++) {
    for (int j = 0; teste[i][j] != '\0'; j++) {
      comb[k][j] = teste[j][i];
    }
    comb[k][palavra] = '\0';
  }
  k = 0;
  if (borrado > 1) {
    for (int i = 0; i < borrado * palavra; i++) {
      strcpy(aux, senha);
      for (int j = 0; aux[j] != '\0'; j++) {
        if (aux[j] == '#') {
          aux[j] = comb[l][k];
          k++;
        }
      }
      strcpy(senhas[i], aux);
      l += 1;
      k = 0;
    }
  }

  for (int i = 0; i < borrado * palavra; i++) {
    printf("%s\n", senhas[i]);
  }
  return 0;
}
