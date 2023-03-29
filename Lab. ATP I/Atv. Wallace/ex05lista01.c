/*5. Faça um algoritmo para ler três valores reais e informar se estes podem ou não formar
os lados de um triângulo. Em caso afirmativo, classificar o triângulo entre equilátero,
isósceles ou escaleno.*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a,b,c;
    //entrada
    do{
        printf("Digite os três lados para formação de um triângulo:\n");
        scanf("%f",&a);
        scanf("%f",&b);
        scanf("%f",&c);
        if (a<=0 || b<=0 || c<=0)
        {
            printf("Um triângulo não pode possuir um lado nulo ou negativo, por favor digite um valor válido!\n");
        }
    } while (a<=0 || b<=0 || c<=0);
    //análise/saídas
    if (a<b+c && b<a+c && c<a+b)
    {
        printf("Seu triângulo existe!\n");
        if (a==b && b==c && a==c)
        {
            printf("Seu triângulo é equilátero.\n");
        } else if (a==b || a==c || b==c)
        {
            printf("Seu triângulo é isósceles.\n");
        } else {
            printf("Seu triângulo é escaleno.\n");
        }
    } else {
        printf("Um triângulo não pode ser formado com essas medidas.\n");
    }
    return 0;
}
