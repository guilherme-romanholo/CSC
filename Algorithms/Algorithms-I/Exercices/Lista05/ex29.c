#include <stdio.h>

int main(int argc, char const *argv[])
{
    char nome1[5][60], nome2[5][60];

    for (int i = 0; i < 5; i++)
        scanf(" %s",&nome1[i]);
    
    for (int i = 0, j = 0; i < 5; i++)
    {
      printf("%s ",nome1[i]);
    }


    return 0;
}
