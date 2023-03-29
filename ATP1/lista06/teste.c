#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1, mult = 1;
    scanf("%d",&num1);
    while (num1!=0)
    {
        mult = mult*num1;
        num1--;
    }
    printf("%d",mult);
    return 0;
}
