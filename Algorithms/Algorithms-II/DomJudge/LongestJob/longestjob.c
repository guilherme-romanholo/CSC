#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int tempo;
  int carga;
  struct list *prox;
} t_list;

t_list *cadastra() {
  t_list *aux = malloc(sizeof(t_list));
  scanf("%d", &aux->tempo);
  scanf("%d", &aux->carga);
  aux->prox = NULL;
  return aux;
}

t_list *insert(t_list *h, t_list *new) {
  t_list *aux, *antes;
  if (h == NULL)
    return new;

  aux = antes = h;

  while (aux->prox && new->tempo > aux->tempo) {
    antes = aux;
    aux = aux->prox;
  }

  if (aux == h) {
    if (new->tempo > aux->tempo) {
      new->prox = h->prox;
      h->prox = new;
      return h;
    } else {
      new->prox = h;
      return new;
    }
  }

  if (new->tempo > aux->tempo) {
    new->prox = aux->prox;
    aux->prox = new;
  } else {
    new->prox = aux;
    antes->prox = new;
  }
  return h;
}

void deleta(t_list **h, int carga, int tempo) {
  t_list *aux = *h, *antes;
  if (aux != NULL && aux->tempo == tempo && aux->carga == carga) {
    *h = aux->prox;
    free(aux);
    return;
  }
  while (aux != NULL && aux->tempo != tempo && aux->carga != carga) {
    antes = aux;
    aux = aux->prox;
  }
  if (aux == NULL)
    return;
  antes->prox = aux->prox;
  free(aux);
}

int busca(t_list *h, int ini, int *tempoaux) {
  t_list *aux = h;
  int maior = 0;
  while (aux && aux->tempo <= ini) {
    if (aux->carga > maior) {
      maior = aux->carga;
      *tempoaux = aux->tempo;
    } else if (aux->carga == maior) {
      if (*tempoaux > aux->tempo) {
        *tempoaux = aux->tempo; 
      }
    }
    aux = aux->prox;
  }
  return maior;
}

int main(int argc, char *argv[]) {
  int N, i, inicio = 10001, maior, tempoaux;
  t_list *lista = NULL, *new;
  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    new = cadastra();
    if (new->tempo < inicio)
      inicio = new->tempo;
    lista = insert(lista, new);
  }

  while (lista) {
    maior = busca(lista, inicio, &tempoaux);
    if (maior == 0) {
      inicio = lista->tempo;
      maior = busca(lista, inicio, &tempoaux);
    }
    deleta(&lista, maior, tempoaux);
    printf("%d ", maior);
    inicio += maior;
  }

  printf("\n");

  return 0;
}

