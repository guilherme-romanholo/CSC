#include <stdio.h>

int main(int argc, char *argv[]) {

  int alg;
  char num[100], invnum[100];
  printf("Qual a quantidade de algarismos: \n");
  scanf("%d", &alg);
  printf("Digite seu número: \n");

  for (int i = 0, j = alg; i <= alg; i++, j--) {
    scanf("%c", &num[i]);
    invnum[j] = num[i];
  }
  printf("%s", invnum);

  return 0;
}
