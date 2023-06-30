#include <stdio.h>

int main(int argc, char const *argv[])
{
    int voto;
    float cand1 = 0,cand2 = 0,cand3 = 0,cand4 = 0,nulo = 0,branco = 0,tot = 0;
    float perc;
    do
    {
        printf("Escolha sua opção:\n");
        printf("1,2,3,4 - Para os respectivos candidatos\n5 - Voto nulo\n6 - Voto em branco\n0 - Parar a apuração\n");
        scanf("%d",&voto);
        switch (voto)
        {
        case 1:
            cand1++;
            tot++;
            break;
        case 2:
            cand2++;
            tot++;
            break;
        case 3:
            cand3++;
            tot++;
            break;
        case 4:
            cand4++;
            tot++;
            break;        
        case 5:
            nulo++;
            tot++;
            break;
        case 6:
            branco++;
            tot++;
            break;        
        default:
            break;
        }
    } while (voto!=0);
    
    perc = ((branco+nulo)/tot)*100;

    printf("Total de votos para o candidato 1: %.0f\n",cand1);
    printf("Total de votos para o candidato 2: %.0f\n",cand2);
    printf("Total de votos para o candidato 3: %.0f\n",cand3);
    printf("Total de votos para o candidato 4: %.0f\n",cand4);
    printf("Total de votos nulos: %.0f\n",nulo);
    printf("Total de votos brancos: %.0f\n",branco);
    printf("Percentual de votos nulos e branco sobre o total é: %.2f%% \n",perc);

    
    return 0;
}
