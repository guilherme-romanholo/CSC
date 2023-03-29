#include <stdio.h>
//falta fazer algumas validações
int main(int argc, char const *argv[])
{
    int fila[10], opc, i=0;

    do
    {
        printf("[1]Inserir\n[2]Remover\n[3]Print\n[0]Sair\n");
        do{
            scanf("%d",&opc);
            if (opc!=1 && opc!=2 && opc!=3 && opc!=0)
            {
                printf("Opção inválida, digite novamente!\n");
            }
        } while (opc!=1 && opc!=2 && opc!=3 && opc!=0);
        if (opc==1)
        {
            printf("Digite o número que vai entrar na fila:\n");
            scanf("%d",&fila[i]);
            i++;     
        }
        if (opc==2)
        {
            i--;
        }
        if (opc==3)
        {
            printf("O elemento do topo é: %d\n",fila[i-1]);
        }
    } while (opc!=0);
    

    return 0;
}
