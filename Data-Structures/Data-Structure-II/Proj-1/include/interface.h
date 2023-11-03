#ifndef INTERFACE_H
#define INTERFACE_H
// Biblioteca para todas as operações realacionadas
// ao front end do programa

#include "movie.h"
#include "index.h"

// Função para registrar um novo filme
void register_movie_UI(FILE *database, PidxList_t **p_indexes, SidxList_t **s_indexes);
// Função para buscar um novo filme
void search_movie_UI(FILE *database, PidxList_t *p_indexes, SidxList_t *s_indexes);
// Função encapsulada para buscar pelo indice primário
void search_movie_pkey_UI(FILE *database, PidxList_t *p_indexes);
// Função encapsulada para buscar pelo indice secundário
void search_movie_title_UI(FILE *database, PidxList_t *p_indexes, SidxList_t *s_indexes);
// Função para remover um filme pela chave primária
void remove_movie_pkey_UI(PidxList_t **p_node, SidxList_t **s_node, FILE *database);
// Função para atualizar a nota do filme
void update_score_pkey_UI(PidxList_t *p_indexes, FILE *database);
// Função para imprimir o filme
void print_movie_UI(Movie movie);
// Função para listar os filmes
void list_movies_UI(PidxList_t *p_indexes, SidxList_t *s_indexes, FILE *database);
// Função para compactar o arquivo de dados
void refactor_database_UI(PidxList_t *p_indexes, FILE **database);
// Finção para printar as opções
void print_options_UI();
// Pausa a tela
void pause_screen_UI();
// Limpa a tela
void clear_screen_UI();

#endif // !INTERFACE_H
