#include "stack.h"
#include "tree.h"
#include <stdlib.h>

struct stack {
  tree_t *value;
  struct stack *next;
};

stack_t *newStack(tree_t *value) {
  stack_t *stack = malloc(sizeof(stack_t));

  stack->next = NULL;
  stack->value = value;

  return stack;
}

void pushStack(stack_t **stack, tree_t *value) {
  stack_t *newTop = newStack(value);

  if (*stack == NULL){
    (*stack) = newTop;
    return;
  }

  newTop->next = (*stack);

  (*stack) = newTop;
}

tree_t *popStack(stack_t **stack) {
  tree_t *value = (*stack)->value;
  stack_t *rem = (*stack);

  *stack = (*stack)->next;

  free(rem);

  return value;
}
