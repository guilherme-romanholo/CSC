#include <iostream>

int main(int argc, char *argv[]) {
  int t, v;

  while (std::cin >> t >> v) {
    std::cout << 2 * t * v << std::endl;
  }
  return 0;
}
