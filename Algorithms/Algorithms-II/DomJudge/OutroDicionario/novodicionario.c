#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
  char pal[1000];
  struct list *prox;
} t_list;

t_list *insere(t_list *h, t_list *new);
void deleta(t_list **h, char *str);
void printList(t_list *h);
void cadastra(t_list **new, char *str);
void busca(t_list *h, char *str);

int main(int argc, char *argv[]) {
  int n, m, i, opc;
  char str[1000];
  t_list *new, *lista = NULL;

  scanf("%d %d", &n, &m);

  for (i = 0; i < n; i++) {
    scanf(" %s", str);
    cadastra(&new, str);
    lista = insere(lista, new);
  }
  for (i = 0; i < m; i++) {
    scanf("%d %s", &opc, str);
    if (opc == 1) {
      cadastra(&new, str);
      lista = insere(lista, new);
    } else if (opc == 0) {
      deleta(&lista, str);
    } else {
      busca(lista, str);
    }
  }

  return 0;
}

void busca(t_list *h, char *str) {
  t_list *aux = h;
  while (aux != NULL && strcmp(aux->pal, str) < 0)
    aux = aux->prox;
  printList(aux);
}

void cadastra(t_list **new, char *str) {
  t_list *aux = malloc(sizeof(t_list));
  strcpy(aux->pal, str);
  aux->prox = NULL;
  *new = aux;
}

t_list *insere(t_list *h, t_list *new) {
  t_list *aux, *antes;
  if (h == NULL) {
    h = new;
    return h;
  }
  aux = antes = h;
  while (aux->prox && strcmp(new->pal, aux->pal) > 0) {
    antes = aux;
    aux = aux->prox;
  }
  if (aux == h) {
    if (strcmp(new->pal, aux->pal) > 0) {
      new->prox = aux->prox;
      h->prox = new;
      return h;
    } else if (strcmp(new->pal, aux->pal) < 0) {
      new->prox = h;
      return new;
    } else {
      return h;
    }
  }
  if (strcmp(new->pal, aux->pal) > 0) {
    aux->prox = new;
  } else if (strcmp(new->pal, aux->pal) < 0) {
    new->prox = aux;
    antes->prox = new;
  } else {
    return h;
  }
  return h;
}

void deleta(t_list **h, char *str) {
  t_list *aux = *h, *antes;
  if (aux != NULL && strcmp(aux->pal, str) == 0) {
    *h = aux->prox;
    free(aux);
    return;
  }
  while (aux != NULL && strcmp(aux->pal, str) != 0) {
    antes = aux;
    aux = aux->prox;
  }
  if (aux == NULL)
    return;
  antes->prox = aux->prox;
  free(aux);
}

void printList(t_list *h) {
  t_list *aux = h;

  if (aux == NULL) {
    printf("NULL");
  }
  while (aux) {
    printf("%s ", aux->pal);
    aux = aux->prox;
  }
  printf("\n");
}
