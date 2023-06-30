#include <stdio.h>

int comapara(char str1[30],char str2[30])
{
    int i = 0;
    while (str1[i]!='\0' && str2[i]!='\0' && str1[i] == str2[i])
        i++;
    return str1[i] - str2[i];     
}

int main(int argc, char const *argv[])
{
    char vetor[30], vetor2[30];
    int b = 1;
    char c;
    scanf(" %s",vetor);
    scanf(" %s",vetor2);
    int i = 0;
     
    
    b = comapara(vetor,vetor2);
    if (b)
    {
        printf("dif");
    } else {
        printf("igu");
    }
    

    return 0;
}
