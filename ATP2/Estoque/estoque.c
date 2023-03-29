#include <stdio.h>
#include <stdlib.h>

typedef struct produtos {
  float preco;
  char nome[50];
  int cod;
  int qtd;
  int baixaDia;
} Prod;

void listarProd(FILE *ptr) {
  int i = 0;
  Prod estoque;
  printf("=====Produtos cadastrados=====\n");
  while (fread(&estoque, sizeof(Prod), 1, ptr) != 0) {
    i++;
    printf("(%d)%s\n", i, estoque.nome);
  }
}

void diminuirEstoque(FILE *ptr) {
  int opc2, novo;
  Prod estoque;
  listarProd(ptr);
  printf("Você deseja alterar a quantidade de qual produto?\n");
  scanf("%d", &opc2);
  fseek(ptr, (opc2 - 1) * sizeof(Prod), SEEK_SET);
  fread(&estoque, sizeof(Prod), 1, ptr);
  printf("Digite a nova quantidade do produto em estoque:\n");
  scanf("%d", &novo);
  estoque.qtd = novo;
  fseek(ptr, (opc2 - 1) * sizeof(Prod), SEEK_SET);
  fwrite(&estoque, sizeof(Prod), 1, ptr);
  printf("Produto alterado com sucesso!\n");
  getchar();
}

void removerProd(FILE *ptr) {
  int i = 0, opc2;
  Prod estoque;
  FILE *aux;
  aux = fopen("aux.txt", "wb");
  listarProd(ptr);
  rewind(ptr);
  printf("Qual produto você deseja remover?\n");
  scanf("%d", &opc2);
  i = 0;
  while (fread(&estoque, sizeof(Prod), 1, ptr) != 0) {
    if (opc2 - 1 != i) {
      fwrite(&estoque, sizeof(Prod), 1, aux);
    }
    i++;
  }
  fclose(ptr);
  fclose(aux);
  getchar();
  remove("estoque.txt");
  rename("aux.txt", "estoque.txt");
  printf("Produto removido com sucesso!\n");
  getchar();
}

void buscarProd(FILE *ptr) {
  int opc;
  Prod estoque;
  listarProd(ptr);
  printf("Escolha o numero do produto:\n");
  scanf("%d", &opc);
  fseek(ptr, sizeof(Prod) * (opc - 1), SEEK_SET);
  fread(&estoque, sizeof(Prod), 1, ptr);
  printf("======================\n");
  printf("Nome: %s\n", estoque.nome);
  printf("Código: %d\n", estoque.cod);
  printf("Preço: %.2f\n", estoque.preco);
  printf("Quantidade: %d\n", estoque.qtd);
  printf("Baixa do dia: %d\n", estoque.baixaDia);
  printf("======================\n");
}

void cadastrarProd(FILE *ptr) {
  Prod estoque;
  printf("Digite o nome do produto:\n");
  scanf(" %[^\n]s", estoque.nome);
  printf("Digite o preco do produto:\n");
  scanf("%f", &estoque.preco);
  printf("Digite o código do produto:\n");
  scanf("%d", &estoque.cod);
  printf("Digite a quantidade do estoque:\n");
  scanf("%d", &estoque.qtd);
  fwrite(&estoque, 1, sizeof(Prod), ptr);
}

int main(int argc, char *argv[]) {
  int opc, opc2;
  char c;
  FILE *fp;
  do {
    system("clear");
    printf("======Gerenciador de estoque=====\n");
    printf("(1)Cadastrar produto\n(2)Remover produto\n(3)Buscar "
           "produto\n(4)Listar nomes\n(5)Reajustar estoque\n(6)Baixas do "
           "dia\n(7)Reajustar preço\n(0)Sair\n");
    scanf("%d", &opc);
    system("clear");
    switch (opc) {
    case 1:
      fp = fopen("estoque.txt", "ab");
      cadastrarProd(fp);
      fclose(fp);
      scanf(" %c", &c);
      break;
    case 2:
      fp = fopen("estoque.txt", "rb");
      removerProd(fp);
      break;
    case 3:
      fp = fopen("estoque.txt", "rb");
      buscarProd(fp);
      fclose(fp);
      scanf(" %c", &c);
      break;
    case 4:
      fp = fopen("estoque.txt", "rb");
      listarProd(fp);
      fclose(fp);
      scanf(" %c", &c);
      break;
    case 5:
      fp = fopen("estoque.txt", "rb+");
      diminuirEstoque(fp);
      fclose(fp);
      break;
    default:
      break;
    }
  } while (opc != 0);

  return 0;
}
