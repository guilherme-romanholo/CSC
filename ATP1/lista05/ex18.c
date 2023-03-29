#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int vetor[11], num, ind, aux;
    for (int i = 0; i < 10; i++)
    {
        vetor[i] = rand(); 
    }
    printf("Vetor: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\nDigite um elemento e a posição (1 a 11) que ele deve ser inserido no vetor respectivamente:\n");
    scanf("%d",&num);
    scanf("%d",&ind);
    for (int i = 10; i > ind; i--)
    {
        vetor[i] = vetor[i-1]; 
    }
    vetor[ind] = num;
    for (int i = 0; i < 11; i++)
    {
        printf("%d ",vetor[i]);
    }
    return 0;
}
