#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct conjunto conj_t;
typedef struct elemento elem_t;

void printConjunto(conj_t *A); // ok
void criaConjVazio(conj_t **A); // ok
void uniao(conj_t *A, conj_t *B, conj_t **C); // ok
void interseccao(conj_t *A, conj_t *B, conj_t **C); // ok
void insere(char *x, conj_t **A); // ok
char verificaTipo(char *x); // ok
int membro(char *x, conj_t *A); // ok
int igual(conj_t *A, conj_t *B); // ok

#endif // !CONJUNTO_H
