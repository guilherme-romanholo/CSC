#include <stdio.h>
#include <time.h>
#define MAX 200000

// Struct para os números BitInt
typedef struct biggo {
  int high;
  int low;
} BigInt;

void insertionSort(BigInt *, int);
void le_arquivo(BigInt *); // Função para leitura do arquivo
void escreve_arquivo(BigInt *); // Função para escrita do arquivo

int main(int argc, char const *argv[]) {
  BigInt vet[MAX];
  time_t t;
  double time;

  // Leitura do arquivo
  le_arquivo(vet);

  // Marcação de tempo durante a execução do sort
  t = clock();
  insertionSort(vet, MAX);
  t = clock() - t;

  // Transforma o tempo em segundos
  time = (double)t / CLOCKS_PER_SEC;
  
  // Escrita no arquivo de output
  escreve_arquivo(vet);

  // Printa o tempo de execução
  printf("%lf\n", time);

  return 0;
}

void insertionSort(BigInt *arr, int n) {
  int i, j;
  BigInt key;

  // Código original do insertion sort com algumas alterações
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j].high >= key.high) {
      // Caso os números possuam a parte high iguais
      if (arr[j].high == key.high) {
        // Fazemos o desempate com a parte low
        if (arr[j].low >= key.low) {
          arr[j + 1] = arr[j];
          j = j - 1;
        } else {
          break;
        }
        // Se não ele realiza o insertion normal
      } else {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    }
    arr[j + 1] = key;
  }
}

void escreve_arquivo(BigInt *vet) {
  FILE *fp;

  fp = fopen("insertion.dat", "w");

  // Escreve no arquivo de output com a parte low
  // positiva como ela estava no arquivo original
  for (int i = 0; i < MAX; i++) {
    if (vet[i].low < 0)
      vet[i].low = -1 * vet[i].low;
    fprintf(fp, "%d %d\n", vet[i].high, vet[i].low);
  }

  fclose(fp);
}

void le_arquivo(BigInt *vet) {
  BigInt big;
  FILE *fp;

  fp = fopen("bigint.dat", "r");

  // Lê o arquivo com a parte low negativa
  // caso o high seja negativo para facilitar a ordenação
  for (int i = 0; i < MAX; i++) {
    fscanf(fp, "%d %d", &big.high, &big.low);
    if (big.high < 0)
      big.low = -1 * big.low;
    vet[i] = big;
  }

  fclose(fp);
}
