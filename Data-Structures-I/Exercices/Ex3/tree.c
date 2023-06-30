#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
  char info;
  struct no *dir;
  struct no *esq;
};

int vazia(no *raiz) { return (raiz == NULL); }

no *cria_no(char c, no *esq, no *dir) {
  no *novo = malloc(sizeof(no));

  novo->info = c;
  novo->dir = dir;
  novo->esq = esq;

  return novo;
}

int insere_esq(no *pai, char elemento) {
  if (pai->esq != NULL)
    return 0;

  pai->esq = cria_no(elemento, NULL, NULL);

  return 1;
}

void imprime_arvore(no *raiz) {
  if (raiz != NULL) {
    printf("%c\n", raiz->info);
    imprime_arvore(raiz->esq);
    imprime_arvore(raiz->dir);
  }
}
