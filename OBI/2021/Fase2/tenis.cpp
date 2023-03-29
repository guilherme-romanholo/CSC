#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  int vet[4], i;
  // entrada
  for (i = 0; i < 4; i++) {
    std::cin >> vet[i];
  }
  // operação (A+D) - (B+C) com valor absoluto
  std::cout << abs((vet[0] + vet[3]) - (vet[1] + vet[2])) << std::endl;

  return 0;
}
