#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  unsigned int N, aux;
  std::vector<unsigned int> par, impar;

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> aux;
    if (aux % 2)
      impar.push_back(aux);
    else
      par.push_back(aux);
  }

  std::sort(par.begin(), par.end());
  std::sort(impar.begin(), impar.end(), std::greater<unsigned int>());

  for (auto var : par) {
    std::cout << var << std::endl;
  }
  for (auto var : impar) {
    std::cout << var << std::endl;
  }

  return 0;
}
