#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {
  char val[40];
  struct elemento *prox;
};

struct conjunto {
  char tipo;
  int tam;
  elem_t *elem;
};

void criaConjVazio(conj_t **A) {
  conj_t *newConj = malloc(sizeof(conj_t));
  newConj->tipo = 'n';
  newConj->tam = 0;
  newConj->elem = NULL;
  *A = newConj;
}

char verificaTipo(char *x) {
  int flag, ponto = 0;

  for (int i = 0; i < strlen(x); i++) {
    flag = 0;
    for (char j = 48; j < 58; j++) {
      if (x[i] == j)
        flag = 1;
      if (x[i] == '-' && strlen(x) != 1)
        flag = 1;
      if (x[i] == '.') {
        ponto = 1;
        flag = 1;
      }
    }
    if (!flag) {
      if (strlen(x) == 1)
        return 'c';
      else
        return 's';
    }
  }

  if (ponto)
    return 'f';
  else
    return 'i';
}

void insere(char *x, conj_t **A) {
  int flag = 0;
  elem_t *head = (*A)->elem;
  elem_t *newElem = malloc(sizeof(elem_t));
  strcpy(newElem->val, x);
  newElem->prox = NULL;

  if (head == NULL) {
    (*A)->tipo = verificaTipo(x);
    (*A)->elem = newElem;
    (*A)->tam++;
    return;
  }

  if ((*A)->tipo != verificaTipo(x)) {
    return;
  }

  if (!strcmp(head->val, x)) {
      return;
  }

  while (head->prox != NULL) {
    if (!strcmp(head->val, x)) {
      return;
    }
    head = head->prox;
  }

  if (!strcmp(head->val,x))
    return;

  head->prox = newElem;
  (*A)->tam++;
}

void uniao(conj_t *A, conj_t *B, conj_t **C) {
  if (A->tipo != B->tipo) {
    printf("Os conjuntos possuem tipos diferentes.\n");
    return;
  }

  elem_t *head;
  conj_t *newConj = malloc(sizeof(conj_t));
  newConj->tipo = A->tipo;

  head = A->elem;
  while (head != NULL) {
    insere(head->val, &newConj);
    head = head->prox;
  }
  head = B->elem;
  while (head != NULL) {
    insere(head->val, &newConj);
    head = head->prox;
  }

  *C = newConj;
}

void interseccao(conj_t *A, conj_t *B, conj_t **C) {
  if (A->tipo != B->tipo) {
    printf("Os conjuntos são de tipos diferentes.\n");
    return;
  }

  elem_t *elemA = A->elem, *elemB;
  conj_t *newConj;
  criaConjVazio(&newConj);

  while (elemA != NULL) {
    elemB = B->elem;
    while (elemB != NULL) {
      if (!strcmp(elemA->val, elemB->val))
        insere(elemA->val, &newConj);

      elemB = elemB->prox;
    }
    elemA = elemA->prox;
  }

  if (newConj->tam != 0)
    newConj->tipo = A->tipo;

  *C = newConj;
}

int igual(conj_t *A, conj_t *B) {
  conj_t *uni;

  if (A->tipo != B->tipo || A->tam != B->tam)
    return 0;

  uniao(A, B, &uni);

  if (uni->tam == A->tam) {
    free(uni);
    return 1;
  } else {
    free(uni);
    return 0;
  }
}

int membro(char *x, conj_t *A) {
  elem_t *head = A->elem;

  while (head != NULL) {
    if (!strcmp(head->val, x))
      return 1;
    head = head->prox;
  }
  return 0;
}

void printConjunto(conj_t *A) {
  elem_t *newElem = A->elem;

  printf("Tipo: %c\nTamanho: %d\n",A->tipo, A->tam);
  while (newElem != NULL) {
    printf("%s ", newElem->val);
    newElem = newElem->prox;
  }
  printf("\n");
}