#include <iostream>
#include <vector>

int verifica(std::vector<int> vet, int tam) {
  int i, j;

  for (i = 0, j = tam - 1; i <= tam / 2; i++, j--) {
    if (vet[i] != vet[j]) {
      return i + 1;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int n, i, cont = 0, aux;
  std::vector<int> vet;
  std::cin >> n;

  for (i = 0; i < n; i++) {
    std::cin >> aux;
    vet.push_back(aux);
  }

  i = verifica(vet, n);
  while (i) {
    i--;
    if (vet[i] >= vet[n - i - 1]) {
      vet[n - i - 1] += vet[n - i - 2];
      vet.erase(vet.end() - i - 2);
    } else {
      vet[i] += vet[i + 1];
      vet.erase(vet.begin() + i + 1);
    }
    n--;
    cont++;
    i = verifica(vet, n);
  }

  std::cout << cont << std::endl;

  return 0;
}
