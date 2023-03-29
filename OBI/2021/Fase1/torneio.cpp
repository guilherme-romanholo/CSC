#include <iostream>

int main(int argc, char *argv[]) {
  char c;
  int i, cont = 0;

  // usamos o laço para contar o número de vitórias
  for (i = 0; i < 6; i++) {
    std::cin >> c;
    if (c == 'V') {
      cont++;
    }
  }

  // analisamos o grupo com base no número de vitórias
  if (cont == 5 || cont == 6) {
    std::cout << "1" << std::endl;
  } else if (cont == 3 || cont == 4) {
    std::cout << "2" << std::endl;
  } else if (cont == 1 || cont == 2) {
    std::cout << "3" << std::endl;
  } else {
    std::cout << "-1" << std::endl;
  }

  return 0;
}
