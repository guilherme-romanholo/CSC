#include <stdio.h>

int main(int argc, char *argv[]) {
  int A;
  printf("Digite o número que você quer ver a tabudada:\n");
  scanf("%d", &A);
  for (int i = 1; i <= 10; i++) {
    printf("%d x %d = %d\n", i, A, i * A);
  }

  return 0;
}
