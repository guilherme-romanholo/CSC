#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char string[50], aux, c;
    scanf(" %[^\n]s",string);
    for (int i = 0, j = strlen(string) - 1; i < strlen(string)/2 ; i++, j--)
    {
        aux = string[i];
        string[i] = string[j];
        string[j] = aux;
    }
    printf("%s",string); 
    return 0;
}
