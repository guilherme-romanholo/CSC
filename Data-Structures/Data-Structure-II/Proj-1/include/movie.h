#ifndef MOVIE_H
#define MOVIE_H
// Biblioteca para todas as operações realacionadas
// ao back end do programa

#include <stddef.h>
#include <stdio.h>

#define MAX_STRING 100
#define MAX_PKEY 6

// Variavéis globais que guardar a formatação de 
// entrada e saida do arquivo
extern const char *MOVIE_FORMAT_OUT;
extern const char *MOVIE_FORMAT_IN;

// Estrutura referente ao filme
typedef struct movie {
  // Chave primária
  char p_key[MAX_PKEY];
  // Títulos do filme
  char br_title[MAX_STRING];
  char title[MAX_STRING];
  // Diretor do filme
  char director[MAX_STRING];
  // País de origem
  char country[MAX_STRING];
  // Nota
  int score;
  // Ano de lançamento
  char year[5];
} Movie;

// Função para serializar um filme
size_t serialize_movie(Movie movie, FILE *database);
// Função para ler um filme do arquivo
Movie deserialize_movie(int rrn, FILE *database);
// Função para deletar o filme
void delete_movie(FILE *database, int rrn);
// Função encapsulada para ler o filme para um buffer
void bufferize_movie(Movie movie, char **buffer_out);
// Função para alterar a nota de um filme
void update_score(FILE *database, int rrn, int score);
// Função para criar a chave primária
void make_pkey(Movie *movie);

#endif // !MOVIE_H
