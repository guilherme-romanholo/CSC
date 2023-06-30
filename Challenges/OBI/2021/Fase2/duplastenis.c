#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(int argc, char *argv[]) {
  int v[4];
  for (int i = 0; i < 4; i++) {
    scanf("%d", &v[i]);
  }
  qsort(v, 4, sizeof(int), cmp);
  printf("%d\n", abs((v[0] + v[3]) - (v[1] + v[2])));
  return 0;
}
