#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(int argc, char *argv[]) {
  int total, num;
  float menor;
  scanf("%d", &total);
  scanf("%d", &num);
  int cidadeF[num + 1], cidade[num];
  for (int i = 0; i < num; i++) {
    scanf("%d", &cidade[i]);
  }
  qsort(cidade, num, sizeof(int), cmp);
  for (int i = 0; i < num + 1; i++) {
    if (i == 0) {
      cidadeF[i] = cidade[i];
    } else if (i == num) {
      cidadeF[i] = total - cidade[i - 1];
    } else {
      cidadeF[i] = cidade[i] - cidade[i - 1];
    }
  }
  for (int i = 0; i < num; i++) {
    if (i == 0) {
      menor = cidadeF[i] + (float)cidadeF[i + 1] / 2;
    } else if (i == num - 1 && (float)cidadeF[i] / 2 + cidadeF[i + 1] < menor) {
      menor = (float)cidadeF[i] / 2 + (float)cidadeF[i + 1];
    } else if (i != 0 && i != num - 1 &&
               (float)cidadeF[i] / 2 + (float)cidadeF[i + 1] / 2 < menor) {
      menor = (float)cidadeF[i] / 2 + (float)cidadeF[i + 1] / 2;
    }
  }
  printf("%.2f\n", menor);
  return 0;
}
