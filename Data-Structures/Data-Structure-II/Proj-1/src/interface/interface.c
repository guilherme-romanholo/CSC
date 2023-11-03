#include "../../include/interface.h"
#include "../../include/database.h"
#include "../../include/index.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define CLEAR "clear"

// Função para registrar um novo filme
void register_movie_UI(FILE *database, PidxList_t **p_indexes,
                       SidxList_t **s_indexes) {
  Movie movie;
  size_t rrn;
  PidxList_t *p_node;
  SidxList_t *s_node;

  // Recebe como entrada as informações referentes ao filme
  puts("Digite o título em português do filme:");
  scanf(" %[^\n]", movie.br_title);
  puts("Digite o título original do filme:");
  scanf(" %[^\n]", movie.title);
  puts("Digite o nome do autor: (Sobrenome, Nome)");
  scanf(" %[^\n]", movie.director);
  puts("Digite o país de gravação:");
  scanf(" %[^\n]", movie.country);
  puts("Digite o ano de lançamento:");
  scanf(" %s", movie.year);
  puts("Digite a nota do filme:");
  scanf("%d", &movie.score);

  // Cria uma chave primária para o filme
  make_pkey(&movie);

  // Serializa o filme no arquivo de dados
  rrn = serialize_movie(movie, database);

  // Insere o novo filme na lista de índices primários
  p_node = new_primary_node(movie.p_key, rrn);
  insert_primary_node(p_indexes, p_node);

  // Insere o novo filme na lista de índices secundários
  s_node = new_secondary_node(movie.p_key, movie.br_title);
  insert_secondary_node(s_indexes, s_node);
}

// Função para listar os filmes
void list_movies_UI(PidxList_t *p_indexes, SidxList_t *s_indexes,
                    FILE *database) {
  char pkey[6];
  int rrn;
  Movie movie;

  // Printa a lista de indíces secundários com todos os filmes
  print_title_list(s_indexes);

  // Escolhe um filme para ver com detalhes
  puts("Digite o chave do filme para ver os detalhes:");
  scanf(" %s", pkey);

  // Procura a chave na lista de indices primários
  rrn = pkey_search(p_indexes, pkey);

  // Lê o filme do arquivo
  if (rrn == -1) {
    puts("Filme não encontrado!");
  } else {
    movie = deserialize_movie(rrn, database);
    // Printa as informações do filme
    print_movie_UI(movie);
  }
}

// Função para pesquisar por um filme
void search_movie_UI(FILE *database, PidxList_t *p_indexes,
                     SidxList_t *s_indexes) {
  int op;

  // O usuário escolhe como ele quer pesquisar o filme
  puts("Como você deseja procurar o filme?");
  puts("(1) Chave Primária\n(2) Título em Português");
  scanf("%d", &op);

  if (op == 1) {
    // Procura com base na chave primária
    search_movie_pkey_UI(database, p_indexes);
  } else {
    // Procura com base na chave secundária
    search_movie_title_UI(database, p_indexes, s_indexes);
  }
}

// Função para pesquisar por um filme pela chave primária
void search_movie_pkey_UI(FILE *database, PidxList_t *p_indexes) {
  char pkey[6];
  int rrn;
  Movie movie;

  // Recebe a chave primária como input
  puts("Digite a chave primária do filme:");
  scanf(" %s", pkey);

  // Procura o filme na lista de indices primários
  rrn = pkey_search(p_indexes, pkey);

  // Caso o filme seja ou não encontrado
  if (rrn == -1) {
    puts("O filme não foi encontrado.");
  } else {
    movie = deserialize_movie(rrn, database);
    print_movie_UI(movie);
  }
}

// Função para pesquisar por um filme pela chave secundária
void search_movie_title_UI(FILE *database, PidxList_t *p_indexes,
                           SidxList_t *s_indexes) {
  char title[100];
  int *rrn = NULL;
  Movie movie;

  // Recebe o título do filme como input
  puts("Digite o título do filme:");
  scanf(" %[^\n]", title);

  // Procura o filme na lista de indices secundários
  rrn = title_search(p_indexes, s_indexes, title);

  // Caso encontre ou não os filmes
  if (rrn[0] == 0) {
    puts("O filme não foi encontrado.");
  } else {
    for (size_t i = 1; i <= rrn[0]; i++) {
      movie = deserialize_movie(rrn[i], database);
      print_movie_UI(movie);
    }
  }

  // Libera o vetor de rrns
  free(rrn);
}

// Função para remover um filme pela chave primária
void remove_movie_pkey_UI(PidxList_t **p_node, SidxList_t **s_node,
                          FILE *database) {
  char pkey[6];
  int rrn;

  // Recebe a chave primária como input
  puts("Digite a chave primária para remoção do filme:");
  scanf(" %s", pkey);

  // Procura o filme na lista de indices primários
  rrn = pkey_search(*p_node, pkey);

  // Caso o filme seja encontrado na lista
  if (rrn == -1) {
    puts("Filme não encontrado!");
  } else {
    // Remove da memória
    remove_primary_node(p_node, pkey);
    remove_secondary_node(s_node, pkey);
    // Exclui do arquivo de dados lógicamente
    delete_movie(database, rrn);
    puts("Filme removido com sucesso!");
  }
}

// Função para atualizar a nota do filme
void update_score_pkey_UI(PidxList_t *p_indexes, FILE *database) {
  char pkey[6];
  int score, rrn;

  // Recebe a chave primária do filme de input
  puts("Digite a chave do filme:");
  scanf(" %s", pkey);

  // Procura pela chave
  rrn = pkey_search(p_indexes, pkey);

  // Caso não encontre o filme
  if (rrn == -1) {
    puts("Filme não encontrado!");
    return;
  }

  // Recebe a nova nota de input
  puts("Digite a nova nota:");
  scanf("%d", &score);

  // Atualiza a nova nota no arquivo de dados
  update_score(database, rrn, score);

  puts("Nota atualizada com sucesso!");
}

// Função para compactar o arquivo de dados
void refactor_database_UI(PidxList_t *p_indexes, FILE **database) {
  char op;

  // Confirma se o arquivo será compactado
  puts("Deseja limpar os registros removidos logicamente do arquivo de dados? "
       "[S/N]");
  scanf(" %c", &op);

  // Caso a resposta seja sim ou não
  if (op == 'S' || op == 's') {
    rebuild_database(p_indexes, database);
    puts("Operação realizada com sucesso!");
  } else {
    puts("Operação cancelada!");
  }
}

// Função para imprimir as informações do filme
void print_movie_UI(Movie movie) {
  puts("=======================================");
  printf("Chave primária: %s\n", movie.p_key);
  printf("Título: %s\n", movie.br_title);
  printf("Título original: %s\n", movie.title);
  printf("Diretor: %s\n", movie.director);
  printf("Ano: %s\n", movie.year);
  printf("País: %s\n", movie.country);
  printf("Score: %d\n", movie.score);
  puts("=======================================");
}

// Função para imprimir as informações
void print_options_UI() {
  puts("========== Gerenciador de Filmes ==========");
  puts("(1) Cadastrar Filme\n(2) Escolher Filme\n(3) Remover Filme\n(4) "
       "Atualizar nota\n(5) Listar Filmes\n(6) Compactar arquivo\n(0) Sair");
}

void clear_screen_UI() { system(CLEAR); }

void pause_screen_UI() {
  puts("Digite alguma coisa para continuar ...");
  getchar();
  getchar();
}
