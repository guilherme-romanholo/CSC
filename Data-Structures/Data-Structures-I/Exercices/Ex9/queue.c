#include "queue.h"
#include "tree.h"
#include <stdlib.h>

struct queue {
  tree_t *node;
  struct queue *next;
};

queue_t *newQueue(tree_t *node) {
  queue_t *queue = malloc(sizeof(queue_t));

  queue->next = NULL;
  queue->node = node;

  return queue;
}

void pushQueue(queue_t **queue, tree_t *node) {
  queue_t *new = newQueue(node);
  queue_t *tmp = *queue;
  
  if (*queue == NULL) {
    *queue = new;
    return;
  }

  while (tmp->next != NULL)
    tmp = tmp->next;

  tmp->next = new;
}

tree_t *popQueue(queue_t **queue) {
  queue_t *rem = *queue;
  tree_t *elem = rem->node;

  (*queue) = (*queue)->next;

  free(rem);

  return elem;
}
