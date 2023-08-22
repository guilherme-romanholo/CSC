#include <stdio.h>
#include <time.h>
#define MAX 200000

// Struct para os números BitInt
typedef struct biggo {
  int high;
  int low;
} BigInt;

// Funções para o quicksort
void troca(BigInt *, BigInt *);
int partition(BigInt *, int, int);
void quickSort(BigInt *, int, int);
// Funções de leitura e escrita nos arquivos
void le_arquivo(BigInt *);
void escreve_arquivo(BigInt *);

int main(int argc, char const *argv[]) {
  BigInt vet[MAX];
  time_t t;
  double time;

  // Leitura do arquivo
  le_arquivo(vet);

  // Marcação de tempo durante a execução do sort
  t = clock();
  quickSort(vet, 0, MAX - 1);
  t = clock() - t;

  // Transforma o tempo em segundos
  time = (double)t / CLOCKS_PER_SEC;

  // Escrita no arquivo de output
  escreve_arquivo(vet);

  // Printa o tempo de execução
  printf("%lf\n", time);

  return 0;
}

void quickSort(BigInt *arr, int lo, int hi) {
  int pi;

  // Realiza o particionamento do vetor em vetores
  // menores de modo recursivo
  if (lo < hi) {
    pi = partition(arr, lo, hi);

    quickSort(arr, lo, pi - 1);
    quickSort(arr, pi + 1, hi);
  }
}

void troca(BigInt *a, BigInt *b) {
  BigInt aux;

  // Função de troca, movendo os dois campos da struct
  aux.high = (*a).high;
  aux.low = (*a).low;

  (*a).high = (*b).high;
  (*a).low = (*b).low;

  (*b).high = aux.high;
  (*b).low = aux.low;
  return;
}

int partition(BigInt *arr, int lo, int hi) {
  // Utiliza o pivo como o último elemento do vetor
  BigInt pivot = arr[hi];
  int i = (lo - 1);

  // Faz a troca dos elementos com base no valor do pivo
  // ordenando em um vetor maior e outro menor que o pivo
  // para a próxima chamada recursiva
  for (int j = lo; j <= hi - 1; j++) {
    if (arr[j].high < pivot.high) {
      i++;
      troca(&arr[i], &arr[j]);
      // Casos o high seja igual, ele desempata pelo low
    } else if (arr[j].high == pivot.high) {
      if (arr[j].low < pivot.low) {
        i++;
        troca(&arr[i], &arr[j]);
      }
    }
  }
  troca(&arr[i + 1], &arr[hi]);
  return (i + 1);
}

void le_arquivo(BigInt *vet) {
  FILE *fp;
  BigInt big;

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

void escreve_arquivo(BigInt *vet) {
  FILE *fp;

  fp = fopen("quick.dat", "w");

  // Escreve no arquivo de output com a parte low
  // positiva como ela estava no arquivo original
  for (int i = 0; i < MAX; i++) {
    if (vet[i].low < 0)
      vet[i].low = -1 * vet[i].low;
    fprintf(fp, "%d %d\n", vet[i].high, vet[i].low);
  }

  fclose(fp);
}
