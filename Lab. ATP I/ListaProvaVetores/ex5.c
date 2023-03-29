#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N[20], aux;
    char c;
    for (int i = 0; i < 20; i++)
    {
        N[i] = rand() % 20;
        printf("%d ",N[i]);
    }
    printf("\n");
    for (int i = 0, j = 19; i < 11; i++,j--)
    {
        aux = N[i];
        N[i] = N[j];
        N[j] = aux;
    }
    for (int i = 0; i < 20; i++)
    {
        printf("%d ",N[i]);
    }
    printf("\n");
    return 0;
}
