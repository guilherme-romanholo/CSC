#include <stdio.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
    typedef struct complexos
    {
        float real;
        float imag;
        float complex z; // declara um numero float do tipo complexo chamado z
        float complex conj;
    }Comp;
    Comp num;
    printf("Digite a parte real:\n");
    scanf("%f",&num.real);
    printf("Digite a parte imágina:\n");
    scanf("%f",&num.imag);
    num.z = CMPLX(num.real,num.imag);// função CMPLX() "concatena" as partes do numero em um complexo
    num.conj = conjf(num.z);
    printf("Argumento: %.2f\n",cargf(num.z)*180/3.1415); // função cargf() calcula o argumento de um numero complexo float, mas retorna o valor em radianos, então precisa converter para graus 
    printf("Conjugado: %.2f% + .2fi\n",creal(num.conj),cimag(num.conj));    
    return 0;
}
