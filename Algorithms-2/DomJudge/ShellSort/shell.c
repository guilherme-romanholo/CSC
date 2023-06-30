#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shellSort(char **arr, int n) {
  int i, j, gap;
  char aux[100];

  gap = n / 8;
  for (i = 0; gap <= n / 4; i++)
    gap = pow(2, i);

  while (gap != 1) {
    gap = gap / 2;
    for (i = gap; i < n; i++) {
      strcpy(aux, arr[i]);
      j = i;
      while (strcmp(arr[j - gap], aux) > 0) {
        strcpy(arr[j], arr[j - gap]);
        j -= gap;
        if (j < gap)
          break;
      }
      strcpy(arr[j], aux);
    }
    for (int m = 0; m < n; m++) {
      printf("%s ", arr[m]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  int n, i;
  char **arr;

  scanf("%d", &n);

  arr = malloc(n * sizeof(char *));
  for (i = 0; i < n; i++)
    arr[i] = malloc(100 * sizeof(char));

  for (i = 0; i < n; i++) {
    scanf(" %s", arr[i]);
  }

  shellSort(arr, n);

  for (i = 0; i < n; i++)
    free(arr[i]);

  free(arr);

  return 0;
}
