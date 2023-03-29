#include <stdio.h>

int main() {
  float preco, energia;
  preco = 0;
  printf("Digite a quantidade de energia gasta em kWh:\n");
  scanf("%f", &energia);

  while (energia != 0) {
    if (energia > 150) {
      while (energia != 150) {
        --energia;
        preco += 2;
      }
    } else if (energia <= 150 && energia >= 101) {
      while (energia != 100) {
        --energia;
        preco += 1.6;
      }
    } else if (energia <= 100 && energia >= 51) {
      while (energia != 50) {
        --energia;
        preco += 1.3;
      }
    } else if (energia <= 50) {
      while (energia != 0) {
        --energia;
        preco += 1;
      }
    }
  }

  printf("O preço total a ser pago é R$ %.2f\n", preco);

  return 0;
}
