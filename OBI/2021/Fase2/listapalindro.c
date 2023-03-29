#include <stdio.h>

int main(int argc, char *argv[]) {
  int n, cont = 0;
  scanf("%d", &n);
  int vet[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }
  for (int i = 0, j = n - 1; i < n; i++, j--) {
    if (vet[i] != vet[j]) {
      cont++;
    }
  }
  printf("%d\n", cont / 2);
  return 0;
}
