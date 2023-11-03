#include "../../include/database.h"
#include "../../include/index.h"
#include "../../include/movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nome dos arquivos usados no projeto
const char *iprimary_filename = "iprimary.idx";
const char *ititle_filename = "ititle.idx";
const char *database_filename = "movies.dat";

// Função para abrir a conexão com os arquivos de dados
void open_connection(FILE **database, PidxList_t **p_indexes,
                     SidxList_t **s_indexes) {
  FILE *iprimary;
  FILE *ititle;

  // Abre a conexão com o arquivo de dados
  *database = fopen(database_filename, "a+");

  // Verifica se o arquivo de indices primários existe
  if ((iprimary = fopen(iprimary_filename, "r")) == NULL)
    create_iprimary_file(&iprimary);

  // Verifica se o arquivo de indices secundários existe
  if ((ititle = fopen(ititle_filename, "r")) == NULL)
    create_ititle_file(&ititle);

  // Fecha os arquivos criados
  fclose(iprimary);
  fclose(ititle);

  // Lê o arquivo de indices primários para a memória
  read_pidx_file(p_indexes, *database);
  // Lê o arquivo de indices secundários para a memória
  read_title_file(s_indexes, *database);
}

// Função para encerrar a conexão com os arquivos
void close_connection(FILE *database, PidxList_t *p_indexes,
                      SidxList_t *s_indexes) {

  // Escreve os dados da memória nos arquivos de indices
  write_pidx_file(p_indexes);
  write_title_file(s_indexes);

  // Fecha o arquivo de dados
  fclose(database);

  // Muda o status dos arquivos para atualizado
  change_index_status(1, iprimary_filename);
  change_index_status(1, ititle_filename);
}

// Função para criar o arquivo de indices primários
void create_iprimary_file(FILE **iprimary) {
  // Cria o arquivo de indíces primários
  *iprimary = fopen(iprimary_filename, "w");

  // Escreve ele como atualizado
  fprintf(*iprimary, HEADER_FORMAT, 0);
}

// Função para criar o arquivo de indices secundários
void create_ititle_file(FILE **ititle) {
  // Cria o arquivo de indíces primários
  *ititle = fopen(ititle_filename, "w");

  // Escreve ele como atualizado
  fprintf(*ititle, HEADER_FORMAT, 0);
}

// Função para mudar o status dos arquivos de indices
void change_index_status(int flag, const char *filename) {
  // Abre o arquivo para leitura/escrita
  FILE *index_file = fopen(filename, "r+");
  char header_buffer[18];

  // Retorna o ponteiro do arquivo para o início
  rewind(index_file);

  // Escreve no buffer a formatação com a flag fornecida
  sprintf(header_buffer, HEADER_FORMAT, flag);

  // Printa a nova flag de atualização no arquivo
  fputs(header_buffer, index_file);

  // Fecha o arquivo
  fclose(index_file);
}

// Função para compactar o arquivo de dados
void rebuild_database(PidxList_t *p_indexes, FILE **database) {
  // Abre um arquivo temporário
  FILE *new_database = fopen("temp.dat", "w");
  Movie movie;

  // Retorna o ponteiro da base de dados para o início
  rewind(*database);

  // Realiza a leitura dos indices guardados na memória
  while (p_indexes != NULL) {
    // Faz a leitura do registro do filme do arquivo antigo
    movie = deserialize_movie(p_indexes->rrn, *database);
    // Escreve o registro no arquivo novo
    serialize_movie(movie, new_database);
    // Passa para o próximo registro
    p_indexes = p_indexes->next;
  }

  // Fecha o arquivo de dados e o temporário
  fclose(*database);
  fclose(new_database);

  // Apaga o arquivo de dados antigo
  remove("movies.dat");

  // Renomeia o novo arquivo temporário
  rename("temp.dat", "movies.dat");

  // Troca o ponteiro do arquivo de dados para o novo arquivo
  *database = fopen("movies.dat", "a+");
}
