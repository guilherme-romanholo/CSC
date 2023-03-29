#include <stdio.h>
#include <string.h>

#define tot 5

int main(int argc, char const *argv[])
{
    //colocar extrato
    int opc, j=0;
    char c;
    int cpfb;
    typedef struct 
    {
        int num;
        int cpf;
        char tipo;
        float saldo;
    } banco;
    banco pessoa[tot];
    do
    {
        system("clear");
        if (opc<0 || opc>6)
        {
            printf("Opção inválida, tente novamente.\n");
        }
        printf("Bem vindo ao programa bancário!\n");        
        printf("Escolha uma das opções:\n");
        printf("[1]Cadastrar Conta\n[2]Buscar conta pelo CPF\n[3]Buscar todas as contas do cliente pelo CPF\n[4]Efetuar depósito\n[5]Efetuar saque\n[6]Mostrar saldo de todas as contas\n[0]Sair\n");
        do{
            scanf("%d",&opc);
        } while (opc<0 && opc>6);
        if (opc==1)
        {
            system("clear");
            printf("Para realizar o cadastro insira os seguintes dados:\n");
            printf("CPF:\n");
            scanf("%d",&pessoa[j].cpf);
            printf("A conta será <p>oupança ou <c>orrente?\n");
            scanf(" %c",&pessoa[j].tipo);
            j++;
            printf("Conta criada com sucesso! Digite qualquer coisa para continuar:\n");
            scanf(" %c",&c);
        } else if (opc==2)
        {
            printf("Digite o CPF da conta para buscá-la:\n");
            scanf("%d", &cpfb);
            for (int i = 0; i < 5; i++)
            {
                if(pessoa[i].cpf==cpfb)
                {
                    printf("Número da conta : %d\nTipo da conta: %c\nSaldo da conta: R$%.2f",i,pessoa[i].tipo,pessoa[i].saldo);
                    printf("Digite qualquer coisa para continuar\n");
                    scanf(" %c",&c);
                }
            }
        }
    } while (opc!=0);
    

    return 0;
}
