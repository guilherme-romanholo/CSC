#include <cstdio>
#include <iostream>
#include <list>
#include <queue>

int main(int argc, char *argv[]) {
  int n, k, u, i, j, aux;
  bool flag = false;
  std::list<int> *lista;
  std::queue<int> fila;

  std::cin >> n >> k >> u;

  lista = new std::list<int>[n];

  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      scanf("%d", &aux);
      lista[i].push_back(aux);
    }
  }
  for (i = 0; i < u; i++) {
    scanf("%d", &aux);
    fila.push(aux);
  }

  while (!fila.empty()) {
    aux = fila.front();
    for (i = 0; i < n; i++) {
      lista[i].remove(aux);
      if (lista[i].empty()) {
        std::cout << i + 1 << " ";
        flag = true;
      }
    }
    if (flag)
      break;
    fila.pop();
  }
  std::cout << std::endl;
  return 0;
}
