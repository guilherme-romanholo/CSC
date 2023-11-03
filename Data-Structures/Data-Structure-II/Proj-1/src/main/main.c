#include "../../include/database.h"
#include "../../include/index.h"
#include "../../include/interface.h"
#include "../../include/movie.h"
#include "../../include/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int op;
  PidxList_t *p_indexes = NULL;
  SidxList_t *s_indexes = NULL;
  FILE *database;

  // Abre a conexão com o arquivo de dados e lê os indices para memória
  open_connection(&database, &p_indexes, &s_indexes);

  // Estrutura do programa principal
  while (true) {
    clear_screen_UI();
    print_options_UI();
    scanf("%d", &op);
    clear_screen_UI();

    // Case para escolha das opções
    switch (op) {
    case 0:
      close_connection(database, p_indexes, s_indexes);
      return EXIT_SUCCESS;
    case 1:
      register_movie_UI(database, &p_indexes, &s_indexes);
      break;
    case 2:
      search_movie_UI(database, p_indexes, s_indexes);
      break;
    case 3:
      remove_movie_pkey_UI(&p_indexes, &s_indexes, database);
      break;
    case 4:
      update_score_pkey_UI(p_indexes, database);
      break;
    case 5:
      list_movies_UI(p_indexes, s_indexes, database);
      break;
    case 6:
      refactor_database_UI(p_indexes, &database);
      break;
    default:
      break;
    }
    pause_screen_UI();
  }
}
