#include <iostream>
#include <vector>

void testaNum(int num, int soma, std::vector<int> *vet) {
  int soma2 = 0, aux = num;
  // separa os digitos e faz a soma
  while (aux) {
    soma2 += aux % 10;
    aux = aux / 10;
  }
  // caso as duas somas forem iguais guarda no veto
  if (soma == soma2) {
    vet->push_back(num);
  }
}

int main(int argc, char *argv[]) {
  int inic, fim, soma, i;
  std::vector<int> vet;

  std::cin >> soma;
  std::cin >> inic;
  std::cin >> fim;

  for (i = inic; i <= fim; i++) {
    testaNum(i, soma, &vet);
  }

  // printa o primeiro e ultimo elemento do vetor (menor e maior)
  std::cout << vet.front() << std::endl;
  std::cout << vet.back() << std::endl;

  return 0;
}
