#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dynamic {
  char c;
  struct dynamic *prox;
} t_struct;

void pushStack(t_struct **top, char c) {
  t_struct *aux;
  aux = malloc(sizeof(t_struct));
  aux->c = c;
  aux->prox = *top;
  *top = aux;
}

void pushQueue(t_struct **front, t_struct **back, char c) {
  t_struct *new;
  new = malloc(sizeof(t_struct));
  new->c = c;
  new->prox = NULL;

  if (!(*front)) {
    *front = *back = new;
    return;
  }

  (*back)->prox = new;
  *back = new;

  return;
}

char popStack(t_struct **top) {
  t_struct *aux = *top;
  char c = aux->c;
  *top = (*top)->prox;
  free(aux);
  return c;
}

char popQueue(t_struct **front, t_struct **back) {
  t_struct *aux = *front;
  char c = aux->c;
  if (*front == NULL)
    return '0';

  if (*front != *back)
    *front = (*front)->prox;
  else
    *front = *back = NULL;

  free(aux);

  return c;
}

int main(int argc, char *argv[]) {
  t_struct *top, *front, *back;
  char c;
  bool flag = true;

  top = front = back = NULL;

  puts("Digite uma sequência de caracteres, assuma 0 como ponto de parada:");
  while (true) {
    scanf(" %c", &c);
    if (c == '0')
      break;
    pushStack(&top, c);
    pushQueue(&front, &back, c);
  }

  while (top) {
    c = popStack(&top);
    printf("%c", c);
    if (c != popQueue(&front, &back))
      flag = false;
  }

  printf("\n");

  if (flag)
    puts("É palíndromo.");
  else
    puts("Não é palíndromo.");

  return 0;
}
