#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *a, int s, int e, int f) {
  int m;

  if (s > e)
    return -1;

  m = (s + e) / 2;

  if (a[m] == f)
    return m;
  else if (f > a[m])
    return binarySearch(a, m + 1, e, f);
  else
    return binarySearch(a, s, m - 1, f);
}

int binarySearch2(int *a, int s, int e, int f) {
  int m;

  if (s > e)
    return -1;

  m = (s + e) / 2;

  if (a[m] == f)
    return m;
  else if (f < a[m])
    return binarySearch2(a, m + 1, e, f);
  else
    return binarySearch2(a, s, m - 1, f);
}

int main(int argc, char *argv[]) {
  int n, m, i, *vet, val, resp;

  scanf("%d", &n);

  vet = malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
    scanf("%d", &vet[i]);

  scanf("%d", &m);

  for (i = 0; i < m; i++) {
    scanf("%d", &val);
    resp = binarySearch(vet, 0, (n / 2) - 1, val);
    if (resp == -1) {
      resp = binarySearch2(vet, n / 2, n - 1, val);
    }
    printf("%d ", resp);
  }
  printf("\n");

  return 0;
}
