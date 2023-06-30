#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  lista *list;
  tipo_elem x;
  int opc, pos;
  tipo_chave key;

  list = malloc(sizeof(lista));
  Definir(list);

  do {
    printf("------Bem vindo ao cadastro de alunos------\n");
    printf("(1) Cadastrar Aluno\n(2) Remover Aluno\n(3) Buscar Aluno\n(4) "
           "Imprimir Turma\n(5) Excluir turma\n(6)Quantidade de "
           "alunos\n(0)Sair\n");
    scanf("%d", &opc);
    switch (opc) {
    case 0:
      break;
    case 1:
      Cria_elem(&x);
      Inserir_ord(x, list);
      break;
    case 2:
      Imprimir(list);
      printf("Digite a chave do aluno:\n");
      scanf("%d", &key);
      Remover_ch(key, list) ? printf("Removido com sucesso!\n")
                            : printf("Aluno não encontrado!\n");
      break;
    case 3:
      printf("Digite a chave do aluno:\n");
      scanf("%d", &key);
      Busca_bin(key,list, &pos) ? printf("Aluno encontrado!\n") : printf("Aluno não encontrado!\n");
      x = list->A[pos];
      Impr_elem(x);
      break;
    case 4:
      Imprimir(list);
      break;
    case 5:
      Apagar(list);
      printf("Turma excluída com sucesso!\n");
      break;
    case 6:
      printf("A turma tem %d alunos.\n", Tamanho(list));
    }
  } while (opc != 0);

  return 0;
}
