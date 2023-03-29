#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *stack, n, aux, cont = 0, soma = 0, k = 0;

  scanf("%d", &n);

  stack = malloc(sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &aux);
    if (aux != 0) {
      cont++;
      stack = realloc(stack, cont * sizeof(int));
      stack[cont - 1] = aux;
    } else {
      if (cont == 0) {
        stack = realloc(stack, sizeof(int));
        stack[0] = 0;
      } else {
        cont--;
        stack = realloc(stack, cont * sizeof(int));
      }
    }
  }
  if (!(cont == 0)) {
    for (int i = 0; i < cont; i++) {
      soma += stack[i];
    }
    printf("%d\n", soma);
  } else {
    printf("0\n");
  }
  return 0;
}
