#include <stdio.h>

char matriz[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}}; //Declaramos uma matriz global para ser reconhecida em todas as funções    

//Função de verificação do jogo da velha, caso o jogador X consiga uma combinação a função retorna o valor 1, o qual decreta a vitória do jogador X.
//caso o jogador O consiga uma combinação, a função retorna 0, que decreta a vitoria do jogador O.
//caso aconteça um empate na última jogada, a função retorna 3, o qual decreta o empate    
int verifica()
{
    if (matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X')
    {
        return 1;
    } else if (matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X')
    {
        return 1;
    } else if (matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X')
    {
        return 1;
    } else if (matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X')
    {
        return 1;
    } else if (matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X')
    {
        return 1;
    } else if (matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X')
    {
        return 1;
    } else if (matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X')
    {
        return 1;
    } else if (matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X')
    {
        return 1;
    }
    
    if (matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O')
    {
        return 0;
    } else if (matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O')
    {
        return 0;
    } else if (matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O')
    {
        return 0;
    } else if (matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O')
    {
        return 0;
    } else if (matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O')
    {
        return 0;
    } else if (matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O')
    {
        return 0;
    } else if (matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O')
    {
        return 0;
    } else if (matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O')
    {
        return 0;
    }

    if (matriz[0][0] != '-' && matriz[0][1] != '-' && matriz[0][2] != '-' && matriz[1][0] != '-' && matriz[1][1] != '-' && matriz[1][2] != '-' && matriz[2][0] != '-' && matriz[2][1] != '-' && matriz[2][2] != '-')
    {
        return 3;
    }
    
}

//Função para printar o jogo da velha na tela e dar um feedback visual
int printmatriz()
{
    for (int i = 0; i < 3; i++)
    {
        {
            for (int j = 0; j < 3; j++)
            {
                printf("\t%c ",matriz[i][j]);
            }
            printf("\n");  
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int jogador = 1, l,k; //jogador mostra qual sera o prox, l e k são as coordenadas da matriz
    printf("\t Jogo da Velha:\n");
    do{
        printmatriz(); //executa a função que imprime o jogo da velha na tela
        if (jogador == 0) //entra nesse laço quando for a vez do jogador 0 (X)
        {
            printf("Faça a sua jogada jogador X, digite as coordenadas:\n");
            scanf("%d",&l); //fornece as coordenadas da matriz
            scanf("%d",&k); //fornece as coordenadas da matriz
            matriz[l-1][k-1] = 'X'; //substitui na matriz a jogada
            jogador = 1; // troca o valor para passar a vez para o proximo jogador

            if(verifica() == 1)//executa um if para saber qual foi o valor retornado pela função verificadora
            {
                printf("Jogador X ganhou!\n");//quando o valor 1 é retornado
                printmatriz();
                return 0; //encerra o programa
            } else if (verifica() == 3)
            {
                printf("Empate!\n");//quando o valor 3 é retornado
                printmatriz();
                return 0; //encerra o programa
            }
            system("clear");// caso seu sistema seja windows, substitua clear por cls 
            continue; // passa a vez para o prox jogador
        }
        if (jogador == 1)
        {
            printf("Faça a sua jogada jogador O, digite as coordenadas:\n");
            scanf("%d",&l);//fornece as coordenadas da matriz
            scanf("%d",&k);//fornece as coordenadas da matriz
            matriz[l-1][k-1] = 'O';//substitui na matriz a jogada
            jogador = 0;// troca o valor para passar a vez para o proximo jogador

            if(verifica() == 0)//executa um if para saber qual foi o valor retornado pela função verificadora
            {
                printf("Jogador O ganhou!\n");//quando o valor 0 é retornado
                printmatriz();
                return 0; // encerra o programa
            } else if (verifica() == 3)
            {
                printf("Empate!\n"); // quando o valor 3 é retornado
                printmatriz();
                return 0; // encerra o programa
            }
            system("clear");// caso seu sistema seja windows, substitua clear por cls
            continue; // passa a vez para o prox jogador
        }
    } while (jogador!=3);// como o jogador nunca recebera o valor 3 (só existem 2 jogadores) o laço while é infinito, então o programa só será encerrado se alguma das condições forem cumpridas (vitória ou empate)
    return 0;
}
