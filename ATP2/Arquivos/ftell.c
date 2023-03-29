#include <stdio.h>

int main (int argc, char *argv[])
{
  FILE *fp = fopen("tamanho.txt", "r");
  int tamanho;

  fseek(fp, 0, SEEK_END);
  tamanho = ftell(fp);
  rewind(fp);

  printf("O arquivo aberto tem um tamanho de %d bytes.\n",tamanho);

  return 0;
}
