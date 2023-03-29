#include <iostream>

int main(int argc, char *argv[]) {
  int a, b, aux;
  std::cin >> a >> b;
  if (a < 0) {
    aux = (a / b - a % b);
    std::cout << aux << " " << a - aux * b << std::endl;
  } else {
    std::cout << a / b << " " << a % b << std::endl;
  }
  return 0;
}
