#include <iostream>

void contador(std::string led) {
  int i, cont = 0, vet[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  for (i = 0; i < led.size(); i++) {
    cont += vet[led[i] - '0'];
  }
  std::cout << cont << " leds" << std::endl;
}

int main(int argc, char *argv[]) {
  int N, i;
  std::string led;

  std::cin >> N;

  for (i = 0; i < N; i++) {
    std::cin >> led;
    contador(led);
  }
  return 0;
}
