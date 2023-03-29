#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int num;
  struct stack *prox;
} stack_t;

void push(stack_t **top, int num) {
  stack_t *aux = malloc(sizeof(stack_t));
  aux->num = num;
  aux->prox = *top;
  *top = aux;
}

void pop(stack_t **top, stack_t **atual) {
  stack_t *aux, *prev;
  aux = prev = *top;
  if (*atual == NULL)
    return;
  if (*atual == *top) {
    *top = (*top)->prox;
    free(*atual);
    *atual = *top;
    return;
  }
  while (aux != *atual) {
    prev = aux;
    aux = aux->prox;
  }
  prev->prox = aux->prox;
  free(aux);
  *atual = prev->prox;
}

void debug(stack_t *top) {
  while (top) {
    printf("%d ", top->num);
    top = top->prox;
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int num;
  stack_t *top = NULL, *aux, *prev;
  do {
    puts("Insira um elemento na pilha, 0 para cancelar.");
    scanf("%d", &num);
    push(&top, num);
  } while (num != 0);

  debug(top);

  puts("Digite um número para todos os menores serem retirados:");
  scanf("%d", &num);

  aux = top;
  while (aux) {
    prev = aux;
    if (aux->num < num)
      pop(&top, &aux);
    else
      aux = aux->prox;
  }

  debug(top);

  return 0;
}
