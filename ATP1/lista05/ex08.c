#include <stdio.h>

int main(int argc, char const *argv[])
{
    int opc,opc1,opc2,opc3,opc5,opc6,opc7,prod1=0,prod2=0,prod3=0,prod4=0,prod5=0,aumento=0;
    char produto1[50] = "-------",produto2[50] = "-------",produto3[50] = "-------",produto4[50] = "-------",produto5[50] = "-------";
    float preco1=0,preco2=0,preco3=0,preco4=0,preco5=0,aumentoP=0;
    do
    {
        printf("[1] Aumentar estoque:\n[2] Baixar estoque:\n[3] Visualizar estoque de um produto:\n[4] Visualizar estoque total:\n[5] Aumentar preço:\n[6] Diminuir o preço:\n[7] Trocar produto:\n[0] Sair:\n");
        scanf("%d",&opc);
        system("clear");
        if (opc==1)
        {
            printf("Você gostaria de aumentar o estoque de qual produto?\n[1] %s\n[2] %s\n[3] %s\n[4] %s\n[5] %s\n[0] Voltar\n",produto1,produto2,produto3,produto4,produto5);
            scanf("%d",&opc1);
            if (opc1==0)
            {
                continue;
            } else if (opc1==1)
            {
                printf("Você gostaria de aumentar em quantas unidades o estoque de %s?\n",produto1);
                scanf("%d",&aumento);
                prod1 += aumento;
            } else if (opc1==2)
            {
                printf("Você gostaria de aumentar em quantas unidades o estoque de %s?\n",produto2);
                scanf("%d",&aumento);
                prod2 += aumento;
            } else if (opc1==3)
            {
                printf("Você gostaria de aumentar em quantas unidades o estoque de %s?\n",produto3);
                scanf("%d",&aumento);
                prod3 += aumento;
            } else if (opc1==4)
            {
                printf("Você gostaria de aumentar em quantas unidades o estoque de %s?\n",produto4);
                scanf("%d",&aumento);
                prod4 += aumento;
            } else if (opc1==5)
            {
                printf("Você gostaria de aumentar em quantas unidades o estoque de %s?\n",produto5);
                scanf("%d",&aumento);
                prod5 += aumento;
            }   
        } else if (opc==2)
        {
            printf("Você gostaria de baixar o estoque de qual produto?\n[1] %s\n[2] %s\n[3] %s\n[4] %s\n[5] %s\n[0] Voltar\n",produto1,produto2,produto3,produto4,produto5);
            scanf("%d",&opc2);
            if (opc2==0)
            {
                continue;
            } else if (opc2==1)
            {
                printf("Você gostaria de baixar em quantas unidades o estoque de %s?\n",prod1);
                scanf("%d",&aumento);
                prod1 -= aumento;
            } else if (opc2==2)
            {
                printf("Você gostaria de baixar em quantas unidades o estoque de %s?\n",prod2);
                scanf("%d",&aumento);
                prod2 -= aumento;
            } else if (opc2==3)
            {
                printf("Você gostaria de baixar em quantas unidades o estoque de %s?\n",prod3);
                scanf("%d",&aumento);
                prod3 -= aumento;
            } else if (opc2==4)
            {
                printf("Você gostaria de baixar em quantas unidades o estoque de %s?\n",prod4);
                scanf("%d",&aumento);
                prod4 -= aumento;
            } else if (opc2==5)
            {
                printf("Você gostaria de baixar em quantas unidades o estoque de %s?\n",prod5);
                scanf("%d",&aumento);
                prod5 -= aumento;
            }   
        } else if (opc==3)
        {
            printf("Você gostaria de ver o estoque de qual produto?\n[1] %s\n[2] %s\n[3] %s\n[4] %s\n[5] %s\n[0] Voltar\n",produto1,produto2,produto3,produto4,produto5);
            scanf("%d",&opc3);
            if (opc3==0)
            {
                continue;
            } else if (opc3==1)
            {
                printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto1,prod1,preco1);
            }else if (opc3==2)
            {
                printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto2,prod2,preco2);
            }else if (opc3==3)
            {
                printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto3,prod3,preco3);
            } else if (opc3==4)
            {
                printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto4,prod4,preco4);
            } else if (opc3==5)
            {
                printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto5,prod5,preco5);
            } 
        } else if (opc==4)
        {
            printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto1,prod1,preco1);
            printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto2,prod2,preco2); 
            printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto3,prod3,preco3); 
            printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto4,prod4,preco4); 
            printf("O produto %s possui %d unidades no estoque e um preço de R$%.2f.\n",produto5,prod5,preco5);
        } else if (opc==5)
        {
            printf("Você gostaria de aumentar o preço de qual produto?\n[1] %s\n[2] %s\n[3] %s\n[4] %s\n[5] %s\n[0] Voltar\n",produto1,produto2,produto3,produto4,produto5);
            scanf("%d",&opc5);
            if (opc5==0)
            {
                continue;
            } else if (opc5==1)
            {
                printf("Digite quanto você quer aumentar o preço:\n");
                scanf("%f",&aumentoP);
                preco1 += aumentoP;               
            } else if (opc5==2)
            {
                printf("Digite quanto você quer aumentar o preço:\n");  
                scanf("%f",&aumentoP);
                preco2 += aumentoP;                
            } else if (opc5==3)
            {
                printf("Digite quanto você quer aumentar o preço:\n");  
                scanf("%f",&aumentoP);
                preco3 += aumentoP;                
            } else if (opc5==4)
            {
                printf("Digite quanto você quer aumentar o preço:\n");   
                scanf("%f",&aumentoP);
                preco4 += aumentoP;               
            } else if (opc5==5)
            {
                printf("Digite quanto você quer aumentar o preço:\n");    
                scanf("%f",&aumentoP);
                preco5 += aumentoP;              
            }  
        } 
        else if (opc==6)
        {
            printf("Você gostaria de diminuir o preço de qual produto?\n[1] %s\n[2] %s\n[3] %s\n[4] %s\n[5] %s\n[0] Voltar\n",produto1,produto2,produto3,produto4,produto5);
            scanf("%d",&opc6);
            if (opc6==0)
            {
                continue;
            } else if (opc6==1)
            {
                printf("Digite quanto você quer diminuir o preço:\n");
                scanf("%f",&aumentoP);
                preco1 -= aumentoP;               
            } else if (opc6==2)
            {
                printf("Digite quanto você quer diminuir o preço:\n");  
                scanf("%f",&aumentoP);
                preco2 -= aumentoP;                
            } else if (opc6==3)
            {
                printf("Digite quanto você quer diminuir o preço:\n");  
                scanf("%f",&aumentoP);
                preco3 -= aumentoP;                
            } else if (opc6==4)
            {
                printf("Digite quanto você quer diminuir o preço:\n");   
                scanf("%f",&aumentoP);
                preco4 -= aumentoP;               
            } else if (opc6==5)
            {
                printf("Digite quanto você quer diminuir o preço:\n");    
                scanf("%f",&aumentoP);
                preco5 -= aumentoP;              
            } 
        } else if (opc==7)
        {
            printf("Você gostaria de cadastrar um produto no lugar de qual desses?\n[1] %s\n[2] %s\n[3] %s\n[4] %s\n[5] %s\n[0] Voltar\n",produto1,produto2,produto3,produto4,produto5);
            scanf("%d",&opc7);
            if (opc7==0)
            {
                continue;
            } else if (opc7==1)
            {
                printf("Digite o nome do novo produto:\n");
                scanf(" %[^\n]s",produto1);
                printf("Digite quantas unidades do novo produto:\n");
                scanf("%d",&prod1);
                printf("Digite o preço do produto:\n");
                scanf("%f",&preco1);
                printf("Produto cadastrado!\n");
            } else if (opc7==2)
            {    
                printf("Digite o nome do novo produto:\n");
                scanf(" %[^\n]s",produto2);
                printf("Digite quantas unidades do novo produto:\n");
                scanf("%d",&prod2);
                printf("Digite o preço do produto:\n");
                scanf("%f",&preco2);
                printf("Produto cadastrado!\n");
            } else if (opc7==3)
            {    
                printf("Digite o nome do novo produto:\n");
                scanf(" %[^\n]s",produto3);
                printf("Digite quantas unidades do novo produto:\n");
                scanf("%d",&prod3);
                printf("Digite o preço do produto:\n");
                scanf("%f",&preco3);
                printf("Produto cadastrado!\n");
            } else if (opc7==4)
            {    
                printf("Digite o nome do novo produto:\n");
                scanf(" %[^\n]s",produto4);
                printf("Digite quantas unidades do novo produto:\n");
                scanf("%d",&prod4);
                printf("Digite o preço do produto:\n");
                scanf("%f",&preco4);
                printf("Produto cadastrado!\n");
            } else if (opc7==5)
            {   
                printf("Digite o nome do novo produto:\n");
                scanf(" %[^\n]s",produto5);
                printf("Digite quantas unidades do novo produto:\n");
                scanf("%d",&prod5);
                printf("Digite o preço do produto:\n");
                scanf("%f",&preco5);
                printf("Produto cadastrado!\n");
            }
        } else if (opc>7 || opc<0){
            printf("Digite uma opção válida:\n");
            scanf("%d",&opc);
        }
    } while (opc!=0);
    return 0;
}
