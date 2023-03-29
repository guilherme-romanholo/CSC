#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct datas
    {
        int dia,mes,ano;
    }Dat;
    printf("Digite um dia:\n");
    scanf("%d",&Dat.dia);
    printf("Digite um mês:\n");
    scanf("%d",&Dat.mes);
    printf("Digite um ano:\n");
    scanf("%d",&Dat.ano);
    switch (Dat.mes)
    {
    case 1:
        printf("%d/janeiro/%d\n",Dat.dia,Dat.ano);
        break;
    case 2:
        printf("%d/fevereiro/%d\n",Dat.dia,Dat.ano);
        break;
    case 3:
        printf("%d/março/%d\n",Dat.dia,Dat.ano);
        break;
    case 4:
        printf("%d/abril/%d\n",Dat.dia,Dat.ano);
        break;
    case 5:
        printf("%d/maio/%d\n",Dat.dia,Dat.ano);
        break;
    case 6:
        printf("%d/junho/%d\n",Dat.dia,Dat.ano);
        break;
    case 7:
        printf("%d/julho/%d\n",Dat.dia,Dat.ano);
        break;
    case 8:
        printf("%d/agosto/%d\n",Dat.dia,Dat.ano);
        break;
    case 9:
        printf("%d/setembro/%d\n",Dat.dia,Dat.ano);
        break;
    case 10:
        printf("%d/outubro/%d\n",Dat.dia,Dat.ano);
        break;
    case 11:
        printf("%d/novembro/%d\n",Dat.dia,Dat.ano);
        break;
    case 12:
        printf("%d/dezembro/%d\n",Dat.dia,Dat.ano);
        break;
    default:
        break;
    }
    return 0;
}
