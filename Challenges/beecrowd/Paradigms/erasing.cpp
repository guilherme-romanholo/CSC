#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

void analisa(int N, int D, int tam) {
  int resp;
  std::vector<int> vet, aux;
  std::vector<int>::iterator invalid;

  while (N) {
    aux.push_back(N % 10);
    N = N / 10;
  }
  std::reverse(aux.begin(), aux.end());

  vet = aux;
  std::cout << std::endl;
  std::sort(aux.begin(), aux.end(), std::greater<int>());

  for (int i = 0; i < D; i++) {
    for (int j = 0; j < vet.size(); j++) {
      if (vet.at(j) == aux.back()) {
        invalid = vet.begin();
        std::advance(invalid, j);
        vet.erase(--invalid);
        aux.pop_back();
        break;
      }
    }
  }

  for (auto var : vet) {
    std::cout << var;
  }
}

int main(int argc, char *argv[]) {
  int N = 1, D = 1, num;
  while (N != 0 && D != 0) {
    std::cin >> N >> D;
    std::cin >> num;
    analisa(num, D, N - D);
  }
  return 0;
}
