#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

void somar(std::string pal);
void subtrair(std::string pal);
void mult(std::string pal);
void div(std::string pal);

int main(int argc, char *argv[]) {
  std::string str;

  std::getline(std::cin, str);

  switch () {
  case '+':
    somar(str);
    break;
  case '-':
    // subtrair();
    break;
  case '*':
    // mult();
    break;
  case '/':
    // div();
    break;
  default:
    break;
  }

  return 0;
}

void somar(std::string pal) {
  int n1, n2, d1, d2, s1, s2;
  std::string aux;
  std::vector<std::string> res;

  n1 = std::stoi(pal);
  d1 = pal[4] - '0';
  n2 = pal[8] - '0';
  d2 = pal[12] - '0';
  s1 = n1 * d2 + n2 * d1;
  s2 = d1 * d2;

  res.push_back(std::to_string(s1));
  res.push_back("/");
  res.push_back(std::to_string(s2));

  for (auto var : res) {
    std::cout << var;
  }
  std::cout << " = ";

  res.clear();

  while (!(s1 % 2) && !(s2 % 2)) {
    s1 = s1 / 2;
    s2 = s2 / 2;
  }
  while (!s1 % 3 && !s2 % 3) {
    s1 = s1 / 3;
    s1 = s1 / 3;
  }

  res.push_back(std::to_string(s1));
  res.push_back("/");
  res.push_back(std::to_string(s2));

  for (auto var : res) {
    std::cout << var;
  }
  std::cout << std::endl;

  res.clear();
}
