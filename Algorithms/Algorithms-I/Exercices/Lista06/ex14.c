#include <stdio.h>
#define m 7

// ex 14.1
int func1(int mapa[m][m])
{
    int ida, cheg;
    char c;
    printf("Digite a cidade de origem:\n");
    scanf("%d",&ida);
    printf("Digite a cidade de destino:\n");
    scanf("%d",&cheg);
    printf("O tempo de percurso entre a cidade %d e %d é de %d hora(s).\n\n",ida,cheg,mapa[ida][cheg]);
    printf("Digite qualquer coisa para continuar:\n");
    scanf(" %c",&c);
    system("clear");
    return 0;
}

// ex 14.2
int func2(int mapa[m][m])
{
    char c;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mapa[i][j]==0)
            {
                break;
            } else {
                printf("%d ", mapa[i][j]);
            }
        }
        printf("\n");
    }
    printf("Digite qualquer coisa para continuar:\n");
    scanf(" %c",&c);
    system("clear");
    return 0;
}

//ex 14.3
int func3(int mapa[m][m])
{
    int ida, cheg, soma = 0, prox, aux = 0;
    char c;
    do {
        if(soma==0){
            printf("Digite a cidade de partida: \n");
            scanf("%d",&ida);
            printf("Digite a cidade de chegada (Se as duas cidades forem iguais a opção é encerrada): \n");
            scanf("%d",&cheg);
            printf("O tempo de percurso entre a cidade %d e a cidade %d é igual a %d hora(s).\n",ida,cheg,mapa[ida][cheg]);
            soma += mapa[ida][cheg];
        } else {
            printf("Digite a próxima cidade:\n");
            scanf("%d",&prox);
            if (cheg==prox)
            {
                printf("Finalizando!\nDigite qualquer coisa para continuar:\n");
                scanf(" %c",&c);
                system("clear");
                break;
            }
            soma += mapa[cheg][prox];
            cheg = prox;
            printf("O tempo de percurso entre as cidades é de %d hora(s).\n",soma);
        }
    } while (aux==0);
    return 0;
}

//ex14.4
int func4(int mapa[m][m])
{
    int ida, chegad, m1, m2, soma1 = 0, soma2 = 0;
    char c;
    printf("Digite a cidade de ida:\n");
    scanf("%d",&ida);
    printf("Digite as cidades de pernoite:\n");
    scanf("%d",&m1);
    scanf("%d",&m2);
    printf("Digite a cidade de destino:\n");
    scanf("%d",&chegad);
    soma1 = ida + m1 + chegad;
    soma2 = ida + m2 + chegad;
    if (soma1 > soma2)
    {
        printf("O percurso pela primeira cidade de pernoite %d possui um tempo menor de %d.\n",m1,soma1);
    } else if (soma1 < soma2)
    {
        printf("O percurso pela segunda cidade de pernoite %d possui um tempo menor de %d.\n",m2,soma2);
    } else if (soma1 == soma2)
    {
        printf("O percurso pelas duas cidades de pernoite %d e %d possui o mesmo tempo de %d.\n",m1,m2,soma1);
    }
    printf("Digite qualquer coisa para continuar:\n");
    scanf(" %c",&c);
    return 0;
}

int main(int argc, char const *argv[])
{
    int matriz[m][m] = {{0,2,11,6,15,11,1},
                        {2,0,7,12,4,2,15},
                        {11,7,0,11,8,3,13},
                        {6,12,11,0,10,2,1},
                        {15,4,8,10,0,5,13},
                        {11,2,3,2,5,0,14},
                        {1,15,13,1,13,14,1}}, opc;

    do{
        printf("Escolha a opção:\n[1] Tempo de duas cidades\n[2] Imprimir a tabela com os horários\n[3] Tempo para uma sequência de cidades\n[4] Menor tempo com duas cidades de pernoite\n[0]  Sair\n");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            system("clear");
            func1(matriz);
            break;
        case 2:
            system("clear");
            func2(matriz);
            break;
        case 3:
            system("clear");
            func3(matriz);
            break;
        case 4:
            system("clear");
            func4(matriz);
            break;    
        default:
            printf("Fim do programa!\n");
            break;
        }
    } while(opc!=0);
    return 0;
}
