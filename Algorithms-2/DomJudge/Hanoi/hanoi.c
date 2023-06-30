#include <stdio.h>
#include <stdlib.h>

int vezes = 0;
int mov;
int vet[3] = {0};

void move_disco(int n, char ori, char dest, char aux) {
  int f;
  if (n >= 1) {
    move_disco(n - 1, ori, aux, dest);
    vezes++;
    f = ori - 65;
    vet[f]--;
    f = dest - 65;
    vet[f]++;
    if (mov == vezes)
      printf("%d %d %d\n", vet[0], vet[1], vet[2]);
    move_disco(n - 1, aux, dest, ori);
  }
}

int main(int argc, char *argv[]) {
  int discos;
  scanf("%d %d", &discos, &mov);
  vet[0] = discos;
  move_disco(discos, 'A', 'C', 'B');
  return 0;
}
