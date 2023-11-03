#include "../../include/database.h"
#include "../../include/index.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes para formatação de entrada e saída no arquivo
const char *HEADER_FORMAT = "{Atualizado: %d}\n";
const char *P_FORMAT_OUT = "{PKey: %s, RRN: %d}\n";
const char *P_FORMAT_IN = "{PKey: %[^,], RRN: %d}\n";

// Função para alocar um novo elemento da lista
PidxList_t *new_primary_node(char *pkey, int rrn) {
  // Aloca o elemento novo
  PidxList_t *new_node = malloc(sizeof(PidxList_t));

  // Atribui os valores para ele
  strcpy(new_node->pkey, pkey);
  new_node->rrn = rrn;
  new_node->next = NULL;

  // Retorna o novo elemento
  return new_node;
}

// Insere o novo elemento na lista de maneira ordenada
void insert_primary_node(PidxList_t **head, PidxList_t *new_node) {
  // Caso a lista esteja vazia ou o primeiro elemento seja substituído
  if (*head == NULL || strcmp((*head)->pkey, new_node->pkey) >= 0) {
    // Insere o elemento na cabeça da lista
    new_node->next = *head;
    *head = new_node;
    return;
  }

  PidxList_t *current = *head;

  // Procura o local de inserção do elemento
  while (current->next != NULL && strcmp(current->pkey, new_node->pkey) < 0)
    current = current->next;

  // Insere o elemento no local encontrado
  new_node->next = current->next;
  current->next = new_node;
}

// Remove uma chave da lista de indices primários
void remove_primary_node(PidxList_t **head, char *pkey) {
  PidxList_t *temp = *head, *prev = NULL;

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

// Função para a busca de um índice primário na lista
int pkey_search(PidxList_t *node, char *pkey) {
  int rrn = -1;

  // Realiza uma busca sequencial até achar o elemento
  while (node != NULL) {
    // Caso o elemento seja encontrado, ele guarda o seu rrn
    if (!strcmp(node->pkey, pkey)) {
      rrn = node->rrn;
      break;
    }
    node = node->next;
  }

  // Caso o rrn não seja encontrado ele retorna -1
  return rrn;
}

// Função para ler o arquivo de indíces primários para RAM
void read_pidx_file(PidxList_t **head, FILE *database) {
  // Abre o arquivo de indíces primários
  FILE *iprimary = fopen(iprimary_filename, "r");
  PidxList_t *new_node;
  int flag, rrn;
  char pkey[6];

  // Reliza a leitura do cabeçalho
  fscanf(iprimary, HEADER_FORMAT, &flag);

  // Caso esteja atualizado
  if (flag) {
    // Lê o arquivo de indíces para a memória
    while (fscanf(iprimary, P_FORMAT_IN, pkey, &rrn) != EOF) {
      new_node = new_primary_node(pkey, rrn);
      insert_primary_node(head, new_node);
    }

  } else {
    // Lê diretamente do arquivo de dados
    update_pidx_file(head, database);
  }

  // Fecha o arquivo de indíces
  fclose(iprimary);
}

// Função quando é necessário atualizar o arquivo de indíces
void update_pidx_file(PidxList_t **head, FILE *database) {
  PidxList_t *new_node;
  int rrn = 0;
  char pkey[6];

  // Volta o arquivo de dados para o início
  rewind(database);

  while (fscanf(database, "%[^@]", pkey) != EOF) {
    // Caso o elemento não tenha sido apagado
    if (strstr(pkey, "*|") == NULL) {
      // Insere ele na lista da memória
      new_node = new_primary_node(pkey, rrn);
      insert_primary_node(head, new_node);
    }
    // Adiciona o RRN
    rrn++;
    // Pula para o próximo registro
    fseek(database, rrn * 192, SEEK_SET);
  }
}

// Função para escrever as alterações da memória para o arquivo
void write_pidx_file(PidxList_t *head) {
  // Abre o arquivo para escrita
  FILE *iprimary = fopen(iprimary_filename, "w");
  PidxList_t *previous;

  // Marca o arquivo como atualizado
  fprintf(iprimary, HEADER_FORMAT, 1);

  // Escreve no arquivo todos os elementos da lista
  while (head != NULL) {
    fprintf(iprimary, P_FORMAT_OUT, head->pkey, head->rrn);

    previous = head;
    head = head->next;

    // Libera os elementos da memória
    free(previous);
  }

  // Fecha o arquivo
  fclose(iprimary);
}
