#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct planetas {
  char nome[22];
  double x, y, z;
  double peso;
} Plan;

int main() {
  int n, m, i, opc, ind, ind1, ind2, j;
  char aux1[22], aux2[22];
  double dist, sum;

  scanf("%d %d", &n, &m);

  Plan planetas[n];

  for (i = 0; i < n; i++) {
    scanf(" %s %lf %lf %lf %lf", planetas[i].nome, &planetas[i].peso,
          &planetas[i].x, &planetas[i].y, &planetas[i].z);
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &opc);
    if (opc == 1) {
      scanf(" %s %s", aux1, aux2);
      for (j = 0; j < n; j++) {
        if (!strcmp(aux1, planetas[j].nome)) {
          ind1 = j;
        }
      }
      for (j = 0; j < n; j++) {
        if (!strcmp(aux2, planetas[j].nome)) {
          ind2 = j;
        }
      }
      dist = sqrt((planetas[ind2].x - planetas[ind1].x) *
                      (planetas[ind2].x - planetas[ind1].x) +
                  (planetas[ind2].y - planetas[ind1].y) *
                      (planetas[ind2].y - planetas[ind1].y) +
                  (planetas[ind2].z - planetas[ind1].z) *
                      (planetas[ind2].z - planetas[ind1].z));
      printf("%.2lf\n", dist);
    } else if (opc == 2) {
      scanf(" %s", aux1);
      for (int j = 0; j < n; j++) {
        if (!strcmp(aux1, planetas[j].nome)) {
          printf("%.0lf %.0lf %.0lf\n", planetas[j].x, planetas[j].y,
                 planetas[j].z);
        }
      }
    } else if (opc == 3) {
      scanf(" %s", aux1);
      for (int j = 0; j < n; j++) {
        if (!strcmp(aux1, planetas[j].nome)) {
          printf("%.2lf\n", planetas[j].peso);
        }
      }
    }
  }
  return 0;
}
