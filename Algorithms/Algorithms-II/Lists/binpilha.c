#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int val;
  struct stack *prox;
} t_stack;

void push(t_stack **top, int val) {
  t_stack *aux = malloc(sizeof(t_stack));
  aux->val = val;
  aux->prox = NULL;
  if (top)
    aux->prox = *top;
  *top = aux;
}

int pop(t_stack **top) {
  t_stack *aux = *top;
  int val = aux->val;
  *top = (*top)->prox;
  free(aux);
  return val;
}

int main(int argc, char *argv[]) {
  int num;
  t_stack *top = NULL;
  scanf("%d", &num);
  if (num != 0) {
    while (num) {
      push(&top, num % 2);
      num = num / 2;
    }
    while (top) {
      printf("%d", pop(&top));
    }
  } else {
    printf("0");
  }
  printf("\n");
  return 0;
}
