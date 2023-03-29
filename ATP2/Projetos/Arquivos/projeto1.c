// Inclusão de bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define do tamanho máximo das palavras
#define maxpal 50

int main(int argc, char *argv[]) {
  // Declaração das variáveis usadas
  FILE *cod, *pal, *lin;
  int num, i, cont = 0;
  char string[maxpal];
  char arr[5][maxpal];

  // Abertura e verificação dos arquivos
  cod = fopen("codigos.dat", "r");
  pal = fopen("palavras.dat", "r");
  lin = fopen("linhas.dat", "w");
  if (cod == NULL || pal == NULL || lin == NULL) {
    printf("Não foi possível abrir os arquivos necessários!\n");
    exit(0);
  }

  // Laço de repetição principal para leitura dos dois arquivos ao mesmo tempo
  while (!feof(cod) && !feof(pal)) {
    // Lê o número dentro do arquivo codigos.dat
    fscanf(cod, "%d ", &num);

    if (num > 0) { // Se o número for maior que zero, ele lê o arquivo de
                   // palavras e escreve no arquivo de saída N palavras
      for (i = 0; i < num; i++) {
        fscanf(pal, "%s ", string);
        strcpy(arr[cont % 5],
               string); // Enquanto isso ele vai guardando as últimas palavras
                        // lidas em um array de strings para ser usando mais
                        // para frente
        cont++; // Usamos %5 para ele sempre ir rodando o array de 5 posições de
                // forma circular, tudo isso mediado por uma variável contadora
        fprintf(lin, "%s ", string);
      }
    } else if (num < 0) { // Caso o número seja menor que zero, escrevemos no
                          // arquivo as últimas N palavras
      cont += num; // Somamos o número de palavras na variável contadora, como o
                   // número é negativo ocorre uma subtração
      for (i = 0; i < abs(num); i++) {
        fprintf(lin, "%s ",
                arr[cont %
                    5]); // Percorre o array de forma circular, lendo e
                         // escrevendo no arquivo de saída as últimas N palavras
        cont++; // Mediado pela variável contadora
      }
    } else { // Caso o número seja zero, escrevemos 0 no arquivo de saída
      fprintf(lin, "0");
    }
    fprintf(lin, "\n"); // Passamos para próxima linha do arquivo de saída
  }

  // Quando um arquivo termina ele verifica se ainda existe algum arquivo que
  // não chegou no fim
  if (!feof(pal)) { // Caso o arquivo palavras não tenha terminado
    i = 1; // Começamos com i = 1 para não ocorre o problema de pular uma linha
           // antes escrevermos 5 palavras
    while (!feof(pal)) {
      fscanf(pal, "%s ",
             string); // Lẽ as palavras restantes e escreve no arquivo de saída
                      // até chegar ao fim do arquivo
      fprintf(lin, "%s ", string);
      if (!(i % 5)) {
        fprintf(
            lin,
            "\n"); // Pula uma linhas a cada 5 palavras, para escrever de 5 em 5
      }
      i++;
    }
  } else if (!feof(cod)) { // Caso o arquivo de números não tenha terminado
    while (!feof(cod)) {
      fscanf(cod, "%d ",
             &num); // Lê os números restantes e escreve no arquivo de saída
      fprintf(lin, "%d ", num);
    }
  }

  // Fecha os arquivos utilizados
  fclose(cod);
  fclose(pal);
  fclose(lin);
  return 0;
}
