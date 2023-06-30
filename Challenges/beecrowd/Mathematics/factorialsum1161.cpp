#include <iomanip>
#include <iostream>

void fatorial(int n1, int n2) {
  long double fat1 = 1, fat2 = 1, sum;
  int i;
  for (i = n1; i > 1; i--) {
    fat1 *= i;
  }
  for (i = n2; i > 1; i--) {
    fat2 *= i;
  }
  sum = fat1 + fat2;
  std::cout << std::setprecision(0) << std::fixed;
  std::cout << sum << std::endl;
}

int main(int argc, char *argv[]) {
  int n1, n2;

  while (std::cin >> n1 >> n2) {
    fatorial(n1, n2);
  }
  return 0;
}
