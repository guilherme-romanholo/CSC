//Código para validação do CPF

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char cpf_string[12];// tipo char para facilitar a entrada do CPF no Scanf
    int cpf[11];// tipo int para ser armazenado o CPF após a entrada
    int flag = 0;// variável de controle utilizada na verificação
    int soma1 = 0, soma2 = 0;//utilizadas nas regras 2 e 3
    int verificador1, verificador2;//digitos verificadores 
    //Entrada
    printf("Digite o CPF para ser verificado:\n");
    scanf(" %s",&cpf_string);
    //Conversão de char para int
    for (int i = 0; i < 11; i++)// i < 11 pois não é necessário utilizar o último caractere da string (\0)
    {
        cpf[i] = cpf_string[i] - '0'; // Na tabela ASCII o caractere '0' possui valor inteiro de 48, o caractere '1' possui valor inteiro de 49, o caractere '2' possui valor de '50' e assim por diante. Dessa forma, se calcularmos '2' - '0', é a mesma coisa de fazer 50 - 48 com os valores inteiros convertidos pela tabela ASCII, o que resulta no valor inteiro 2. Se calcularmos '1' - '0', estamos fazendo 49 - 48 = 1. Isso funciona como um "macete" para conversão de uma número como caractere para inteiro.
    }
    //Validação do CPF

    //Regra 1: Verificar se todos os valores do CPF são iguais
    for (int i = 0; i < 10; i++)//Usamos i < 10 pois não é necessário verificar quando o i = 10, se não ele vai verificar com um elemento que não existe no vetor
    {
        if (cpf[i] != cpf[i+1])
        {
            flag = 1;// Verificamos os dígitos do CPF de 2 em 2, caso pelo menos um par for diferente isso significa que o CPF não possui todos os valores iguais, assim atribuímos o valor 1 para nossa variável de controle. 
        }
    }
    if (flag == 0)
    {
        printf("CPF inválido!");
        return 0; //Finaliza o programa
    }
    //Regra 2: Validando o primeiro dígito verificador
    //Para essa validação, pegamos o primeiro número do CPF e multiplicamos por 10, depois pegamos o segundo número e multiplicamos por 9, e assim até o nono número. Após isso os resultados devem ser somados e divididos por 11, pegando o resto nos subtraímos esse valor de 11 e seu resultado tem que ser o primeiro dígito verificador do CPF.

    for (int i = 0, j = 10; i < 9; i++, j--)//Como são só os nove primeiros dígitos o laço deve rodar até i < 9, incrementando o i e decrementando o j, que é por que nós iremos multiplicar
    {
        soma1 += cpf[i]*j;
    }
    verificador1 = 11 - (soma1 % 11);
    if (verificador1 == 10)
    {
        verificador1 = 0;//A regra diz que se o resultado for 10 o dígito verificador deve ser 0
    }
    if (verificador1 != cpf[9])
    {
        printf("CPF inválido!");
        return 0; //Finaliza o programa
    }

    //Regra 3: Validando o segundo dígito verificador
    //Para essa validação fazemos o mesmo da primeira, mas dessa vez incluindo o primeiro dígito verificador, ou seja, até o décimo número do CPF e nossa multiplicação começa por 11 em vez de 10.
    for (int i = 0, j = 11; i < 10; i++,j--)//Mesmo esquema do primeiro dígito
    {
        soma2 += cpf[i]*j;
    }
    verificador2 = 11 - (soma2 % 11);
    if (verificador2 == 10)
    {
        verificador2 = 0;
    }
    if (verificador2 != cpf[10])
    {
        printf("CPF inválido!");
        return 0; // Finaliza o programa
    } else {
        printf("CPF válido!");
    }
    //Como o código é lido de uma maneira linear ele só vai chegar no CPF válido se passar por todos os outros testes acima, mas o melhor modo de fazer esse código otimizado seria com Ifs encadeados e aninhados.
    return 0;
}
