#include <stdio.h>

#define refri 2.50
#define cerveja 4.00
#define pizza 47.30
#define almoco 15.00
#define porcao 10.50

int main(int argc, char *argv[]) {
  int opc = 1;
  int qtd, mesa;
  float preco;
  preco = 0;
  printf("Digite o número da mesa:\n");
  scanf("%d", &mesa);
  while (opc != 0) {
    printf("Escolha seu pedido: \n[ 1 ] Refrigerante - R$2.50 \n[ 2 ] Cerveja "
           "- R$4.00 \n[ 3 ] "
           "Pizza - R$47.30 \n[ 4 ] Almoço - R$15.00 \n[ 5 ] Porção - R$10.50 "
           "\n[ 0 ] Sair \n");
    scanf("%d", &opc);
    switch (opc) {
    case 1:
      qtd = 0;
      printf("Digite a quantidade de refrigerantes:\n");
      scanf("%d", &qtd);
      preco += refri * qtd;
      break;
    case 2:
      qtd = 0;
      printf("Digite a quantidade de cervejas:\n");
      scanf("%d", &qtd);
      preco += cerveja * qtd;
      break;
    case 3:
      qtd = 0;
      printf("Digite a quantidade de pizzas:\n");
      scanf("%d", &qtd);
      preco += pizza * qtd;
      break;
    case 4:
      qtd = 0;
      printf("Digite a quantidade de almoços:\n");
      scanf("%d", &qtd);
      preco += almoco * qtd;
      break;
    case 5:
      qtd = 0;
      printf("Digite a quantidade de porções:\n");
      scanf("%d", &qtd);
      preco += porcao * qtd;
      break;
    }
  }
  printf("O total a se pagar pelas pessoas da mesa %d é R$ %.2f.\n", mesa,
         preco);

  return 0;
}
