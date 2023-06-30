/*13.Escreva um programa que leia do teclado vários números inteiros. Quando um
número negativo for digitado, encerre o processo, calcule e mostre:
(a) A soma de todos os números digitados.
(b) A quantidade de números digitados.
(c) A média dos números digitados.
(d) O maior número digitado.
(e) O menor número digitado.*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, qtd = 0, maior = 0, menor, media, soma = 0;
    //entrada
    printf("Digite os números positivos que quiser e um número negativo para encerrar o programa:\n");
    do
    {
        scanf("%d",&num);
        if(num>=0){
            qtd++;
            if (qtd==1)
            {
                maior = num;
                menor = num;
                soma += num; 
            } else {
                if (num>maior)
                {
                    maior = num;
                }
                if (num<menor)
                {
                    menor = num;
                }
                soma += num;
            }
        }           
    } while (num>=0);
    //saídas
    printf("A soma de todos os número digitados é %d\n",soma);
    printf("A quantidade de números digitados é %d\n",qtd);
    printf("A média dos números digitados é %.2f\n",(float)soma/(float)qtd);    
    printf("O maior número digitado é %d\n",maior);
    printf("O menor número digitado é %d\n",menor);
    return 0;
}
