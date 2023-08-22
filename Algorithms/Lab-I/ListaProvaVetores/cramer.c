#include <stdio.h>

int main(int argc, char const *argv[])
{
    float matriz[3][3], vetor[3], Det,Detx,Dety,Detz;
    printf("Matriz:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f",&matriz[i][j]);
        }   
    }
    printf("Vetor:\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%f",&vetor[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ",matriz[i][j]);
        }
        printf("= %.2f\n",vetor[i]);   
    }
    //Determinante
    Det = matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1] + -1*matriz[0][2]*matriz[1][1]*matriz[2][0] + -1*matriz[0][0]*matriz[1][2]*matriz[2][1] + -1*matriz[0][1]*matriz[1][1]*matriz[2][2];
    Detx = vetor[0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*vetor[2] + matriz[0][2]*vetor[1]*matriz[2][1] + -1*matriz[0][2]*matriz[1][1]*vetor[2] + -1*vetor[0]*matriz[1][2]*matriz[2][1] + -1*matriz[0][1]*vetor[1]*matriz[2][2];
    Dety = matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1] + -1*matriz[0][2]*matriz[1][1]*matriz[2][0] + -1*matriz[0][0]*matriz[1][2]*matriz[2][1] + -1*matriz[0][1]*matriz[1][1]*matriz[2][2];
    Detz = matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1] + -1*matriz[0][2]*matriz[1][1]*matriz[2][0] + -1*matriz[0][0]*matriz[1][2]*matriz[2][1] + -1*matriz[0][1]*matriz[1][1]*matriz[2][2];
    printf("%.2f",Det);
    printf("%.2f",Detx/Det);
    return 0;
}
