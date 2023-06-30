#include <stdio.h>

int main(int argc, char const *argv[])
{
    int vetor[10], opc, i = -1;
    do
    {
        printf("[1] Inserir\n[2] Remover\n[3] Mostrar a pilha\n[4] Sair\n");
        scanf("%d",&opc);
        if (opc==1)
        {
            if (i<10){
                i++;
                printf("Digite o número que você deseja inserir: \n");
                scanf("%d",&vetor[i]);
            } else
            {
                printf("A pilha ja está cheia!\n");
            }
        } else if (opc==2)
        {
            if (i==-1)
            {
                i--;
            } else if (i<0)
            {
                printf("Não existem mais elementos nessa lista!\n");   
            } else {
                for (int j = 0; j <= i; j++)
                {
                    vetor[j] = vetor[j+1]; 
                }
                i--;
            }
        } else {
            printf("A ordem da pilha é:\n");
            for (int j = i; j >= 0; j--)
            {
                printf("%d\n",vetor[j]);
            }
        }
    } while (opc!=4);
    return 0;
}
