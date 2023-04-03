#include <cmath>
#include <iostream>

int hexadecimal(char hex, int aux) {
  switch (hex) {
  case 'A':
    return 10 * std::pow(16, aux);
  case 'B':
    return 11 * std::pow(16, aux);
  case 'C':
    return 12 * std::pow(16, aux);
  case 'D':
    return 13 * std::pow(16, aux);
  case 'E':
    return 14 * std::pow(16, aux);
  case 'F':
    return 15 * std::pow(16, aux);
  default:
    return (hex - '0') * std::pow(16, aux);
  }
}

int main(int argc, char *argv[]) {
  std::string hex;
  int num = 0, aux;

  std::cout << "Digite um número hexadecimal: " << std::endl;
  std::cin >> hex;

  aux = hex.size() - 1;
  for (int i = 0; i < hex.size(); i++) {
    num += hexadecimal(hex[i], aux);
    aux--;
  }

  std::cout << "Número convertido em decimal: " << num << std::endl;

  return 0;
}
