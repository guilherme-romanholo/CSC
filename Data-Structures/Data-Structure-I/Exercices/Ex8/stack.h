#ifndef STACK_H
#define STACK_H

#include "tree.h"

typedef struct stack stack_t;

void pushStack(stack_t **stack, tree_t *value);
tree_t *popStack(stack_t **stack);
stack_t *newStack(tree_t *value);

#endif // !STACK_H
