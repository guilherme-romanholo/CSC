/*12.Faça um algoritmo que receba o valor de venda; escolha a condição de pagamento
selecionada no menu, e mostre o total da venda final conforme as condições a seguir:
1. Venda a Prazo – desconto de 10%.
2. Venda a Prazo 30 dias – desconto de 5%.
3. Venda a Prazo 60 dias – mesmo preço.
4. Venda a Prazo 90 dias – acréscimo de 5%.
5. Venda com Cartão de Débito – desconto de 8%.
6. Venda com Cartão de Crédito – desconto de 7%.*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int opc;
    float precoInic, precoFim;
    //entrada do preço
    printf("Digite o valor do produto comprado:\n");
    scanf("%f",&precoInic);
    do //escolha da opção
    {
        printf("Escolha a condição de pagamento:\n");
        printf("1. Venda a Prazo – desconto de 10%%.\n2. Venda a Prazo 30 dias – desconto de 5%%.\n3. Venda a Prazo 60 dias – mesmo preço.\n4. Venda a Prazo 90 dias – acréscimo de 5%%.\n5. Venda com Cartão de Débito – desconto de 8%%.\n6. Venda com Cartão de Crédito – desconto de 7%%.\n");
        scanf("%d",&opc);
        if (opc>6 || opc<1)
        {
            system("clear");   
            printf("Opção inválida, tente novamente.");
        }
    } while (opc>6 || opc<1);
    switch (opc)//saídas 
    {
    case 1:
        precoFim = precoInic*0.9;
        printf("O valor a pagar a prazo possui um desconto de 10%% é: R$%.2f\n",precoFim);
        break;
    case 2:
        precoFim = precoInic*0.95;
        printf("O valor a pagar em 30 dias possui um desconto de 5%% é: R$%.2f\n",precoFim);
        break;
    case 3:
        precoFim = precoInic;
        printf("O valor a pagar em 60 dias possui o preço original: R$%.2f\n",precoFim);
        break;

    case 4:
        precoFim = precoInic*1.05;
        printf("O valor a pagar em 90 dias possui um acréscimo de 5%%: R$%.2f\n",precoFim);
        break;

    case 5:
        precoFim = precoInic*0.92;
        printf("O valor a pagar com cartão de débito possui desconto de 8%% é: R$%.2f\n",precoFim);
        break;

    case 6:
        precoFim = precoInic*0.93;
        printf("O valor a pagar com cartão de crédito possui desconto de 7%% é: R$%.2f\n",precoFim);
        break;
    default:
        break;
    }
    return 0;
}
