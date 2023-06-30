#include <stdio.h>

int main(int argc, char const *argv[])
{
    char cpf[21], cpfFormt[15] = {'*','*','*','.','*','*','*','.','*','*','*','-','*','*'};
    scanf(" %s",cpf);
    for ( int i = 0, j = 0; i < 12; i++, j++)
    {
        if (cpfFormt[j] == '*')
        {
            cpfFormt[j] = cpf[i];
        } else
        {
            cpfFormt[j+1] = cpf[i];
            j++;   
        }
    }
    printf("%s",cpfFormt);
    return 0;
}
