#include <stdio.h>
#include <stdlib.h>

// Estrutura para os elementos da lista
typedef struct list {
  int id;
  int k;
  int o;
  struct list *prox;
} t_list;

int flag = 0;

t_list *alocar(int, int, int);    // Função para alocar um elemento
void insere(t_list **, t_list *); // Função de inserção na lista
void busca(t_list **, int *, t_list **,
           t_list **); // Busca do elemento na lista
void deleta(t_list **, t_list **, t_list **,
            t_list **); // Deleção de um elemento na lista

int main(int argc, char *argv[]) {
  // Declaração das variáveis utilizadas
  int num_elemt, i, aux_k, aux_o, k;
  t_list *head, *new, *rem, *cur;
  // head = cabeça da lista
  // new = novo elemento para ser inserido
  // rem = último elemento removido
  // cur = elemento atual em análise

  head = new = rem = cur = NULL;

  // Recebe o número de elementos da lista
  scanf("%d", &num_elemt);

  // Laço de repetição para o cadastro dos elementos na lista
  for (i = 0; i < num_elemt; i++) {
    scanf("%d %d", &aux_k, &aux_o);
    new = alocar(i + 1, aux_k, aux_o);
    insere(&head, new);
  }

  // Caso inicial, começamos na cabeça da lista
  cur = head;
  k = cur->k;

  // Busca os elementos em quanto existir mais de um elemento na lista
  while (cur != cur->prox) {
    busca(&cur, &k, &rem, &head);
  }

  // Printa o elemento final
  printf("%d\n", cur->id);

  return 0;
}

void busca(t_list **cur, int *k, t_list **rem, t_list **h) {
  int i;
  t_list *antes;

  antes = *cur;

  // Percorre a lista por K elementos
  for (i = 0; i < *k - 1; i++) {
    antes = *cur;
    *cur = (*cur)->prox;
  }

  // Salvamos o valor do próximo K
  *k = (*cur)->k;

  if ((*cur)->o == 0) {
    // Caso o último removido não seja nulo, liberamos ele
    if (*rem)
      free(*rem);
    // Deletamos o elemento atual
    deleta(cur, &antes, rem, h);
  } else {
    // Reinserimos o último removido
    insere(h, *rem);
    if (flag == 1) {
      *h = *rem;
      flag = 0;
    }
    // Deletamos o elemento atual
    deleta(cur, &antes, rem, h);
  }
  return;
}

void deleta(t_list **cur, t_list **antes, t_list **rem, t_list **h) {
  // Caso o removido seja a cabeça, passamos a cabeça para o próximo elemento
  // para não perde-lá
  if (*cur == *h){
    *h = (*h)->prox;
    flag = 1;
  } else {
    flag = 0;
  }
  // Salvamos o elemento removido na variável auxiliar do último removido
  *rem = *cur;
  // Ligamos lista retirando o elemento
  (*antes)->prox = (*cur)->prox;
  // Passamos o atual para o próximo elemento
  (*cur) = (*cur)->prox;
  // Fazemos o removido apontar para NULL e sua opção vira 0 como especificado
  (*rem)->prox = NULL;
  (*rem)->o = 0;
  return;
}

t_list *alocar(int id, int k, int o) {
  // Alocamos um elemento
  t_list *aux = malloc(sizeof(t_list));

  // Atribuímos os valores para o elemento alocado
  aux->id = id;
  aux->k = k;
  aux->o = o;
  aux->prox = NULL;

  return aux;
}

void insere(t_list **h, t_list *new) {
  t_list *atual, *antes;

  antes = atual = *h;

  // Caso tentarmos inserir NULL ele termina a função
  if (new == NULL)
    return;

  // Caso a lista esteja vazia
  if (!(*h)) {
    *h = new;
    new->prox = new;
    return;
  }

  // Caso exista apenas um elemento na lista
  if ((*h)->prox == *h) {
    new->prox = atual;
    atual->prox = new;
    if (new->id < atual->id)
      *h = new;
    return;
  }

  // Percorremos a lista até achar a posição desejada para inserir o elemento
  while (antes->prox != *h && new->id > atual->id) {
    antes = atual;
    atual = atual->prox;
  }

  // Verificamos se é a posição da cabeça para relizarmos a inserção sem
  // perde-lá
  if (atual == *h && new->id < atual->id) {
    antes = atual->prox;
    while (antes->prox != atual)
      antes = antes->prox;
    antes->prox = new;
    new->prox = *h;
    *h = new;
    return;
  }

  // Caso padrão, inserimos entre o atual e o anterior
  new->prox = atual;
  antes->prox = new;
  return;
}
