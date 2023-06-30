#include <stdio.h>
#include <stdlib.h>
#define m 3

int main(int argc, char const *argv[]) {
  int matrizA[m][m], matrizB[m][m], matrizC[m][m], j;

  for (int i = 0; i < m; i++) 
  {
    for (int j = 0; j < m; j++) 
    {
        matrizA[i][j] = rand() % 5;
        matrizB[i][j] = rand() % 5;
    }
  }
  // multiplicação
  for (int i = 0; i < m; i++) 
  {
    for (j = 0; j < m; j++) 
    {
        matrizC[i][j] = matrizA[i][0]*matrizB[0][j] + matrizA[i][1]*matrizB[1][j] + matrizA[i][2]*matrizB[2][j];
    }
  }

  for (int i = 0; i < m; i++) 
  {
    for (int j = 0; j < m; j++) 
    {
      printf("%d ", matrizA[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  
  for (int i = 0; i < m; i++) 
  {
    for (int j = 0; j < m; j++) 
    {
      printf("%d ", matrizB[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < m; i++) 
  {
    for (int j = 0; j < m; j++) 
    {
      printf("%d ", matrizC[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}
