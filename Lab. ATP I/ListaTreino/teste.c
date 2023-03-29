#include <stdio.h>
#include <stdlib.h>

int main () {
  char matriz[2][10],vet[10];
  int count = 0;
   printf("vetor\n");
  for (int i = 0; i < 10; i++)
  {
    scanf(" %c",&vet[i]);
  }
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 10; j++)
    {
        scanf(" %c",&matriz[i][j]);
        if(matriz[i][j] == vet[j])
        {
            count++;
        }
    }
    printf("Nota %d = %d",i,count);
    count = 0;
  }
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 10; j++)
    {
        printf("%c ",matriz[i][j]);
    }
    printf("\n");
  }

  
  return 0;
}