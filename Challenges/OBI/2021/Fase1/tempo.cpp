#include <iostream>
#include <queue>
#include <vector>

int main(int argc, char *argv[]) {
  int N, i, num;
  char tipo;
  std::vector<int> vet;
  std::queue<int> contatos;

  std::cin >> N;

  for (i = 0; i < N; i++) {
    std::cin >> tipo;
    std::cin >> num;
    if (tipo == 'R') {
      contatos.push(num);
    }
    if (tipo != 'T') {
      vet.push_back(num);
      vet.push_back(1);
    } else {
      vet.pop_back();
      vet.push_back(num);
    }
  }
  vet.pop_back();

  while (contatos.size()) {
    for (i = 0; i < vet.size(); i++) {
      if (vet[i] == contatos.front()) {
      }
    }
  }

  return 0;
}
