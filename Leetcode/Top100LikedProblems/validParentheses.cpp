#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char *argv[]) {
  string input = "()";
  bool flag = true;
  stack<char> stack;

  cin >> input;

  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '[' || input[i] == '{' || input[i] == '(')
      stack.push(input[i]);
    if (input[i] == ']' || input[i] == '}' || input[i] == ')') {
      if (input[i] == ']' && stack.top() == '[')
        stack.pop();
      else if (input[i] == '}' && stack.top() == '{')
        stack.pop();
      else if (input[i] == ')' && stack.top() == '(')
        stack.pop();
      else
        flag = false;
    }
  }

  if (flag)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  return 0;
}
