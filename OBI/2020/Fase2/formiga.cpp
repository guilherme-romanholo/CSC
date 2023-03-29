#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

int **matriz, cont = 0;
std::vector<int> vet, aux;

int indice(int num) {
  int i;
  for (i = 0; i < vet.size(); i++) {
    if (vet[i] == num) {
      return i;
    }
  }
  return 0;
}

void tent(int orig, int nsal) {
  int i, j, t;
  t = indice(aux.back());
  if (matriz[orig][t] == 1 || matriz[t][orig] == 1) {
    aux.pop_back();
    cont++;
    tent(t, nsal);
  }
  aux.pop_back();
}

int main(int argc, char *argv[]) {
  int nsal, ntun, orig, i, input, input2;

  std::cin >> nsal >> ntun >> orig;

  matriz = new int *[nsal];

  for (i = 0; i < nsal; i++) {
    matriz[i] = new int[nsal];
    std::cin >> input;
    vet.push_back(input);
  }

  aux = vet;
  std::sort(aux.begin(), aux.end());
  memset(matriz, 0, nsal * nsal * sizeof(int));

  for (i = 0; i < ntun; i++) {
    std::cin >> input >> input2;
    matriz[input - 1][input2 - 1] = 1;
    matriz[input2 - 1][input - 1] = 1;
  }

  while (!aux.empty()) {
    std::remove(aux.begin(), aux.end(), orig);
    tent(orig, nsal);
  }

  std::cout << cont << std::endl;
  // for (i = 0; i < nsal; i++) {
  //   for (int j = 0; j < nsal; j++) {
  //     std::cout << matriz[i + j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  return 0;
}
