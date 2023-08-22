#include <stdio.h>
#include <string.h>

int isPalind(char *str, int ini, int fim) {
  if (ini == fim)
    return 1;
  else if (ini > fim)
    return 1;
  if (str[ini] != str[fim])
    return 0;
  return isPalind(str, ini + 1, fim - 1);
}

void buscar(char *str, int ini, int fim, int *maior) {
  if (fim == 0) {
    return;
  }
  if (ini != fim) {
    if (isPalind(str, ini, fim) && fim - ini + 1 > *maior) {
      *maior = fim - ini + 1;
      buscar(str, ini + 1, fim, maior);
    } else {
      buscar(str, ini + 1, fim, maior);
    }
  } else {
    buscar(str, 0, fim - 1, maior);
  }
}

int main(int argc, char *argv[]) {
  char str[2001];
  int maior = 1;
  scanf(" %s", str);
  buscar(str, 0, strlen(str) - 1, &maior);
  printf("%d\n", maior);
  return 0;
}
