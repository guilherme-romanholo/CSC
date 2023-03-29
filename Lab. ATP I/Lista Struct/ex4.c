#include <stdio.h>
#include <math.h>
#include <complex.h>
#define m 2

int main(int argc, char const *argv[])
{
    typedef struct complexos
    {
        float re;
        float im;
        float complex z;
    }Comp;
    Comp num[m];
    char opc;
    for (int i = 0; i < m; i++)
    {
        printf("Digite a parte real\n");
        scanf("%f",&num[i].re);
        printf("Digite a parte imágina\n");
        scanf("%f",&num[i].im);
        num[i].z = CMPLX(num[i].re,num[i].im);
    }
    printf("Número escolhidos: (%.2f + %.2fi) e (%.2f + %.2fi)\n",num[0].re,num[0].im,num[1].re,num[1].im);
    printf("A soma entre os dois número complexos é: (%.2f + %.2fi)\n",num[0].re+num[1].re,num[0].im+num[1].im);         
    printf("O produto entre os dois número é (%.2f + %.2fi)\n",(num[0].re*num[1].re)-(num[0].im*num[1].im),(num[0].re*num[1].im)-(num[0].im*num[1].re));
    printf("O módulo dos números digitados são: %.2f e %.2f\n",sqrt(pow(num[0].re,2)+pow(num[0].im,2)),sqrt(pow(num[1].re,2)+pow(num[1].im,2)));
    printf("Os conjugados dos números complexos digitados são: (%.2f - %.2fi) e (%.2f - %.2fi)\n",num[0].re,num[0].im,num[1].re,num[1].im);
    printf("Os argumentos dos número complexos digitados são:%.2f graus e %.2f graus\n",cargf(num[0].z),cargf(num[1].z));
    return 0;
}
