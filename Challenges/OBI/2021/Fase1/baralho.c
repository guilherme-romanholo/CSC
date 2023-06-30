#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarResp() {}

int main(int argc, char *argv[]) {
  char str[157], aux[3];
  int C[13] = {0}, E[13] = {0}, U[13] = {0}, P[13] = {0}, i, j, ind;

  scanf(" %s", str);

  for (i = 0; i < strlen(str) / 3; i += 3) {
    strncpy(aux, &str[i * 3], 2);
    aux[2] = '\0';
    ind = atoi(aux);
  }
  ind = 0;
  for (i = 0; i < 13; i++) {
    if (C[i] == 0) {
      ind++;
    } else if (C[i] == 2) {
      printf("erro\n");
      break;
    }
  }
  printf("%d\n", ind);
  ind = 0;
  for (i = 0; i < 13; i++) {
    if (E[i] == 0) {
      ind++;
    } else if (E[i] == 2) {
      printf("erro\n");
      break;
    }
  }
  printf("%d\n", ind);
  ind = 0;
  for (i = 0; i < 13; i++) {
    if (U[i] == 0) {
      ind++;
    } else if (U[i] == 2) {
      printf("erro\n");
      break;
    }
  }
  printf("%d\n", ind);
  ind = 0;
  for (i = 0; i < 13; i++) {
    if (P[i] == 0) {
      ind++;
    } else if (P[i] == 2) {
      printf("erro\n");
      break;
    }
  }
  printf("%d\n", ind);
  return 0;
}
