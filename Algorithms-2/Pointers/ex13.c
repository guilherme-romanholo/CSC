#include <stdio.h>
#include <string.h>

int compara(char *str, char *sub) {
  int i, j = 0, len = strlen(str), lensub = strlen(sub);

  for (i = 0; i < len; i++) {
    if (str[i] == sub[j]) {
      j++;
    } else {
      j = 0;
    }
    if (j == lensub) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  char str[20], sub[20], aux[20];
  int i, len;

  scanf(" %[^\n]s", str);
  scanf(" %[^\n]s", sub);

  if (compara(str, sub)) {
    printf("Sim\n");
  } else {
    printf("Não\n");
  }
  return 0;
}
