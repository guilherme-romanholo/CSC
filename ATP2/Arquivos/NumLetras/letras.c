#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int vet[26] = {0}, aux = 65, i;
  char nomearq[20], c;

  scanf(" %s", nomearq);

  fp = fopen(nomearq, "r");

  while (fscanf(fp, "%c", &c) != EOF) {
    if (c != ' ') {
      c = toupper(c);
      vet[c - 65]++;
    }
  }

  for (i = 0; i < 26; i++) {
    if (vet[i] != 0)
      printf("%c = %d\n", aux, vet[i]);
    aux++;
  }

  fclose(fp);
  return 0;
}
