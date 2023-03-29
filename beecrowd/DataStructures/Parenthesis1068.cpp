#include <iostream>
#include <stack>

int main(int argc, char *argv[]) {
  std::string str;
  std::stack<char> pilha;
  bool flag;

  while (std::cin >> str) {
    flag = true;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(')
        pilha.push('(');
      if (str[i] == ')' && !pilha.empty())
        pilha.pop();
      else if (str[i] == ')' && pilha.empty())
        flag = false;
    }
    if (flag && pilha.empty())
      std::cout << "correct" << std::endl;
    else
      std::cout << "incorrect" << std::endl;
    str.clear();
    while (!pilha.empty())
      pilha.pop();
  }
  return 0;
}
