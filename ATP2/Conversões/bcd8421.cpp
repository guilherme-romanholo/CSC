#include <iostream>
#include <stack>

void bcd(int num, std::stack<std::string> *res) {
  char vet[10][5] = {{"0000"}, {"0001"}, {"0010"}, {"0011"}, {"0100"},
                     {"0101"}, {"0110"}, {"0111"}, {"1000"}, {"1001"}};
  res->push(vet[num]);
}

int main(int argc, char *argv[]) {
  int num, aux;
  std::stack<std::string> res;

  std::cout << "Digite um número decimal positivo: " << std::endl;
  std::cin >> num;

  while (num) {
    aux = num % 10;
    bcd(aux, &res);
    num = num / 10;
  }
  while (res.size()) {
    std::cout << res.top() << " ";
    res.pop();
  }

  std::cout << std::endl;
  return 0;
}
