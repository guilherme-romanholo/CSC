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
                printf("Digite um número inteiro para ser inserido: \n");
                scanf("%d", &vetor[i]);
            } else {
                printf("Não podem ser colocados mais elementos nessa pilha!\n");
            }
        } else if (opc==2)
        {
            if (i>-1)
                i--;
            else
                printf("Todos os elementos da pilha foram removidos!\n");
        } else 
        {
            if (i>=0)
                printf("O item do topo é: %d\n", vetor[i]);
            else
                printf("Não existem elementos nessa pilha!\n");
        }
    } while (opc!=4);
    return 0;
}
