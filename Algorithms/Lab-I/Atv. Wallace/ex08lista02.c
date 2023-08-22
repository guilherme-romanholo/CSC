/*8. Escreva um algoritmo que, dado o primeiro elemento, a razão (valor positivo ou
negativo), e o número de termos N de uma Progressão Aritmética (PA), imprima todos
os N primeiros elementos da progressão.*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    float razao, primT;
    int numT;
    //entrada
    printf("Digite o primeiro elemento, a razão e o número de termos para a progressão aritmética respectivamente:\n");
    scanf("%f",&primT); 
    scanf("%f",&razao); 
    scanf("%d",&numT);
    //saída
    for (int i = 0; i < numT; i++)
    {
        printf("%.2f ",primT);
        primT = primT + razao;
    }
    printf("\n");
    return 0;
}
