#include <iostream>
#include <stack>

int main(int argc, char *argv[]) {
  int N, i, num, soma = 0;
  std::stack<int> pilha;

  std::cin >> N; // entrada do valor N

  for (i = 0; i < N; i++) {
    std::cin >> num; // entrada dos números
    if (num) {       // caso num não seja zero adicionamos ele na pilha
      pilha.push(num);
    } else { // caso ele seja zero retiramos o último elemento
      pilha.pop();
    }
  }

  while (pilha.size()) { // fazemos a soma dos elementos que restaram
    soma += pilha.top();
    pilha.pop();
  }

  std::cout << soma << std::endl;
  return 0;
}
