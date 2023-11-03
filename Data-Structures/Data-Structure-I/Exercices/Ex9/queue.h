#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

typedef struct queue queue_t;

queue_t *newQueue(tree_t *node);
void pushQueue(queue_t **queue, tree_t *node);
tree_t *popQueue(queue_t **queue);

#endif // !QUEUE_H
