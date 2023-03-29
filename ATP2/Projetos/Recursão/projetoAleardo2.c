#include <stdio.h>

int num, res[20] = {0}, candidatos[20] = {0}, cont = 0, maior = 0;

void zera_vet(int *);
void copia_resp(int *);
void verifica_resp(int *);
void busca(int, int *, int);
int analisa_maior(int *);

int main(int argc, char *argv[]) {
  int atual[20] = {0}, numTeste, numCand, i, j, resposta[100][21];

  scanf("%d %d", &numTeste, &numCand);
  for (i = 0; i < numCand; i++) {
    scanf("%d", &candidatos[i]);
  }

  for (i = 0; i < numTeste; i++) {
    scanf("%d", &num);
    if (num == 0) {
      printf("0\n");
    } else {
      busca(0, atual, 0);
      printf("%d ", cont);
      for (j = 0; j < 20; j++) {
        if (res[j] != 0) {
          printf("%d ", candidatos[j]);
        }
      }
      printf("\n");
      cont = 0;
      zera_vet(res);
      zera_vet(atual);
      maior = 0;
    }
  }

  return 0;
}

void busca(int ini, int *atual, int soma) {
  if (soma == num) {
    cont++;
    verifica_resp(atual);
    return;
  }
  if (soma > num)
    return;
  if (ini >= 20)
    return;

  atual[ini]++;
  busca(ini + 1, atual, soma + candidatos[ini]);
  atual[ini]--;
  busca(ini + 1, atual, soma);
}

void verifica_resp(int *atual) {
  int qtd = 0, maior1 = 0, maior2 = 0;
  for (int i = 0; i < 20; i++) {
    if (atual[i] != 0) {
      qtd++;
    }
  }
  if (qtd > maior) {
    maior = qtd;
    copia_resp(atual);
  } else if (qtd == maior) {
    maior1 = analisa_maior(atual);
    maior2 = analisa_maior(res);
    if (maior1 > maior2) {
      copia_resp(atual);
    }
  }
}

int analisa_maior(int *vet) {
  int test = 0;
  for (int i = 0; i < 20; i++) {
    if (vet[i] != 0 && i > test) {
      test = i;
    }
  }
  return test;
}

void zera_vet(int *vet) {
  int i;
  for (i = 0; i < 20; i++) {
    vet[i] = 0;
  }
}

void copia_resp(int *atual) {
  int i;
  zera_vet(res);
  for (i = 0; i < 20; i++) {
    res[i] = atual[i];
  }
}
