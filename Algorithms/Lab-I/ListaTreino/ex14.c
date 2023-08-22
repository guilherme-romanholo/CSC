#include <stdio.h>

int main(int argc, char const *argv[])
{
    char nome[80], nomeF[10];
    int j = 0;
    scanf(" %[^\n]s",nome);
    for (int i = 0; i < 80; i++)
    {
        if(i == 0)
        {
        nomeF[j] = nome[0];
        j++;
        }
        if (nome[i] == ' ')
        {
            nomeF[j] = nome[i+1];
            j++;
        }
    }
    nomeF[j] = '\0';
    j = 0;
    while (nomeF[j]!='\0')
    {
        printf("%c. ",nomeF[j]);
        j++;
    }
    printf("\n");
    return 0;
}
