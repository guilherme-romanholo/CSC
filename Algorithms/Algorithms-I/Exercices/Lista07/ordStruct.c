#include <stdio.h>
#define m 3

int main(int argc, char const *argv[])
{
    typedef struct pessoa
    {
        char nome;
        int idade;
    }Pes;
    Pes gente[m];
    int opc, auxIdade, j;
    char auxNom;
    for (int i = 0; i < m; i++)
    {
        printf("Digite o nome:\n");
        scanf(" %c",&gente[i].nome);    
        printf("Digite o idade:\n");    
        scanf("%d",&gente[i].idade); 
    }
    do
    {
        printf("[1]Mostrar Struct\n[2]Ordenar pela idade\n[0]Fechar\n");
        scanf("%d",&opc);
        if (opc == 1)
        {
            for (int i = 0; i < m; i++)
            {
                printf("Pessoa índice [%d]\n",i);
                printf("Nome: %c\n",gente[i].nome);
                printf("Idade: %d\n",gente[i].idade);
                printf("\n");
            }
        } else if (opc == 2)
        {
            for (int i = 1; i < m; i++)
            {
                auxIdade = gente[i].idade;
                auxNom = gente[i].nome;
                j = i;
                while (j>0 && gente[j-1].idade > auxIdade)
                {
                    gente[j].idade = gente[j-1].idade;
                    gente[j].nome = gente[j-1].nome;
                    j--;
                }
                gente[j].idade = auxIdade;
                gente[j].nome = auxNom;
            }   
        }
    } while ( opc != 0);
    return 0;
}
