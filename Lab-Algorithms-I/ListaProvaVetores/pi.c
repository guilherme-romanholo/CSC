#include <stdio.h>
#include <math.h>
int main()
{
    double aprox,aproxAnt;
    double dif,soma,termo;
    int den,cont;

    soma = 0;
    den = 1;
    cont = 0;
    dif = 1;
    aproxAnt = 10;
    while(dif > 0.000001){
        termo = 1.0/den;
        if (cont%2){
            soma = soma + termo;
        }
        else{
            soma = soma - termo;
        }
        aprox = 4 * soma;
        dif = fabs(aprox-aproxAnt);

        aproxAnt = aprox;
        den = den + 2;
        cont++;
    }
    printf("%.7f",aprox);
    return 0;
}