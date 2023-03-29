#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{   
    srand(time(NULL));
    int vetor[10], somaTot = 0, somaPares = 0, somaImp = 0, par = 0, impar = 0;
    for (int i = 0; i < 10; i++)
    {
        vetor[i] = rand() % 100;
        somaTot += vetor[i];
        printf("%d ", vetor[i]);
        if (vetor[i]%2)
        {
            somaImp += vetor[i];
            impar++;    
        } else {
            somaPares += vetor[i];
            par++;
        }     
    }
    printf("A média dos numeros é: %.2f\n", (float)somaTot/10);
    printf("A média dos numeros pares é: %.2f\n", (float)somaPares/par);
    printf("A média dos numeros impares é: %.2f\n", (float)somaImp/impar);
    printf("A quantidade de numeros pares é %d\n", par);
    printf("A quantidade de numeros impares é %d\n", impar);
    return 0;
}
