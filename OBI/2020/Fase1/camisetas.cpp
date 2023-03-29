#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
  int i, n, *t, m[2], aux;

  std::cin >> n;

  t = new int[n];                // Alocamos o vetor de N posições
  memset(t, 0, n * sizeof(int)); // Zeramos esse vetor

  for (i = 0; i < n; i++) {
    std::cin >> aux;
    if (aux == 1)
      t[0]++; // Caso o tamanho seja 1 contamos +1 na posição 0
    else
      t[1]++; // Caso o tamanho seja 2 contamos +1 na posição 1
  }

  std::cin >> m[0] >> m[1];

  if (t[0] < m[0] || t[1] < m[1])  // Verifica se o número de camisetas
    std::cout << "N" << std::endl; // disponíveis é o suficiente
  else
    std::cout << "S" << std::endl;

  return 0;
}
