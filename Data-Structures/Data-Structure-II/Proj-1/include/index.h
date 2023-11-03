#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>

// Variavéis globais que guardar a formatação de 
// entrada e saida dos arquivos
extern const char *HEADER_FORMAT;
extern const char *P_FORMAT_OUT;
extern const char *P_FORMAT_IN;
extern const char *S_FORMAT_OUT;
extern const char *S_FORMAT_IN;

// Linked List dos indices primários
typedef struct primary_node {
  char pkey[6];
  int rrn;
  struct primary_node *next;
} PidxList_t;

// Linked List dos indices secundários
typedef struct secondary_node {
  char br_title[100];
  char pkey[6];
  struct secondary_node *next;
} SidxList_t;

// Funções para alocar um novo nó de indice
PidxList_t *new_primary_node(char *pkey, int rrn);
SidxList_t *new_secondary_node(char *pkey, char *br_title);
// Funções para realizar a busca dos indices
int pkey_search(PidxList_t *node, char *pkey);
int *title_search(PidxList_t *p_node, SidxList_t *s_node, char *br_title);
// Funções para inserir um novo indice na lista
void insert_primary_node(PidxList_t **head, PidxList_t *new_node);
void insert_secondary_node(SidxList_t **head, SidxList_t *new_node);
// Funções para remover um indice da lista
void remove_primary_node(PidxList_t **head, char *pkey);
void remove_secondary_node(SidxList_t **head, char *pkey);
// Funções para ler os arquivos de indices
void read_pidx_file(PidxList_t **head, FILE *database);
void read_title_file(SidxList_t **head, FILE *database);
// Funções para atualizar os arquivos de indices
void update_pidx_file(PidxList_t **head, FILE *database);
void update_title_file(SidxList_t **head, FILE *database);
// Funções para escrever as alterações nos arquivos de indices
void write_pidx_file(PidxList_t *head);
void write_title_file(SidxList_t *head);
// Funções de debug para printar as listas
void print_title_list(SidxList_t *node);

#endif // !INDEX_H
