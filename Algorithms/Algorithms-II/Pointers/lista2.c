#include <stdio.h>

struct lista {
  int valor;
  struct lista *proximo;
};

struct lista *procurarValor(
    struct lista *pLista,
    int valor) // a função retorna um endereço de memória do tipo struct lista
{
  while (pLista != NULL) {
    if (pLista->valor == valor) {
      return pLista;
    } else {
      pLista = pLista->proximo;
    }
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  struct lista m1, m2, m3;
  struct lista *resultado, *gancho = &m1;
  int valor;

  m1.valor = 5;
  m2.valor = 10;
  m3.valor = 15;

  m1.proximo = &m2;
  m2.proximo = &m3;
  m3.proximo = NULL;

  printf("Digite o valor da pesquisa:\n");
  scanf("%d", &valor);

  resultado = procurarValor(gancho, valor);

  if (resultado == NULL) {
    printf("Valor não encontrado!\n");
  } else {
    printf("Valor %d encontrado!\n", resultado->valor);
  }

  return 0;
}
