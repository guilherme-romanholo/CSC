#include <math.h>
#include <stdio.h>

int main() {
  float x1, x2, a, b, c, delta;

  printf("Digite os valores de a, b, c respectivamente: \n");
  scanf("%f", &a);
  scanf("%f", &b);
  scanf("%f", &c);

  delta = (b * b) - (4 * a * c);

  if (delta > 0) {
    x1 = (-1 * b + sqrtf(delta)) / (2 * a);
    x2 = (-1 * b - sqrtf(delta)) / (2 * a);
    printf("As raízes da equação são: %.2f e %.2f. \n", x1, x2);
  } else if (delta == 0) {
    x1 = (-1 * b + sqrt(delta)) / 2 * a;
    printf("A raiz da equação é: %.2f. \n", x1);
  } else {
    printf("Não existem raízes reais. \n");
  }

  return 0;
}
