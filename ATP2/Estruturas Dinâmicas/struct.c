#include <stdio.h>
#include <stdlib.h>

typedef struct frutas {
  char nome[20];
  float peso;
  struct frutas *prox;
} Fruta;

Fruta *cadastra_fruta() {
  Fruta *aux;
  aux = malloc(sizeof(Fruta));
  puts("Digite o nome:");
  scanf(" %s", aux->nome);
  puts("Digite o peso:");
  scanf("%f", &aux->peso);
  puts("Cadastrado com sucesso!");
  aux->prox = NULL;
  return aux;
}

Fruta *insere_fruta(Fruta *list, Fruta *f) {
  Fruta *aux = list;
  if (list == NULL)
    return f;

  while (list->prox != NULL) {
    list = list->prox;
  }
  list->prox = f;
  return aux;
}

void lista_fruta(Fruta *f) {
  while (f != NULL) {
    printf("Nome : %s\n", f->nome);
    printf("Peso : %f\n\n", f->peso);
    f = f->prox;
  }
}

int main(int argc, char *argv[]) {
  Fruta *fruteira = NULL, *nova;
  int opc;
  char c;

  do {
    puts("(1)Cadastrar fruta\n(2)Listar Frutas\n(3)Excluir frutas\n(0)Sair");
    scanf("%d", &opc);
    switch (opc) {
    case 0:
      return 0;
    case 1:
      nova = cadastra_fruta();
      fruteira = insere_fruta(fruteira, nova);
      break;
    case 2:
      lista_fruta(fruteira);
      break;
    case 3:
      break;
    default:
      break;
    }
    puts("Digite alguma coisa para continuar...");
    scanf(" %c", &c);
    system("clear");
  } while (opc != 0);
  return 0;
}
