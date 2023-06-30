#include <iostream>
#include <stack>

int main(int argc, char *argv[]) {
  int i = 0;
  std::stack<char> pilha;
  std::string input;

  std::cin >> input;

  for (i = 0; i < input.size(); i++) {
    if (input[i] == '(' || input[i] == '{' || input[i] == '[') {
      pilha.push(input[i]);
    }
    if (input[i] == ']' && pilha.top() != '[') {
      std::cout << 'N' << std::endl;
      exit(0);
    } else if (input[i] == ']' && pilha.top() == '[') {
      pilha.pop();
    }
    if (input[i] == '}' && pilha.top() != '{') {
      std::cout << 'N' << std::endl;
      exit(0);
    } else if (input[i] == '}' && pilha.top() == '{') {
      pilha.pop();
    }
    if (input[i] == ')' && pilha.top() != '(') {
      std::cout << 'N' << std::endl;
      exit(0);
    } else if (input[i] == ')' && pilha.top() == '(') {
      pilha.pop();
    }
  }
  std::cout << 'S' << std::endl;
  return 0;
}
