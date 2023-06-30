#include <stdio.h>
#include <string.h>
#define n 6

int main(int argc, char const *argv[])
{
    int opc, i = -1, opc6, estoque, auxestoque, opc2;
    char c, codigo[60];
    float lucroTot = 0;
    typedef struct produtos
    {
        char nome[60];
        char cod[60];
        float preco;
        int qtd;
        int baixa;
        float lucro;
    } prod;
    prod registros[n];
    //teste
    for (int j = 0; j < n; j++)
    {
        registros[j].baixa = 0;
    }
    for (int j = 0; j < n; j++)
    {
        registros[j].lucro = 0;
    }
    //fim teste
    //depois tentar arrumar o atualizar lucros e deixar sem ele
    do
    {
        printf("Escolha a opção:\n");
        printf("[1]Cadastrar o produto\n[2]Adicionar Estoque\n[3]Baixar estoque\n[4]Pesquisar um produto\n[5]Lista dos produtos\n[6]Editar preço\n[7]Lucro Vendas\n[8]Trocar Produto\n[9]Atualizar Lucros\n[0]Sair\n");
        scanf("%d",&opc);
        if (opc == 1)
        {
            system("clear");
            i++;
            if (i == n)
            {
                printf("Todos os produtos estão ocupados, por favor troque um produto.\n");
                continue;
            }
            printf("Digite o nome do produto que deseja cadastrar:\n");
            scanf(" %[^\n]s",&registros[i].nome);
            printf("Digite o código do produto:\n");
            scanf(" %s",&registros[i].cod);
            printf("Digite o preço do produto:\n");
            scanf("%f",&registros[i].preco);
            printf("Digite a quantidade do produto:\n");
            scanf("%d",&registros[i].qtd);
            system("clear");
            printf("Produto cadastrado com sucesso!\n");
        } else if (opc == 2)
        {
            system("clear");
            printf("Digite qual produto você deseja aumentar o estoque:\n");
            for (int j = 0; j <= i; j++)
            {
                printf("(%d) %s\n",j,registros[j].nome);
            }
            scanf("%d",&opc6);
            printf("Digite quantas unidade você deseja aumentar:\n");
            scanf("%d",&estoque);
            registros[opc6].qtd += estoque;
            printf("Estoque alterado com sucesso!\nNovo estoque é de %d unidades.\n",registros[opc6].qtd);
            printf("Digite qualquer coisa para continuar...\n");
            scanf(" %c",&c);
            system("clear");
        } else if (opc == 3)
        {
            system("clear");
            printf("Digite qual produto você deseja diminuir o estoque:\n");
            for (int j = 0; j <= i; j++)
            {
                printf("(%d) %s\n",j,registros[j].nome);
            }
            scanf("%d",&opc6);
            printf("Digite quantas unidade você deseja diminuir:\n");
            scanf("%d",&estoque);
            registros[opc6].qtd -= estoque;
            registros[opc6].baixa = estoque;
            printf("Estoque alterado com sucesso!\nNovo estoque é de %d unidades.\n",registros[opc6].qtd);
            printf("Digite qualquer coisa para continuar...\n");
            scanf(" %c",&c);
            system("clear");
        } else if (opc == 4)
        {
            system("clear");
            printf("Digite o código do produto para ver suas informações:\n");
            scanf(" %s",&codigo);
            for (int j = 0; j <= i; j++)
            {
                if (!(strcmp(codigo,registros[i].cod)))
                {
                    printf("Nome: %s\n",registros[j].nome);
                    printf("Preço: R$%.2f\n",registros[j].preco);
                    printf("Estoque: %d\n",registros[j].qtd);
                    printf("Baixa da ultima venda: %d\n",registros[j].baixa);
                    printf("Digite qualquer coisa para continuar...\n");
                    scanf(" %c",&c);
                    system("clear");
                }
            }
        } else if (opc == 5)
        {
            system("clear");
            if (i == -1)
            {
                printf("Nenhum produto cadastrado.\n");
                continue;
            }
            for (int j = 0; j <= i ;j++)
            {
                printf("Produto: %s\nCódigo: %s\n\n",registros[j].nome,registros[j].cod);
            }
            printf("Digite qualquer coisa para continuar...\n");
            scanf(" %c",&c);
            system("clear");
        } else if (opc == 6)
        {
            system("clear");
            printf("Digite qual produto você deseja mudar o preço:\n");
            for (int j = 0; j <= i; j++)
            {
                printf("(%d) %s\n",j,registros[j].nome);
            }
            scanf("%d",&opc6);
            printf("Digite o preço novo:\n");
            scanf("%f",&registros[opc6].preco);
            printf("Preço alterado com sucesso!\n");
            printf("Digite qualquer coisa para continuar...\n");
            scanf(" %c",&c);
            system("clear");
        } else if (opc == 7)
        {
            system("clear");
            printf("[1]Lucro de um produto\n[2]Lucro Total\n");
            scanf("%d",&opc2);
            if (opc2 == 1)
            {
                printf("Escolha qual produto você deseja saber o lucro:\n");
                for (int j = 0; j <= i; j++)
                {
                    printf("(%d) %s\n",j,registros[j].nome);
                }
                scanf("%d",&opc6);
                registros[opc6].lucro += registros[opc6].preco*registros[opc6].baixa; //não funciona
                printf("O lucro desse produto foi %f.\nDeseja resetar o lucro desse produto? <s>im/<n>ão\n");
                scanf(" %c",&c);
                if (c == 's')
                {
                    registros[opc6].lucro = 0;
                    printf("Lucro do produto resetado!\n");
                }
            } else if (opc2 == 2)
            {
                printf("O lucro total dos produtos é R$%f.\nDeseja resetar o lucro total? <s>im/<n>ão\n",lucroTot);
                scanf(" %c",&c);
                if (c == 's')
                {
                    lucroTot = 0;
                    printf("Lucro total resetado!\n");
                }
            }
            printf("Digite qualquer coisa para continuar...\n");
            scanf(" %c",&c);
            system("clear");
        } else if (opc == 8)
        {
            printf("Escolha qual produto você deseja substituir:\n");
            for (int j = 0; j <= i; j++)
            {
                printf("(%d) %s\n",j,registros[j].nome);
            }
            scanf("%d",&opc6);
            printf("Digite o nome do produto que deseja cadastrar:\n");
            scanf(" %[^\n]s",&registros[opc6].nome);
            printf("Digite o código do produto:\n");
            scanf(" %s",&registros[opc6].cod);
            printf("Digite o preço do produto:\n");
            scanf("%f",&registros[opc6].preco);
            printf("Digite a quantidade do produto:\n");
            scanf("%d",&registros[opc6].qtd);
            system("clear");
            printf("Produto substituído com sucesso!\n");
        } else if (opc == 9)
        {
            for (int j = 0; j <= i; j++)
                {
                    lucroTot += registros[j].lucro;
                }
        }
        
    } while (opc!=0);
    printf("Programa finalizado!\n");
    return 0;
}
