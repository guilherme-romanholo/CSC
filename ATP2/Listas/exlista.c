/*
Seja L uma lista simplesmente encadeada composta de números inteiros cujos nós
são l1, l2, l3, ..., ln. Escreva funções para que, percorrendo L, uma única vez,
construa uma outra lista L’ formada dos seguintes elementos:
a) l2, l3, ..., ln, l1;
b) ln, ln‐1 ,...,l1;
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int val;
  struct lista *prox;
} t_list;

t_list *alocar(int val) {
  t_list *aux = malloc(sizeof(t_list));

  aux->val = val;
  aux->prox = NULL;

  return aux;
}

void printList(t_list *h) {
  t_list *aux = h;
  if (h == NULL) {
    puts("Lista vazia!");
    return;
  }
  while (aux != NULL) {
    printf("%d ", aux->val);
    aux = aux->prox;
  }
  printf("\n");
}

void inserir(t_list **h, t_list *new) {
  t_list *atual = *h;
  if ((*h) == NULL) {
    *h = new;
    return;
  }
  while (atual->prox != NULL)
    atual = atual->prox;
  atual->prox = new;
}

void copiaLista(t_list *h, t_list **dest) {
  t_list *aux = h, *new, *resp = NULL;

  while (aux != NULL) {
    new = alocar(aux->val);
    inserir(&resp, new);
    aux = aux->prox;
  }
  *dest = resp;
}

void itemA(t_list **h) {
  t_list *aux = *h, *new;

  while (aux->prox != NULL)
    aux = aux->prox;

  aux->prox = *h;
  new = (*h)->prox;
  (*h)->prox = NULL;
  *h = new;
}

void itemB(t_list *h, t_list **resp) {
  t_list *aux = h, *aux2 = NULL, *new;

  aux2 = aux;
  aux = aux->prox;
  aux2->prox = NULL;

  while (aux != NULL) {
    new = aux;
    aux = aux->prox;
    new->prox = aux2;
    aux2 = new;
  }

  *resp = aux2;
}

int main(int argc, char *argv[]) {
  t_list *head, *new, *listA, *listB, *listAux;
  int opc, val;

  head = new = listA = listB = listAux = NULL;

  for (int i = 0; i < 10; i++) {
    puts("Digite o valor do elemento:");
    scanf("%d", &val);
    new = alocar(val);
    inserir(&head, new);
  }


  copiaLista(head, &listA);
  copiaLista(head, &listAux);

  itemA(&listA);
  itemB(listAux, &listB);

  puts("Lista original:");
  printList(head);
  puts("Lista item A:");
  printList(listA);
  puts("Lista item B:");
  printList(listB);

  return 0;
}
