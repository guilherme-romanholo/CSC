#include "../../include/movie.h"
#include "../../include/database.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constante do tamanho do buffer
const int BUFFER_SIZE = 192;
// Contantes para a formatação do registro na entrada e saída
const char *MOVIE_FORMAT_OUT = "%s@%s@%s@%s@%s@%s@%d@";
const char *MOVIE_FORMAT_IN = "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%d@";

// Função para realizar a serialização do filme no arquivo
size_t serialize_movie(Movie movie, FILE *database) {
  // Aloca um buffer para o novo filme
  char *buffer_out = malloc(sizeof(char) * (BUFFER_SIZE + 1));
  size_t new_rrn;

  // Coloca o ponteiro do arquivo de dados no final
  fseek(database, 0, SEEK_END);

  // Descobre o tamanho total do arquivo
  new_rrn = ftell(database);
  // Divide por 192 para descobrir o rrn
  new_rrn = new_rrn / 192;

  // Bufferiza o novo filme
  bufferize_movie(movie, &buffer_out);

  // Escreve o buffer no arquivo de dados
  fputs(buffer_out, database);

  // Muda o status dos arquivos de indices para desatualizados
  change_index_status(0, iprimary_filename);
  change_index_status(0, ititle_filename);

  // Libera o buffer da memoria
  free(buffer_out);

  // Retorna o rrn do filme adicionado ao arquivo
  return new_rrn;
}

// Função para realizar a deserialização do filme no arquivo
Movie deserialize_movie(int rrn, FILE *database) {
  Movie movie;
  char buffer_in[BUFFER_SIZE];
  // Descobre o byte offset do registro com base no seu rrn
  size_t byte_offset = rrn * BUFFER_SIZE;

  // Navega no arquivo até o registro
  fseek(database, byte_offset, SEEK_SET);

  // Lê o registro do arquivo para um buffer
  fgets(buffer_in, BUFFER_SIZE, database);

  // Faz a leitura do buffer para uma variável do tipo Movie
  sscanf(buffer_in, MOVIE_FORMAT_IN, movie.p_key, movie.br_title, movie.title,
         movie.director, &movie.year, movie.country, &movie.score);

  // Retorna o filme
  return movie;
}

// Função para excluir um filme do arquivo de dados
void delete_movie(FILE *database, int rrn) {
  // Descobre o byte offset do registro com base no seu rrn
  size_t byte_offset = rrn * BUFFER_SIZE;

  // Reabre o arquivo de dados para sobrescrever um registro
  freopen(database_filename, "r+", database);

  // Move o ponteiro do arquivo para o registro
  fseek(database, byte_offset, SEEK_SET);

  // Remove o registro lógicamente
  fputs("*|", database);

  // Marca os arquivos de indices como desatualizados
  change_index_status(0, iprimary_filename);
  change_index_status(0, ititle_filename);
}

// Função para atualizar a nota no arquivo de dados
void update_score(FILE *database, int rrn, int score) {
  // Faz a leitura do filme que será alterado
  Movie movie = deserialize_movie(rrn, database);
  // Aloca o buffer para o filme
  char *buffer_out = malloc(sizeof(char) * (BUFFER_SIZE + 1));
  // Calcula o byte offset do registro
  size_t byte_offset = rrn * BUFFER_SIZE;

  // Reabre o arquivo de dados para sobrescrever
  freopen(database_filename, "r+", database);

  // Atribui a nova nota ao filme
  movie.score = score;

  // Bufferiza o filme com a nova nota
  bufferize_movie(movie, &buffer_out);

  // Navega até a posição do filme no arquivo
  fseek(database, byte_offset, SEEK_SET);

  // Escreve o novo registro bufferizado no arquivo
  fputs(buffer_out, database);

  // Muda os status do arquivos de indices para desatualizados
  change_index_status(0, iprimary_filename);
  change_index_status(0, ititle_filename);

  // Libera o buffer
  free(buffer_out);
}

// Função para bufferizar um filme
void bufferize_movie(Movie movie, char **buffer_out) {
  // Escreve o filme serializado e formatado no buffer
  sprintf(*buffer_out, MOVIE_FORMAT_OUT, movie.p_key, movie.br_title,
          movie.title, movie.director, movie.year, movie.country, movie.score);

  // Preenche o restante do buffer com '#'
  for (size_t i = strlen(*buffer_out); i < BUFFER_SIZE; i++)
    (*buffer_out)[i] = '#';

  // Encerra o buffer com '\0'
  (*buffer_out)[BUFFER_SIZE] = '\0';
}

// Função para fazer a chave primária de um filme
void make_pkey(Movie *movie) {
  // Pega as 3 primeiras letras do sobrenome do diretor
  for (size_t i = 0; i < 3; i++)
    movie->p_key[i] = toupper(movie->director[i]);

  // Pega os dois ultimos digitos do ano
  movie->p_key[3] = movie->year[2];
  movie->p_key[4] = movie->year[3];
  // Encerra a string
  movie->p_key[5] = '\0';
}
