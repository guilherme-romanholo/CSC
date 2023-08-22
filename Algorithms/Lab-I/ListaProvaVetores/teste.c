#include <stdio.h>

int main(int argc, char const *argv[])
{
    int count = 0;
    for (int i = 501; i < 1000; i++)
    {
        if (i%10 == (i%100)/10 && i%10 == (i%1000)/100)
            count++;
    }
    printf("%d\n",count);
    return 0;
}