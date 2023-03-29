#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int vetorA[5], vetorB[5], vetorC[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Digite um valor para o vetorA[%d]:\n",i);
        scanf("%d", &vetorA[i]);
        printf("Digite um valor para o vetorB[%d]:\n",i);
        scanf("%d", &vetorB[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("VetorA[%d] = %d\n",i,vetorA[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("VetorB[%d] = %d\n",i,vetorB[i]);
    }
    printf("\nInvertendo os vetores...");
    printf("\n");
    sleep(3);
    for (int i = 0, j = 4; i < 5; i++,j--)
    {
        vetorC[i] = vetorA[i]*vetorB[j];
    }
    for (int i = 0; i < 5; i++)
    {
        printf("VetorC[%d] = %d\n",i,vetorC[i]);
    }
  
    return 0;
}