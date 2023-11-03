#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define tam_fila 100

// ED para fila
//------------------------------------------------------
typedef struct {
  int A[tam_fila];
  int inicio, fim;
} fila;
//------------------------------------------------------

// Operações da fila
//------------------------------------------------------
// Cria uma fila vazia
void Definir(fila *q) {
  q->fim = 0;
  q->inicio = 0;
}

// Retorna true se fila não contém elementos, false caso contrário
bool Vazia(fila *q) {
  if (q->inicio == q->fim)
    return true;
  return false;
}

// Retorna true se fila cheia, false caso contrário
bool Cheia(fila *q) {
  if (q->inicio == ((q->fim + 1) % tam_fila))
    return true;
  return false;
}

// Adiciona um elemento no fim da fila q (retorna true se sucesso, false c.c.)
bool Inserir(fila *q, int elem) {
  if (Cheia(q))
    return false;
  q->fim = (q->fim + 1) % tam_fila;
  q->A[q->fim] = elem;
  return true;
}

// Remove um elemento do início da fila q (retorna true se sucesso, false c.c.)
bool Remover(fila *q, int *elem) {
  if (Vazia(q))
    return false;
  q->inicio = (q->inicio + 1) % tam_fila;
  *elem = q->A[q->inicio];
  return true;
}
//------------------------------------------------------

// Funções adicionadas para o exercício
//------------------------------------------------------
// Alocação da matriz
int **AlocarMatriz(int tam) {
  int **matriz = calloc(tam, sizeof(int *));

  for (int i = 0; i < tam; i++)
    matriz[i] = calloc(tam, sizeof(int));

  return matriz;
}

// Liberar matriz da memória
void FreeMatriz(int **matriz, int tam) {
  for (int i = 0; i < tam; i++)
    free(matriz[i]);

  free(matriz);
}

// Printar a matriz 
void PrintaMatriz(int **matriz, int tam) {
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

// Operação de leitura do arquivo
int **LerArquivo(const char *arquivo) {
  FILE *fp = fopen(arquivo, "r");
  int tam, ori, dest, peso, **matriz;

  fscanf(fp, "%d", &tam);

  matriz = AlocarMatriz(tam);

  while (fscanf(fp, "%d %d %d", &ori, &dest, &peso) != EOF)
    matriz[ori][dest] = peso;

  fclose(fp);

  return matriz;
}

// Função para ler o tamanho da matriz no arquivo
int LerTamanho(const char *arquivo) {
  FILE *fp = fopen(arquivo, "r");
  int tam;

  fscanf(fp, "%d", &tam);

  fclose(fp);

  return tam;
}
//------------------------------------------------------

//------------------------------------------------------
// Principal
int main() {
  int **A, *dist, N;
  int i, j, c = 0;
  fila F;

  A = LerArquivo("digrafo.txt");
  N = LerTamanho("digrafo.txt");

  dist = calloc(N, sizeof(int));

  for (j = 0; j < N; j++)
    dist[j] = INT_MAX;

  dist[c] = 0;
  Definir(&F);
  Inserir(&F, c);

  // Enquanto existirem elementos na fila
  while (!Vazia(&F)) {
    // Remove o primeiro elemento da fila
    Remover(&F, &i);
    // Verifica o elemento removido com os demais elementos
    for (j = 0; j < N; j++)
      // Se tiver ligação entre os vértices e a nova
      // distância é menor do que a distância atual
      if (A[i][j] != 0 && dist[j] >= dist[i] + A[i][j]) {
        // Troca as distâncias
        dist[j] = dist[i] + A[i][j];
        // Insere novamente o vétice na fila
        Inserir(&F, j);
      }
  }

  PrintaMatriz(A, N);

  printf("\n");

  for (i = 0; i < N; i++)
    printf("dist[%d]: %d\n", i, dist[i]);

  free(dist);
  FreeMatriz(A, N);
}
