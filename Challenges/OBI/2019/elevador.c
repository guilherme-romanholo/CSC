#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main(int argc, char *argv[]) {
  int n, *v, flag = 0;
  scanf("%d", &n);
  v = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  qsort(v, n, sizeof(int), cmp);
  for (int i = 0; i < n; i++) {
    if (v[i + 1] - v[i] > 8) {
      flag = 1;
    }
  }
  if (flag == 1) {
    printf("N\n");
  } else {
    printf("S\n");
  }
  return 0;
}
