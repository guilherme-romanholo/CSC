#include <stdio.h>
#include <stdlib.h>

// Struct para nossos elementos da fila
typedef struct queue {
  int id;      // Identificação
  int arrival; // Tempo de chagada na fila
  int burn;    // Tempo que leva para ser atendido
  struct queue *next;
} queue_t;

// Struct para os caixas que irão realizar o atendimento
typedef struct cashier {
  int id;        // Identificação
  int arrival;   // Tempo que a pessoa chega no caixa
  int time;      // Tempo total decorrido no caixa
  queue_t *pers; // Pessoa que está sendo atendida
  struct cashier *next;
} cashier_t;

void insert_arrival(queue_t **, queue_t *);
void push_cashier(cashier_t **, cashier_t **, cashier_t *);
queue_t *pop_queue(queue_t **);
cashier_t *pop_cashier(cashier_t **, cashier_t **);
void search_remove(cashier_t **, cashier_t **, cashier_t **, cashier_t **, int);
queue_t *alloc_queue(int, int, int);
cashier_t *alloc_cashier(int);
void print_times(cashier_t *, int);

int main(int argc, char *argv[]) {
  int id, arrival, burn, time, num_elem, num_cashier, i;
  queue_t *new_queue, *input_queue;
  cashier_t *free_cashier_head, *free_cashier_tail, *work_cashier_head, *work_cashier_tail, *new_cashier;
  // input_queue = fila principal ordenada em relação ao tempo de chegada
  // free_cashier = fila de caixas que estão livres para o atendimento
  // work_cashier = fila de caixas que estão atendendo um elemento
  // work_cashier e free_cashier possuem head e tail

  free_cashier_head = free_cashier_tail = work_cashier_head = work_cashier_tail = NULL;
  input_queue = NULL;

  scanf("%d %d", &num_elem, &num_cashier);

  // Entrada dos inputs na fila ordenada pelo tempo de chegada
  for (i = 0; i < num_elem; i++) {
    scanf("%d %d %d", &id, &arrival, &burn);
    new_queue = alloc_queue(id, arrival, burn);
    insert_arrival(&input_queue, new_queue);
  }

  // Criação dos caixas para o atendimento
  for (i = 1; i <= num_cashier; i++) {
    new_cashier = alloc_cashier(i);
    push_cashier(&free_cashier_head, &free_cashier_tail, new_cashier);
  }

  // Começamos o atendimento no tempo 0
  time = 0;

  // Loop executado enquanto temos elementos na fila de entrada
  // ou quando algum caixa ainda está atendendo um elemento
  while (input_queue || work_cashier_head) {

    // Verificamos se alguém ja foi atendido para tirar o caixa do estado
    // de trabalho e colocá-lo na fila de caixa livre
    search_remove(&work_cashier_head, &work_cashier_tail, &free_cashier_head, &free_cashier_tail, time);

    // Verificamos se a fila ainda tem elementos para serem atendidos, se algum
    // elemento bateu o tempo para ser atendido e se possuimos algum caixa livre
    while (input_queue != NULL && time >= input_queue->arrival && free_cashier_head != NULL) {
      // Retiramos o elementos da fila de input
      new_queue = pop_queue(&input_queue);
      new_queue->next = NULL;
      // Atribuímos ele ao primeiro caixa livre
      free_cashier_head->pers = new_queue;
      // Retiramos o caixa da fila de caixas livres e marcamos o tempo
      // que começa o atendimento
      new_cashier = pop_cashier(&free_cashier_head, &free_cashier_tail);
      new_cashier->arrival = time;
      new_cashier->next = NULL;
      // Colocamos o caixa na fila de caixas trabalhando
      push_cashier(&work_cashier_head, &work_cashier_tail, new_cashier);
    }

    // Contamos mais um tempo
    time++;
  }

  // Printamos a resposta
  print_times(free_cashier_head, num_cashier);

  // Liberamos a memória usada pelos caixas
  while (free_cashier_head != NULL) {
    new_cashier = free_cashier_head;
    free_cashier_head = free_cashier_head->next;
    free(new_cashier);
  }

  return 0;
}

// Função de busca e remoção quando é terminado o atendimento de um caixa
// que está trabalhando e reinserção dele na fila de caixas livres
void search_remove(cashier_t **work_head, cashier_t **work_tail, cashier_t **free_head, cashier_t **free_tail, int time) {
  cashier_t *aux = *work_head, *prev;

  // Verificamos se o caixa que terminou o atendimento é a cabeça
  if (aux != NULL && time - aux->arrival == (aux->pers)->burn) {
    // Passamos a cabeça da fila dos caixas trabalhando para o próximo
    *work_head = aux->next;
    // Liberamos o elemento já atendido e contamos o
    // tempo em que o caixa finalizou o atendimento
    free(aux->pers);
    aux->pers = NULL;
    aux->time = time;
    aux->next = NULL;
    // Colocamos esse caixa na fila de caixas livres
    push_cashier(free_head, free_tail, aux);
    return;
  }

  // Procura na fila de caixas trabalhando se algum já terminou o antendimento
  while (aux != NULL && time - aux->arrival != (aux->pers)->burn) {
    prev = aux;
    aux = aux->next;
  }

  // Caso nenhum tenha acabado o atendimento finalizamos a função
  if (aux == NULL)
    return;

  // Caso algum caixa tenha acabado retiramos ele da fila
  prev->next = aux->next;

  // Caso ele seja a cauda, atualizamos a cauda
  if (aux == *work_tail)
    *work_tail = prev;

  // Liberamos o elemento já atendido e contamos o
  // tempo em que o caixa finalizou o atendimento
  free(aux->pers);
  aux->pers = NULL;
  aux->time = time;
  aux->next = NULL;
  // Colocamos esse caixa na fila de caixas livres
  push_cashier(free_head, free_tail, aux);
}

// Retira o primeiro da fila para ser atendido
queue_t *pop_queue(queue_t **head) {
  queue_t *aux;
  if (*head == NULL)
    return NULL;
  aux = *head;
  *head = (*head)->next;
  return aux;
}

// Retira um caixa do começo da fila de caixas
cashier_t *pop_cashier(cashier_t **head, cashier_t **tail) {
  cashier_t *aux;
  if (*head == NULL)
    return NULL;
  aux = *head;
  if (*head != *tail)
    *head = (*head)->next;
  else
    *head = *tail = NULL;
  return aux;
}

// Coloca um caixa no fim da fila de caixas
void push_cashier(cashier_t **head, cashier_t **tail, cashier_t *new) {
  // Fila vazia
  if (*head == NULL) {
    *head = *tail = new;
    return;
  }
  // Fila não esteja vazia
  (*tail)->next = new;
  *tail = new;
  return;
}

// Imprime o tempo total dos caixas de forma ordenada
void print_times(cashier_t *head, int num_cashier) {
  cashier_t *tmp = head;
  int i;
  for (i = 1; i <= num_cashier; i++) {
    while (tmp != NULL && tmp->id != i)
      tmp = tmp->next;
    printf("%d ", tmp->time);
    tmp = head;
  }
  printf("\n");
}

// Alocação e inicialização de um caixa
cashier_t *alloc_cashier(int id) {
  cashier_t *new;
  new = malloc(sizeof(cashier_t));
  new->id = id;
  new->arrival = 0;
  new->time = 0;
  new->pers = NULL;
  new->next = NULL;
  return new;
}

// Alocação e inicialização de um elemento na fila
queue_t *alloc_queue(int id, int arrival, int burn) {
  queue_t *new = malloc(sizeof(queue_t));
  new->id = id;
  new->arrival = arrival;
  new->burn = burn;
  new->next = NULL;
  return new;
}

// Função para inserção ordenada dos inputs na fila principal
// com base no tempo de chegada
void insert_arrival(queue_t **h, queue_t *new) {
  queue_t *aux, *antes;

  // Caso a fila esteja vazia
  if (*h == NULL) {
    *h = new;
    return;
  }

  aux = antes = *h;

  // Procuramos o local de inserção do novo elemento com base
  // no seu tempo de chegada
  while (aux->next && new->arrival >= (aux->next)->arrival) {
    antes = aux;
    aux = aux->next;
  }

  // Casos ele seja inserido na posição da cabeça
  if (aux == *h) {
    if (new->arrival > aux->arrival) {
      // Inserção depois da cabeça
      new->next = (*h)->next;
      (*h)->next = new;
    } else if (new->arrival < aux->arrival) {
      // Inserção no lugar da cabeça
      new->next = *h;
      *h = new;
    } else {
      // Mesmo tempo, fazemos o desempate com o ID
      if (new->id < aux->id) {
        new->next = *h;
        *h = new;
      } else {
        new->next = (*h)->next;
        (*h)->next = new;
      }
    }
    return;
  }

  // Caso ele não seja inserido na posição da cabeça
  if (new->arrival > aux->arrival) {
    // Inserção antes do aux
    new->next = aux->next;
    aux->next = new;
  } else if (new->arrival < aux->arrival) {
    // Inserção depois do aux
    new->next = aux;
    antes->next = new;
  } else {
    // Mesmo tempo, fazemos o desempate com o ID
    if (new->id < aux->id) {
      new->next = aux;
      antes->next = new;
    } else {
      new->next = aux->next;
      aux->next = new;
    }
  }
  return;
}
