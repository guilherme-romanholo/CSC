#include "conjunto.h"
#include <stdio.h>

int main(){
    conj_t *numerosInteiros, *numerosPositivos, *numerosNegativos;

    criaConjVazio(&numerosNegativos);
    criaConjVazio(&numerosPositivos);

    insere("-12", &numerosNegativos);
    insere("-4", &numerosNegativos);
    insere("-63", &numerosNegativos);
    insere("-3", &numerosNegativos);

    insere("12", &numerosPositivos);
    insere("4", &numerosPositivos);
    insere("63", &numerosPositivos);
    insere("3", &numerosPositivos);

    printConjunto(numerosNegativos);
    printConjunto(numerosPositivos);

    uniao(numerosPositivos,numerosNegativos,&numerosInteiros);

    printf("%d\n",membro("3",numerosPositivos));
    printConjunto(numerosInteiros);

    return 0;
}