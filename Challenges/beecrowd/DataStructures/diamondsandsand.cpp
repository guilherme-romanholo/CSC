#include <iostream>
#include <stack>

void analisa(std::string str) {
  std::stack<char> pilha;
  int i, cont = 0;

  for (i = 0; i < str.size(); i++) {
    if (str[i] == '<') {
      pilha.push('<');
    }
    if (str[i] == '>' && !pilha.empty()) {
      pilha.pop();
      cont++;
    }
  }
  std::cout << cont << std::endl;
}

int main(int argc, char *argv[]) {
  int N, i;
  std::string *str;

  std::cin >> N;
  str = new std::string[N];

  for (i = 0; i < N; i++) {
    std::cin >> str[i];
  }

  for (i = 0; i < N; i++) {
    analisa(str[i]);
  }

  return 0;
}
