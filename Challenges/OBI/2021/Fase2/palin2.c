#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int tam, resp = 0;
  char palavra[501];
  bool palindromo;

  printf("Tamanho:\n");
  scanf("%d", &tam);
  printf("Palavra:\n");
  scanf(" %s", palavra);

  for (int i = 0; i < tam; i++) {
    for (int j = i; j < tam; j++) {
      palindromo = true;

      for (int pi = i, pf = j; pi <= pf; pi++, pf--) {
        if (palavra[pi] != palavra[pf]) {
          palindromo = false;
        }
      }

      if (palindromo && resp < j - i + 1) {
        resp = j - i + 1;
      }
    }
  }

  printf("%d\n", resp);
  return 0;
}
