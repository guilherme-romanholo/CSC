#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numAviao = 0;

typedef struct queue {
  int id;
  char cor[20];
  struct queue *prox;
} t_queue;

void push(t_queue **f, t_queue **b, int id, char *cor) {
  t_queue *aux = malloc(sizeof(t_queue));
  aux->id = id;
  strcpy(aux->cor, cor);
  aux->prox = NULL;
  numAviao++;

  if (*f == NULL) {
    *f = *b = aux;
    return;
  }
  (*b)->prox = aux;
  *b = aux;
}

void pop(t_queue **f, t_queue **b) {
  t_queue *aux = *f;
  if (*f == NULL) {
    puts("Fila vazia!");
    return;
  }
  if (*f == *b) {
    *f = *b = NULL;
    return;
  } else {
    *f = (*f)->prox;
  }
  printf("Decolagem do avião %d autorizada!\n", aux->id);
  free(aux);
  numAviao--;
}

void printQueue(t_queue *f, t_queue *b) {
  t_queue *aux = f;
  if (f == NULL) {
    puts("Fila vazia!");
    return;
  }
  puts("Os aviões estão na fila na seguinte ordem:");
  while (aux != NULL) {
    printf("%d ", aux->id);
    aux = aux->prox;
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  t_queue *front, *back;
  int opc, id;
  char cor[20];

  front = back = NULL;

  do {
    puts("(1)Aviões aguardando na fila\n(2)Autorizar decolagem do primeiro "
         "avião\n(3)Adicionar avião a fila\n(4)Listar os aviões na "
         "fila\n(5)Características do primeiro avião\n(0)Sair");
    scanf("%d", &opc);

    switch (opc) {
    case 1:
      printf("Aviões aguardando: %d\n", numAviao);
      break;
    case 2:
      pop(&front, &back);
      break;
    case 3:
      puts("Digite o id do avião:");
      scanf("%d", &id);
      puts("Digite a cor do avião:");
      scanf(" %s", cor);
      push(&front, &back, id, cor);
      break;
    case 4:
      printQueue(front, back);
      break;
    case 5:
      if (front == NULL) {
        puts("Fila vazia!");
      } else {
        printf("Características do primeiro avião:\nID = %d\nCor = %s\n",
               front->id, front->cor);
      }
      break;
    default:
      break;
    }

  } while (opc != 0);

  return 0;
}
