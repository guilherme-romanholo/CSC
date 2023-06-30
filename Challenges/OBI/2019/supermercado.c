#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
int main(int argc, char *argv[]) {
  typedef struct supermercados {
    float preco;
    int gramas;
  } super;
  int n;
  float menor = INFINITY;
  scanf("%d", &n);
  super locais[n];
  for (int i = 0; i < n; i++) {
    scanf("%f %d", &locais[i].preco, &locais[i].gramas);
  }
  for (int i = 0; i < n; i++) {
    if ((1000 / (float)locais[i].gramas) * locais[i].preco < menor) {
      menor = (1000 / (float)locais[i].gramas) * locais[i].preco;
    }
  }
  printf("%.2f\n", menor);
  return 0;
}
*/

int main(int argc, char *argv[]) {
  typedef struct supermercados {
    float preco;
    int gramas;
  } super;
  int n;
  float menor = INFINITY;
  super *locais;
  scanf("%d", &n);
  locais = malloc(n * sizeof(super));
  for (int i = 0; i < n; i++) {
    scanf("%f %d", &locais[i].preco, &locais[i].gramas);
  }
  for (int i = 0; i < n; i++) {
    if ((1000 / (float)locais[i].gramas) * locais[i].preco < menor) {
      menor = (1000 / (float)locais[i].gramas) * locais[i].preco;
    }
  }
  printf("%.2f\n", menor);
  free(locais);
  return 0;
}
