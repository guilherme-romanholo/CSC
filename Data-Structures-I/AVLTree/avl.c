#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

struct avl {
  int chave;
  struct avl *dir;
  struct avl *esq;
  int fb;
};

int max(int a, int b) { return (a > b) ? a : b; }

int getFB(avl_t *node) {
  if (!node)
      return 0;
  return node->fb;
}

avl_t *rotaciona_esq(avl_t *x) {
  avl_t *y = x->dir;
  avl_t *t2 = y->esq;

  y->esq = x;
  x->dir = t2;

  x->fb = max(getFB(x->dir), getFB(x->esq)) + 1;
  y->fb = max(getFB(y->dir), getFB(y->esq)) + 1;

  return y;
}

avl_t *rotaciona_dir(avl_t *y) {
  avl_t *x = y->esq;
  avl_t *t2 = x->dir;

  x->dir = y;
  y->esq = t2;

  x->fb = max(getFB(x->dir), getFB(x->esq)) + 1;
  y->fb = max(getFB(y->dir), getFB(y->esq)) + 1;

  return x;
}

int fator_balanceamento(avl_t *node) {
  return getFB(node->dir) - getFB(node->esq);
}

avl_t *newNode(int key) {
  avl_t *node = malloc(sizeof(avl_t));

  node->esq = NULL;
  node->dir = NULL;
  node->fb = 0;
  node->chave = key;

  return node;
}

avl_t *menor_valor(avl_t *root) {
  avl_t *no = root;

  while (no->esq != NULL)
    no = no->esq;

  return no;
}

avl_t *insert(avl_t *root, int key) {
  if (root == NULL)
    return newNode(key);

  if (key > root->chave)
    root->dir = insert(root->dir, key);
  else if (key < root->chave)
    root->esq = insert(root->esq, key);
  else
    return root;

  root->fb = 1 + max(getFB(root->esq), getFB(root->dir));

  int balance = fator_balanceamento(root);

  if (balance > 1 && key > (root->dir)->chave) {
    return rotaciona_esq(root);
  } else if (balance > 1 && key < (root->dir)->chave) {
    root->dir = rotaciona_dir(root->dir);
    return rotaciona_esq(root);
  } else if (balance < -1 && key < (root->esq)->chave) {
    return rotaciona_dir(root);
  } else if (balance < -1 && key > (root->esq)->chave) {
    root->esq = rotaciona_esq(root->esq);
    return rotaciona_dir(root);
  }

  return root;
}

avl_t *remocao(avl_t *root, int key) {
  if (root == NULL)
    return root;

  if (key > root->chave) {
    root->dir = remocao(root->dir, key);
  } else if (key < root->chave) {
    root->esq = remocao(root->esq, key);
  } else {
    if (root->dir == NULL || root->esq == NULL) {
      avl_t *aux;

      if (root->dir == NULL)
        aux = root->esq;
      else
        aux = root->dir;

      if (aux == NULL) {
        aux = root;
        root = NULL;
      } else {
        *root = *aux;
      }

      free(aux);
    } else {
      avl_t *aux = menor_valor(root->dir);
      root->chave = aux->chave;
      root->dir = remocao(root->dir, aux->chave);
    }
  }

  if (root == NULL)
    return root;

  root->fb = 1 + max(getFB(root->esq), getFB(root->dir));

  int balance = fator_balanceamento(root);

  if (balance > 1 && getFB(root->dir) <= 0) {
    return rotaciona_esq(root);
  } else if (balance > 1 && getFB(root->dir) > 0) {
    root->dir = rotaciona_dir(root->dir);
    return rotaciona_esq(root);
  } else if (balance < -1 && getFB(root->esq) >= 0) {
    return rotaciona_dir(root);
  } else if (balance < -1 && getFB(root->esq) < 0) {
    root->esq = rotaciona_esq(root->esq);
    return rotaciona_dir(root);
  }

  return root;
}

void preOrder(avl_t *root) {
  if (root) {
    printf("%d\n", root->chave);
    preOrder(root->esq);
    preOrder(root->dir);
  }
}
