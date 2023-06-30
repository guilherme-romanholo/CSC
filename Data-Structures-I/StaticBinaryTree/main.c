#include "tree.h"
#include <stdio.h>
#define tam 50

int main(int argc, char *argv[]) {
  tree arvore[tam];

  initializeTree(arvore, tam);

  createRoot(arvore, 20);

  insert(arvore, 10);
  insert(arvore, 15);
  insert(arvore, 32);
  insert(arvore, 3);
  insert(arvore, 35);
  insert(arvore, 28);

  printf("Árvore 2D:\n");
  callPrintTree2D(arvore);

  printf("\nPré ordem:\n");
  callPreOrder(arvore);

  printf("\nPós ordem:\n");
  callPosOrder(arvore);

  printf("\nIn ordem:\n");
  callInOrder(arvore);

  printf("\nNúmero de elementos: %d\n",callNumberOfNodes(arvore));

  printf("Altura: %d\n",callHeight(arvore));

  printf("Balanceada: ");
  callBalanced(arvore) ? printf("Sim\n") : printf("Não\n");

  printf("Perfeitamente balanceada: ");
  callPerfectlyBalanced(arvore) ? printf("Sim\n") : printf("Não\n");

  printf("Tamanho máximo alocado: %d\n",getMaxSize());

  return 0;
}
