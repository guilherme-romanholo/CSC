/*14.Faça um algoritmo que imprima na tela um losango utilizando somente o caractere
“X” (veja a ilustração abaixo). O usuário deverá escolher a quantidade (de linhas) da
figura a ser impressa na tela. Dica: Observe os padrões de uma linha para a outra.*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int linhas, aux, aux2;
    int k = 1;
    do
    {
        printf("Escolha quantas linhas o losango vai possuir:\n");
        scanf("%d",&linhas);
        if (linhas<3)
        {
            printf("Não é possível formar um losango com menos de 3 linhas.\nDigite um número válido!\n");
        }   
    } while (linhas<3); 
    aux = linhas-1;
    if (linhas%2){ //num linhas ímpares
        //parte crescente
        for (int i = 0; i < (linhas/2)+1; i++)
        {   
            
            for (int i = 0; i < aux; i++)
            {
                printf(" ");
            }
            aux -= 2;
            for (int j = 0; j < k; j++)
            {
                printf("X");
            }
            printf("\n");
            k += 4;   
        }
        //parte decrescente
        aux += 4;
        for (int i = 0; i < linhas/2; i++)
        {
            if (i==0)
            {
                k -= 4;
            }
            
            for (int i = 0; i < aux; i++)
            {
                printf(" ");
            }
            aux += 2;
            k -= 4;
            for (int i = 0; i < k; i++)
            {
                printf("X");   
            }
            printf("\n");
        }
    } else { //num de linhas pares
         //parte crescente
        for (int i = 0; i < (linhas/2); i++)
        {   
            
            for (int i = 0; i <= aux; i++)
            {
                printf(" ");
            }
            aux -= 2;
            for (int j = 0; j < k; j++)
            {
                printf("X");
            }
            printf("\n");
            k += 4;   
        }
        //parte decrescente
        aux += 2;
        for (int i = 0; i < (linhas/2); i++)
        {
            for (int i = 0; i <= aux; i++)
            {
                printf(" ");
            }
            aux += 2;
            k -= 4;
            for (int i = 0; i < k; i++)
            {
                printf("X");   
            }
            printf("\n");
        }
    }
    return 0;
}
