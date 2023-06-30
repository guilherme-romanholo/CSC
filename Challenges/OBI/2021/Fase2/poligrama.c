#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int tam, letras1[26] = {0}, letras2[26] = {0};
  scanf("%d", &tam);
  char str[tam + 1], aux;
  scanf(" %s", str);

  for (int i = 0; i < (tam / 2); i++) {
    aux = str[i];
    if (letras2[aux - 91] != 1)
      letras1[aux - 91]++;
  }
  for (int i = (tam / 2); i < tam; i++) {
    aux = str[i];
    if (letras2[aux - 91] != 1)
      letras2[aux - 91]++;
  }
  for (int i = 0; i < 26; i++) {
    if (letras1[i] != letras2[i]) {
      printf("*\n");
      break;
    }
  }

  return 0;
}
