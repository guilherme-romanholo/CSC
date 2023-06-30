#ifndef TREE_H
#define TREE_H

typedef struct no no;

int vazia(no *raiz);
no *cria_no(char c, no *esq, no *dir);
int insere_esq(no *pai, char elemento);
void imprime_arvore(no *raiz);

#endif // !TREE_H
