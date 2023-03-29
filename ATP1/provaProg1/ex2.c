#include <stdio.h>

int main(int argc, char const *argv[])
{
    int long num,invnum = 0,copia,dig;
    scanf("%d",&num);
    copia = num;
    while (copia>0)
    {
        dig = copia % 10;
        copia = copia/10;
        invnum = invnum*10 + dig;
    }
    printf("%ld\n",invnum);
    if (invnum == num)
    {
        printf("Palíndromo!\n");
    } else {
        printf("Não é palíndromo!\n");
    }
    return 0;
}
