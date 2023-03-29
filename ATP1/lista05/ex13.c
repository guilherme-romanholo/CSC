#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int A[5],maiorI=0,dif,ind1,ind2;
    printf("Digite 5 números inteiros consecultivos:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&A[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        dif = A[i] - A[i+1];
        if (maiorI==0)
        {
            maiorI = fabs(dif);
            ind1 = i;
            ind2 = i+1;
        } else if (fabs(dif)>maiorI)
        {
            maiorI = fabs(dif); 
            ind1 = i;
            ind2 = i+1;
        }       
    }
    printf("A maior diferença entre elementos consecultivos é :%d. Entre os valores dos vetores A[%d] e A[%d].\n",maiorI,ind1,ind2);
    return 0;
}
