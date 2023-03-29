#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int vetor[500], aux, k,l;
    char opc;
    for (int i = 0; i < 500; i++)
    {
        vetor[i] = rand() % 1000;   
    }
    do
    {
        printf("Escolha a operação:\n[1]Ordenar o vetor em ordem crescente.\n[2]Ordenar o vetor em ordem decrescente.\n[3]Imprimir todo o vetor.\n[4]Imprimir as posições de um intervalo específico.\n[S] Sair.\n");
        scanf(" %c",&opc);
        if (opc=='1')
        {
            for (int i = 0; i < 500; i++)
            {
                for (int j = 0; j < 500; j++)
                {
                    if (vetor[i]<vetor[j])
                    {
                        aux = vetor[j];
                        vetor[j] = vetor[i];
                        vetor[i] = aux;
                    }
                }
            }
            printf("O vetor foi ordenado!\n");
        } else if (opc=='2')
        {
             for (int i = 0; i < 500; i++)
            {
                for (int j = 0; j < 500; j++)
                {
                    if (vetor[i]>vetor[j])
                    {
                        aux = vetor[j];
                        vetor[j] = vetor[i];
                        vetor[i] = aux;
                    }
                }
            }
            printf("O vetor foi ordenado!\n");
        } else if (opc=='3')
        {
            for (int i = 0; i < 500; i++)
            {
                printf("%d ",vetor[i]);
            }
            printf("\n");
        } else if (opc=='4')
        {
            printf("Escolha o intervalo do vetor:\n");
            printf("Posição inicial:\n");
            scanf("%d",&k);
            printf("Posição final:\n");
            scanf("%d",&l);
            for (int i = k; i < l; i++)
            {
                printf("%d ",vetor[i]);
            }
            printf("\n");
        }        
    } while (opc!='s' && opc!='S');
    return 0;
}
