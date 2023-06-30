#include <iostream>
#include <string>

void verifica(int *vet) {
  int cont = 0, i;

  for (i = 0; i < 13; i++) { // faz a contagem de quantas cartas estão faltando
    if (vet[i] == 0) {
      cont++;
    } else if (vet[i] == 2) {
      std::cout << "erro" << std::endl;
      return; // se alguma carta estiver duplicada ele retorna um erro
    }
  }

  std::cout << cont << std::endl;
}

int main(int argc, char *argv[]) {
  std::string input;
  char num[3], naipe;
  int i, j, C[13] = {0}, E[13] = {0}, P[13] = {0}, U[13] = {0};

  std::cin >> input;

  for (i = 0; i < input.size(); i += 3) {
    input.copy(num, 2, i); // copia os caracteres numericos para num
    naipe = input[i + 2];  // copia o caractere do naipe
    if (naipe == 'C') {
      C[std::stoi(num) - 1]++; // marca no vertor que ja possuimos a carta (1),
                               // temos duplicada(2) e não temos (0)
    } else if (naipe == 'P') {
      P[std::stoi(num) - 1]++;
    } else if (naipe == 'E') {
      E[std::stoi(num) - 1]++;
    } else if (naipe == 'U') {
      U[std::stoi(num) - 1]++;
    }
  }

  verifica(C);
  verifica(E);
  verifica(U);
  verifica(P);

  return 0;
}
