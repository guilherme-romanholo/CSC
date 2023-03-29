#include <iostream>

using namespace std;

typedef struct list {
  int val;
  struct list *next;
} list_t;

void insert(list_t **head, int val) {
  list_t *elem = new list_t;
  list_t *aux = *head;

  elem->val = val;
  elem->next = NULL;

  if (*head == NULL) {
    *head = elem;
    return;
  }

  while (aux->next != NULL)
    aux = aux->next;

  aux->next = elem;
}

int main(int argc, char *argv[]) {
  list_t *l1, *l2, *l3;

  l1 = l2 = l3 = NULL;

  return 0;
}
