#include <stdio.h>


int main(int argc, char const *argv[])
{
    int f0 = 1,f1 = 1,f2 = 0,m;
    printf("Quantos termos do fibonnaci?\n");
    scanf("%d",&m);
    printf("%d %d ",f0,f1);
    for (int i = 0; i < m-2; i++)
    {
        f2 = f1 + f0;
        printf("%d ",f2);
        f0 = f1;
        f1 = f2;
    }
    return 0;
}
