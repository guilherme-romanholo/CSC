#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
  int resto;
  while (b != 0) {
    resto = a % b;
    a = b;
    b = resto;
  }
  return a;
}

int main(int argc, char *argv[]) {
  int n, f1, f2, *v;
  scanf("%d", &n);

  v = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &f1, &f2);
    if (f1 > f2) {
      v[i] = mdc(f1, f2);
    } else {
      v[i] = mdc(f2, f1);
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", v[i]);
  }

  return 0;
}
