#ifndef DATABASE_H
#define DATABASE_H 

#include <stdio.h>
#include "index.h"

// Váriaveis globais com o nome dos arquivos
extern const char *iprimary_filename;
extern const char *ititle_filename;
extern const char *database_filename;

// Função para abrir a conexão com o arquivo de dados e ler os indices para a memória
void open_connection(FILE **database, PidxList_t **p_indexes, SidxList_t **s_indexes);
// Função para fechar a conexão com o arquivo de dados e escrever os indices da memória
void close_connection(FILE *database, PidxList_t *p_indexes, SidxList_t *s_indexes);
// Função para criar o arquivo de dados
void create_database_file(FILE **database);
// Função para criar o arquivo de indice primário
void create_iprimary_file(FILE **iprimary);
// Função para criar o arquivo de indice secundário
void create_ititle_file(FILE **ititle);
// Função para mudar a flag nos arquivos de indices
void change_index_status(int flag, const char *filename);
// Função para reconstruir o arquivo de dados fazendo a compatação dele
void rebuild_database(PidxList_t *p_indexes ,FILE **database);

#endif // !DATABASE_H
