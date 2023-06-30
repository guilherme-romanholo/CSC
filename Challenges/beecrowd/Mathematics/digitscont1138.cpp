#include <cstdio>

int main(int argc, char *argv[]) {
  unsigned int A = 1, B = 1, i, num, vet[10] = {0};

  while (true) {
    scanf("%d %d", &A, &B);
    if (A == 0)
      break;
    for (i = A; i <= B; i++) {
      num = i;
      while (num) {
        vet[num % 10]++;
        num = num / 10;
      }
    }
    for (i = 0; i < 10; i++) {
      printf("%d ", vet[i]);
      vet[i] = 0;
    }
    printf("\n");
  }
  return 0;
}
