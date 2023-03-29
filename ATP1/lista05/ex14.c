#include <stdio.h>

int main(int argc, char const *argv[])
{
    int X[5], maior=0;
    printf("Digite 5 valores para um vetor:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&X[i]);
        if (maior==0)
        {
            maior = X[i];
        } else if (X[i]>maior)
        {
            maior = X[i];
        }   
    }
    printf("Vetor digitado: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",X[i]);
    }
    printf("\n");
    printf("O valores do vetor divididos pelo maior valor (%d):\n",maior);
    for (int i = 0; i < 5; i++)
    {
        printf("%.2f ", (float)X[i]/(float)maior);    
    }
    printf("\n");
    return 0;
}
