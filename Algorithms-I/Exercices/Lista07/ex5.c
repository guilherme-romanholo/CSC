#include <stdio.h>
#define n 3

int main(int argc, char const *argv[])
{
    typedef struct datas
    {
        int dia;
        int mes;
        int ano;
    }Data;
    typedef struct pessoas
    {
        char nome[20];
        int idade;
        Data datas;   
    }Pes;
    Pes Vpessoas[n];
    Data hoje;
    int velho, ind;
    printf("Digite o dia atual:\n");
    scanf("%d",&hoje.dia);
    printf("Digite o mes atual:\n");
    scanf("%d",&hoje.mes);
    printf("Digite o ano atual:\n");
    scanf("%d",&hoje.ano);
    for (int i = 0; i < n; i++)
    {
        printf("Digite o nome: \n");
        scanf(" %s",&Vpessoas[i].nome);
        printf("Digite o dia do nascimento: \n");
        scanf("%d",&Vpessoas[i].datas.dia);
        printf("Digite o mes do nascimento: \n");
        scanf("%d",&Vpessoas[i].datas.mes);
        printf("Digite o ano do nascimento: \n");
        scanf("%d",&Vpessoas[i].datas.ano);
    }
    for (int i = 0; i < n; i++)
    {   
        Vpessoas[i].idade = hoje.ano -Vpessoas[i].datas.ano;
        if (Vpessoas[i].datas.mes > hoje.mes)
        {
            Vpessoas[i].idade--;   
        } else if (Vpessoas[i].datas.mes == hoje.mes)
        {
            if (Vpessoas[i].datas.dia >= hoje.dia)
            {
                Vpessoas[i].idade--;   
            }  
        } 
        if (i == 0)
        {
            velho = Vpessoas[i].idade;
            ind = i;
        } else if (Vpessoas[i].idade > velho)
        {
            velho = Vpessoas[i].idade;
            ind = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s\nIdade: %d\n\n",Vpessoas[i].nome,Vpessoas[i].idade);
    }
    printf("Mais velho é %s.\n",Vpessoas[ind].nome);   
    return 0;
}
