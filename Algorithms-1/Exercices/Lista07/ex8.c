#include <stdio.h>
#define m 3

int main(int argc, char const *argv[])
{
    char c;
    int opc, hom = 0, mul = 0, ano_antigo, ind_ant, mes_antigo = 12, dia_antigo = 31;
    float saldo_mulher = 0, saldo_homem = 0, maior, menor, maior_lim;
    typedef struct cliente 
    {
        char nome[20];
        char sobren[20];
        char sexo;
    }Cli;
    typedef struct abertura
    {
        int dia;
        int mes;
        int ano;
    }Data;
    typedef struct conta  
    {
        Cli pessoais;
        Data data_abertura;
        int num_conta;
        float saldo;
        float lim_especial;
    }Cont;
    Cont pessoas[m];
    for (int i = 0; i < m; i++)
    {
        printf("Cadastro do clinte %d\n\n",i);
        printf("Digite o nome da pessoa:\n");
        scanf(" %[^\n]s",&pessoas[i].pessoais.nome);
        printf("Digite o sobrenome:\n");
        scanf(" %[^\n]s",&pessoas[i].pessoais.sobren);
        printf("Digite o sexo:[M/F]\n");
        scanf(" %c",&pessoas[i].pessoais.sexo);
        printf("Digite a data de abertura da conta (dia, mes e ano respectivamente):\n");
        scanf("%d",&pessoas[i].data_abertura.dia);
        scanf("%d",&pessoas[i].data_abertura.mes);
        scanf("%d",&pessoas[i].data_abertura.ano);
        printf("Digite o número da conta:\n");
        scanf("%d",&pessoas[i].num_conta);
        printf("Digite o saldo:\n");
        scanf("%f",&pessoas[i].saldo);
        printf("Digite o limite especial:\n");
        scanf("%f",&pessoas[i].lim_especial);
        printf("Cliente cadastrado!\n");
        printf("Digite qualquer coisa para continuar\n");
        scanf(" %c",&c);
        if (pessoas[i].pessoais.sexo == 'M')
        {
            saldo_homem += pessoas[i].saldo;
            hom++;
        } else
        {
            saldo_mulher += pessoas[i].saldo;
            mul++;
        }
        if (i == 0)
        {
            maior = pessoas[i].saldo;
            menor = pessoas[i].saldo;
        } else if (pessoas[i].saldo > maior) {
            maior = pessoas[i].saldo;
        } else if (pessoas[i].saldo < menor)
        {
            menor = pessoas[i].saldo;   
        }
        if (i == 0)
        {
            ano_antigo = pessoas[i].data_abertura.ano;
        } else if (pessoas[i].data_abertura.ano < ano_antigo)
        {
            ano_antigo = pessoas[i].data_abertura.ano;
        }
        if (i == 0)
        {
            maior_lim = pessoas[i].lim_especial;
        } else if (pessoas[i].lim_especial > maior_lim)
        {
            maior_lim = pessoas[i].lim_especial;
        }
        system("clear");
    }
    //clinte mais antigo
    for (int i = 0; i < m; i++)
    {
        if (pessoas[i].data_abertura.ano == ano_antigo)
        {
            if (pessoas[i].data_abertura.mes < mes_antigo)
            {
                mes_antigo = pessoas[i].data_abertura.mes;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (pessoas[i].data_abertura.ano == ano_antigo && pessoas[i].data_abertura.mes == mes_antigo)
        {
            if (pessoas[i].data_abertura.dia < dia_antigo)
            {
                dia_antigo = pessoas[i].data_abertura.dia;
                ind_ant = i;
            }
            
        }
    }
    do
    {
        printf("Escolha a opcação\n");
        printf("[1]Apresentar dados\n[2]Respostas do exercício\n[0]Finalizar\n");
        scanf("%d",&opc);
        if (opc == 1)
        {
            
        } else if (opc == 2)
        {
            system("clear");
            printf("O saldo médio das mulheres é %.2f.\n",saldo_mulher/mul);
            printf("O saldo médio dos homens é %.2f.\n",saldo_homem/hom);
            printf("O maior saldo entre os homens e mulheres é: %.2f\n",maior);
            printf("O menor saldo entre os homens e mulheres é: %.2f\n",menor);
            printf("O cliente mais antigo é %s, com número da conta %d.\n",pessoas[ind_ant].pessoais.nome,pessoas[ind_ant].num_conta);
            printf("O maior limite especial é %.2f.\n",maior_lim);
        } else {

        }
    } while (opc!=0);
    
    return 0;
}
