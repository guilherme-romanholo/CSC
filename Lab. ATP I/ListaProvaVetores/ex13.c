#include <stdio.h>

int main(int argc, char const *argv[])
{
    char nome[20],sobrenome[20], nome3[40];
    int i = 0, j = 0, len = 0;
    scanf(" %s",nome);
    scanf(" %s",sobrenome);
    while (nome[i] != '\0')
    {
        nome3[i] = nome[i];
        i++;
    }
    nome3[i] = ' ';
    i++;
    while (sobrenome[j] != '\0')
    {
        nome3[i] = sobrenome[j];
        i++;
        j++;
    }
    nome3[i] = '\0';
    i = 0;
    while (nome3[i] != '\0')
    {
        i++;
        len++;
    }
    printf("%s\n",nome3);;
    printf("%c\n",nome3[0]);
    printf("%d\n",len-1);   
    return 0;
}
