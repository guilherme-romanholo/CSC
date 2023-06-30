#include <iostream>
#include <list>

int main(int argc, char *argv[]) {
  int n, i, cont = 0, aux;
  std::list<int> lista;
  std::cin >> n;

  for (i = 0; i < n; i++) {
    std::cin >> aux;
    lista.push_back(aux);
  }

  while (lista.size()) { // enquanto existem elementos na lista
    aux = 0;
    if (lista.front() == lista.back()) {
      // se eles forem iguais remove os dois
      lista.pop_back();
      if (!lista.size()) { // evitar segmentation fault
        break;
      }
      lista.pop_front();
    } else if (lista.front() < lista.back()) {
      // se o da frente é menor, somamos com seu adjacente e excluimos os outros
      // dois
      aux = lista.front();
      lista.pop_front();
      aux += lista.front();
      lista.pop_front();
      lista.push_front(aux);
      cont++;
    } else if (lista.front() > lista.back()) {
      // se o de trás é menor, somamos com seu adjacente e excluimos os outros
      // dois
      aux = lista.back();
      lista.pop_back();
      aux += lista.back();
      lista.pop_back();
      lista.push_back(aux);
      cont++;
    }
  }
  // a varíavel contadora é incrementada por cada operação realizada
  std::cout << cont << std::endl;

  return 0;
}
