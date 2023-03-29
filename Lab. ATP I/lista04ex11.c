#include <stdio.h>

#define precoDiaria 300

int opc = 1;
int h;

int teste() {
  printf("[1] Cadastrar hospede\n[2] Buscar hospede\n[0] Sair\n");
  scanf("%d", &opc);
  if (opc == 1) {
    printf("Digite quantos hospedes deseja cadastrar:\n");
    scanf("%d", &h);
  }
  return opc;
}

int main() {
  float pagoPessoa = 0;
  float total = 0;
  char a;
  int s;
  int num;
  typedef struct {
    char nome[50];
    char end[50];
    char fone[50];
    char cid[50];
    char uf[50];
    int numDia;
  } Dados;

  Dados pessoa[200];

  // printf("[1] Cadastrar hospede\n[2] Buscar hospede\n");
  // scanf("%d", &opc);
  teste();
  while (opc == 1) {
    if (opc == 1) {
      // for (int i = 1; i <= h; i++) {
      printf("Digite o numero do hospede:\n");
      scanf("%d", &num);
      printf("Digite seu nome:\n");
      scanf(" %[^\n]s", pessoa[num].nome);
      printf("Digite seu endereço:\n");
      scanf(" %[^\n]s", pessoa[num].end);
      printf("Digite seu fone:\n");
      scanf(" %[^\n]s", pessoa[num].fone);
      printf("Digite seu cidade:\n");
      scanf(" %[^\n]s", pessoa[num].cid);
      printf("Digite seu estado:\n");
      scanf(" %[^\n]s", pessoa[num].uf);
      printf("Digite seu número de diárias:\n");
      scanf("%d", &pessoa[num].numDia);
      if (pessoa[num].numDia < 15) {
        pagoPessoa = precoDiaria * pessoa[num].numDia + 20;
      } else if (pessoa[num].numDia == 15) {
        pagoPessoa = precoDiaria * pessoa[num].numDia + 14;
      } else {
        pagoPessoa = precoDiaria * pessoa[num].numDia + 12;
      }

      printf("Nome: %s\n", pessoa[num].nome);
      printf("Endereço: %s\n", pessoa[num].end);
      printf("Fone: %s\n", pessoa[num].fone);
      printf("Cidade: %s\n", pessoa[num].cid);
      printf("Estado: %s\n", pessoa[num].uf);
      printf("O total a pagar pelo hospede número %d é: R$%.2f\n", num,
             pagoPessoa);
      total += pagoPessoa;
      //}
      printf("O total ganho pelo hotel é: %.2f\n", total);
      //  printf("[1] Cadastrar hospede\n[2] Buscar hospede\n");
      //  scanf("%d", &opc);
      teste();
    }
  }
  while (opc == 2) {
    if (opc == 2) {
      printf("Escolha o número do hospede: \n");
      scanf("%d", &s);
      printf("Nome: %s\n", pessoa[s].nome);
      printf("Endereço: %s\n", pessoa[s].end);
      printf("Fone: %s\n", pessoa[s].fone);
      printf("Cidade: %s\n", pessoa[s].cid);
      printf("Estado: %s\n", pessoa[s].uf);
      printf("O total a pagar pelo hospede número %d é: R$%.2f\n", s,
             pagoPessoa);
      teste();
    }
  }

  return 0;
}
