#include <stdio.h>
#define n 6
#define m 3

int main(int argc, char const *argv[])
{
    float matriz[n][m], media = 0 ,mediaT = 0;
    int aluno, opc, ma, count;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matriz[i][j] = -1;
        }
    }
    do
    {
        printf("[1]Cadastrar uma aluno\n[2]Média de um aluno\n[3]Média Total\n[0]Sair\n");
        scanf("%d",&opc);
        if (opc == 1) 
        {
            printf("Digite o número do aluno para ser cadastrado: (0 a %d)\n",n-1);
            scanf("%d",&aluno);
            printf("Digite as notas: (%d notas)\n",m);
            for (int j = 0; j < m; j++)
            {
                scanf("%f",&matriz[aluno][j]);
            }
        } else if (opc == 2)
        {
            printf("Qual o número do aluno que você deseja consultar a média?\n");
            scanf("%d",&ma);
            media = 0;
            for (int j = 0; j < m; j++)
            {
                media += matriz[ma][j];
            }
            printf("A média do aluno %d é igual a %f.\n",ma,media/m);
        } else if (opc == 3)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (matriz[i][j] != -1)
                    {
                        mediaT += matriz[i][j];
                        count++;
                    }
                }
            }
            printf("A média total dos alunos é %f\n",mediaT/count);
        }
    } while (opc!=0);
    return 0;
}
