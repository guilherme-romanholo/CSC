#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void insertionSort(double *arr, int n, int pos) {
  int i, j;
  double aux;
  for (i = 1; i <= pos; i++) {
    aux = arr[i];
    j = i;
    while (j > 0 && arr[j - 1] > aux) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = aux;
  }
  for (i = pos; i < n; i++) {
    aux = arr[i];
    j = i;
    while (j > pos && arr[j - 1] < aux) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = aux;
  }
}

int main(int argc, char *argv[]) {
  int n, pos, i;
  double teste, *arr;

  scanf("%d %d", &n, &pos);

  arr = malloc(n * sizeof(double));

  for (i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }

  insertionSort(arr, n, pos);

  for (i = 0; i < n; i++)
    printf("%.3lf ",arr[i]);
  printf("\n");

  free(arr);

  return 0;
}
