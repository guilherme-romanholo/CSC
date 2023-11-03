#include "../../include/index.h"
#include "../../include/database.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes para formatação de entrada e saída no arquivo
const char *S_FORMAT_OUT = "{Title: %s, Pkey: %s}\n";
const char *S_FORMAT_IN = "{Title: %[^,], Pkey: %[^}]}\n";

// ????
void print_title_list(SidxList_t *node) {
  puts("Chave | Título");

  while (node != NULL) {
    printf("%s | %s\n", node->pkey, node->br_title);
    node = node->next;
  }
}

// Função para alocar um novo elemento da lista
SidxList_t *new_secondary_node(char *pkey, char *br_title) {
  // Aloca o elemento novo
  SidxList_t *new_node = malloc(sizeof(SidxList_t));

  // Atribui os valores para ele
  strcpy(new_node->pkey, pkey);
  strcpy(new_node->br_title, br_title);
  new_node->next = NULL;

  // Retorna o novo elemento
  return new_node;
}

// Insere o novo elemento na lista de maneira ordenada
void insert_secondary_node(SidxList_t **head, SidxList_t *new_node) {
  // Caso a lista esteja vazia ou o primeiro elemento seja substituído
  if (*head == NULL || strcmp((*head)->br_title, new_node->br_title) >= 0) {
    // Insere o elemento na cabeça da lista
    new_node->next = *head;
    *head = new_node;
    return;
  }

  SidxList_t *current = *head;

  // Procura o local de inserção do elemento
  while (current->next != NULL && strcmp(current->br_title, new_node->br_title) < 0)
    current = current->next;

  // Insere o elemento no local encontrado
  new_node->next = current->next;
  current->next = new_node;
}

// Remove uma chave da lista de indices secundários
void remove_secondary_node(SidxList_t **head, char *pkey) {
  SidxList_t *temp = *head, *prev = NULL;

  // Caso o elemento removido esteja na cabeça da lista
  if (temp != NULL && strcmp(temp->pkey, pkey) == 0) {
    *head = temp->next;
    free(temp);
    return;
  }

  // Procura o elemento a ser removido
  while (temp != NULL && strcmp(temp->pkey, pkey)) {
    prev = temp;
    temp = temp->next;
  }

  // Caso o elemento não seja encontrado
  if (temp == NULL) {
    return;
  }

  // Tira o apontamento do elemento
  prev->next = temp->next;

  // Libera o elemento da memória
  free(temp);
}

// Função para a busca de um índice secundário na lista
int *title_search(PidxList_t *p_node, SidxList_t *s_node, char *br_title) {
  int *rrn;

  // Aloca um vetor de um elemento onde na primeira
  // posição serão armazenados o número de filmes 
  // encontrados com o título procurado
  rrn = malloc(sizeof(int));
  rrn[0] = 0;

  // Procura filmes como o mesmo título na lista
  while (s_node != NULL) {
    // Caso encontre, adiciona o elemento no vetor de rrn
    if (!strcasecmp(s_node->br_title, br_title)) {
      rrn[0]++;
      rrn = realloc(rrn, sizeof(int) * (rrn[0] + 1));

      rrn[rrn[0]] = pkey_search(p_node, s_node->pkey);
    }
    s_node = s_node->next;
  }

  // Retorna o vetor
  return rrn;
}

// Função para ler o arquivo de indíces secundários para RAM
void read_title_file(SidxList_t **head, FILE *database) {
  // Abre o arquivo de indíces secundários
  FILE *ititle = fopen(ititle_filename, "r");
  SidxList_t *new_node;
  int flag;
  char pkey[6], br_title[100];

  // Reliza a leitura do cabeçalho
  fscanf(ititle, HEADER_FORMAT, &flag);

  // Caso esteja atualizado
  if (flag) {
    // Lê o arquivo de indíces
    while (fscanf(ititle, S_FORMAT_IN, br_title, pkey) != EOF) {
      new_node = new_secondary_node(pkey, br_title);
      insert_secondary_node(head, new_node);
    }

  } else {
    // Lê diretamente do arquivo de dados
    update_title_file(head, database);
  }

  // Fecha o arquivo de indíces
  fclose(ititle);
}

// Função quando é necessário atualizar o arquivo de indíces
void update_title_file(SidxList_t **head, FILE *database) {
  SidxList_t *new_node;
  int rrn = 0;
  char pkey[6], br_title[100];

  // Volta o arquivo de dados para o início
  rewind(database);

  while (fscanf(database, "%[^@]@%[^@]", pkey, br_title) != EOF) {
    // Caso o elemento não tenha sido apagado
    if (strstr(pkey, "*|") == NULL) {
      // Insere ele na lista de indices secundários
      new_node = new_secondary_node(pkey, br_title);
      insert_secondary_node(head, new_node);
    }
    // Adiciona o RRN
    rrn++;
    // Pula para o próximo registro
    fseek(database, rrn * 192, SEEK_SET);
  }
}

// Função para escrever as alterações da memória para o arquivo
void write_title_file(SidxList_t *head) {
  // Abre o arquivo para escrita
  FILE *ititle = fopen(ititle_filename, "w");
  SidxList_t *previous;

  // Marca o arquivo como atualizado
  fprintf(ititle, HEADER_FORMAT, 1);

  // Escreve no arquivo todos os elementos da lista
  while (head != NULL) {
    fprintf(ititle, S_FORMAT_OUT, head->br_title, head->pkey);

    previous = head;
    head = head->next;

    // Libera os elementos da memória
    free(previous);
  }

  // Fecha o arquivo
  fclose(ititle);
}
