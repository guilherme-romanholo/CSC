#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
  char pal[100000];
  struct list *prox;
} t_list;

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

t_list *cadastra(char *str) {
  t_list *aux;
  aux = malloc(sizeof(t_list));
  strcpy(aux->pal, str);
  aux->prox = NULL;
  return aux;
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
}

int main(int argc, char *argv[]) {
  int N, M, i, opc;
  char str[1000000];
  t_list *lista = NULL, *new;

  scanf("%d %d", &N, &M);

  for (i = 0; i < N; i++) {
    scanf(" %s", str);
    new = cadastra(str);
    lista = insere(lista, new);
  }

  for (i = 0; i < M; i++) {
    scanf("%d %s", &opc, str);
    if (opc == 1) {
      new = cadastra(str);
      lista = insere(lista, new);
    } else {
      deleta(&lista, str);
      printList(lista);
      printf("\n");
    }
  }

  return 0;
}
