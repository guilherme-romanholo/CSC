#include <stdio.h>
#include <string.h>

int palindromo(int inicio, int fim, char str[]) {
  char aux[5000];
  int j = 0;
  for (int i = inicio; i < fim + 2; i++) {
    aux[j] = str[i];
    j++;
  }
  aux[j] = '\0';
  for (int i = 0, j = fim; i < fim + 1; i++, j--) {
    if (aux[i] != aux[j]) {
      return 0;
    }
  }
  return strlen(aux);
}

int main(int argc, char *argv[]) {
  int tam, maior = 0, aux;
  char palavra[5000];
  printf("Tamanho:\n");
  scanf("%d", &tam);
  printf("Palavra:\n");
  scanf(" %s", palavra);
  for (int i = 0; i < tam; i++) {
    for (int j = i; j <= tam; j++) {
      aux = palindromo(i, j, palavra);
      if (maior < aux) {
        maior = aux;
      }
    }
  }
  printf("%d\n", maior);
  return 0;
}
