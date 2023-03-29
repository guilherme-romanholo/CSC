#include <stdio.h>
#include <stdlib.h>

typedef struct dinamica {
  int age;
  int time;
  int priority;
  struct dinamica *next;
} struct_t;

struct_t *alloc(int, int, int);
struct_t *pop(struct_t **);
struct_t *sorted_insert(struct_t *, struct_t *);
void priority_insert(struct_t **, struct_t *);
void printList(struct_t *);

int main(int argc, char *argv[]) {
  int n, age, time, count = 0, start_time = 0;
  struct_t *sorted_list, *new, *queue;

  sorted_list = queue = NULL;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &age, &time);
    if (age <= 59)
      new = alloc(age, time, 0);
    else
      new = alloc(age, time, age - 59);
    sorted_list = sorted_insert(sorted_list, new);
  }

  time = sorted_list->time;
  start_time = time;

  while (sorted_list != NULL) {

    if (time == start_time + 3) {
      new = pop(&queue);
      free(new);
      if (queue != NULL)
        queue->priority = 100;
      start_time = time;
    }

    if (time == sorted_list->time) {
      if (queue == NULL)
        start_time = time;
      while (sorted_list != NULL && time == sorted_list->time) {
        new = pop(&sorted_list);
        priority_insert(&queue, new);
      }
      queue->priority = 100;
      printList(queue);
    }

    time++;
  }

  return 0;
}

void priority_insert(struct_t **head, struct_t *new) {
  struct_t *current;
  if (*head == NULL || ((*head)->priority <= new->priority &&new->priority != 0)) {
    new->next = *head;
    *head = new;
  } else {
    current = *head;
    while (current->next != NULL && (current->next)->priority >= new->priority) {
      current = current->next;
    }
    new->next = current->next;
    current->next = new;
  }
}

struct_t *pop(struct_t **head) {
  struct_t *aux = *head;
  if (*head == NULL)
    return NULL;
  *head = (*head)->next;
  return aux;
}

struct_t *sorted_insert(struct_t *h, struct_t *new) {
  struct_t *aux, *antes;
  if (h == NULL) {
    h = new;
    return h;
  }
  aux = antes = h;
  while (aux->next && new->time >= aux->time) {
    antes = aux;
    aux = aux->next;
  }
  if (aux == h) {
    if (new->time > aux->time) {
      new->next = aux->next;
      h->next = new;
      return h;
    } else if (new->time < aux->time) {
      new->next = h;
      return new;
    } else {
      if (new->priority > aux->priority) {
        new->next = h;
        return new;
      } else {
        new->next = aux->next;
        h->next = new;
        return h;
      }
    }
  }
  if (new->time > aux->time) {
    new->next = aux->next;
    aux->next = new;
  } else if (new->time < aux->time) {
    new->next = aux;
    antes->next = new;
  } else {
    if (new->priority > aux->priority) {
      new->next = aux;
      antes->next = new;
    } else {
      new->next = aux->next;
      aux->next = new;
    }
  }
  return h;
}

struct_t *alloc(int age, int time, int priority) {
  struct_t *new = malloc(sizeof(struct_t));
  new->age = age;
  new->time = time;
  new->priority = priority;
  new->next = NULL;
  return new;
}

void printList(struct_t *head) {
  struct_t *aux = head;
  while (aux != NULL) {
    printf("%d ", aux->age);
    aux = aux->next;
  }
  printf("\n");
}
