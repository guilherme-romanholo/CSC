#include <iostream>

int cont;

int fibonacci(int num) {
  cont++;
  if (num == 0)
    return 0;
  else if (num == 1)
    return 1;
  else
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main(int argc, char *argv[]) {
  int N, num, i, fibo;

  std::cin >> N;

  for (i = 0; i < N; i++) {
    std::cin >> num;
    cont = 0;
    fibo = fibonacci(num);
    std::cout << "fib(" << num << ") = " << cont - 1 << " calls = " << fibo
              << std::endl;
  }

  return 0;
}
