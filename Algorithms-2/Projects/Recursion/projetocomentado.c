#include <stdio.h>

// Variáveis globais
int num, res[20] = {0}, candidatos[20] = {0}, cont = 0, maior = 0;

// Protótipos de funções
void zera_vet(int *);
void copia_resp(int *);
void verifica_resp(int *);
void busca(int, int *, int); 
int analisa_maior(int *);

int main(int argc, char *argv[]) {
  // Declaração de variáveis
  int atual[20] = {0}, numTeste, numCand, i, j;

  // Entrada de dados (Número de testes e lista de candidatos)
  scanf("%d %d", &numTeste, &numCand);
  for (i = 0; i < numCand; i++) {
    scanf("%d", &candidatos[i]);
  }

  // Entrada e análise dos números escolhidos
  for (i = 0; i < numTeste; i++) {
      scanf("%d", &num);
      busca(0, atual, 0);
      // Output
      printf("%d ", cont);
      for (j = 0; j < 20; j++) {
        if (res[j] != 0) {
          printf("%d ", candidatos[j]);
        }
      }
      printf("\n");
      // Zerando as variáveis e vetores globais para o próximo teste
      cont = 0;
      zera_vet(res);
      zera_vet(atual);
      maior = 0;
  }

  return 0;
}

// Recursão principal
void busca(int ini, int *atual, int soma) {
  // Casos de parada da recursão
  if (soma == num) {
    // Se a soma for igual ao número, achamos uma possível resposta
    cont++; // Contamos ela na variável contadora (número de respostas)
    verifica_resp(atual); // E fazemos sua verificação para ver se é a maior
    return;
  }
  // Se a soma for maior que o número, não temos uma resposta adiante então é um caso de parada
  if (soma > num)
    return;
  // Se a recursão estourar o vetor de candidatos (20 posições) paramos a recursão
  // No caso da soma não chegar ao número
  if (ini >= 20)
    return;

  atual[ini]++; // Marcamos o atual como 1, ou seja, estamos analisando ele 
  busca(ini + 1, atual, soma + candidatos[ini]); // Chamamos a recursão para o nosso próximo candidato, e somamos o candidato anterior
  atual[ini]--; // Desmarcamos o atual, pois ele já foi utilizado para achar uma resposta, ou não achamos nada com ele (atingiu algum caso de parada)
  busca(ini + 1, atual, soma); // Chamamos a recursão para o nosso próximo candidato, mas dessa vez sem o elemento,o qual foi desmarcado anteriormente 
  // OBS: Chamamos ela só com soma, pois nessa recursão ainda não tinha sido adicionado o candidato já utilizado anteriormente na soma
}

void verifica_resp(int *atual) {
  int qtd = 0, maior1 = 0, maior2 = 0;

  // Conta em quantos candidatos o número foi decomposto
  for (int i = 0; i < 20; i++) {
    if (atual[i] != 0) {
      qtd++;
    }
  }

  // Verifica se ele foi decomposto em mais números do que o maior já análisado
  if (qtd > maior) {
    maior = qtd;
    copia_resp(atual); // Caso seja, copiamos o atual para o vetor de resposta
  } else if (qtd == maior) {
    // Se eles forem iguais analisamos qual o maior elemento do atual e qual o maior elemento do vetor resposta
    maior1 = analisa_maior(atual);
    maior2 = analisa_maior(res);
    if (maior1 > maior2) {
      // Caso o vetor atual tenha um número maior que o vetor de respostas, copiamos o atual para o vetor de resposta
      copia_resp(atual);
    }
  }
}

// Função utilizada para achar o maior número de um vetor
int analisa_maior(int *vet) {
  int test = 0;
  for (int i = 0; i < 20; i++) {
    if (vet[i] != 0 && i > test) {
      test = i;
    }
  }
  return test;
}

// Função utilizada para zerar um vetor
void zera_vet(int *vet) {
  int i;
  for (i = 0; i < 20; i++) {
    vet[i] = 0;
  }
}

// Função utlizada para copiar o vetor atual no vetor de respostas
void copia_resp(int *atual) {
  int i;
  zera_vet(res);
  for (i = 0; i < 20; i++) {
    res[i] = atual[i];
  }
}
