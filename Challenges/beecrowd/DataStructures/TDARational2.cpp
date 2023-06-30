#include <iostream>
#include <queue>
#include <string>
#include <vector>

void divisao(std::string, std::queue<char>);
void soma(std::string, std::queue<char>);
void subt(std::string, std::queue<char>);
void mult(std::string, std::queue<char>);
void simpl(long long int, long long int);

int main(int argc, char *argv[]) {
  std::queue<char> fila;
  std::string str;
  bool flag;
  int i, j, n, tam;

  std::cin >> n;
  std::cin.ignore();

  for (j = 0; j < n; j++) {
    flag = false;
    std::getline(std::cin, str);
    tam = str.size();

    for (i = 0; i < tam; i++) {
      if (str[i] != ' ') {
        fila.push(str[i]);
      }
    }

    for (i = 0; i < tam; i++) {
      if (str[i] == '/' && flag == false) {
        flag = true;
        i++;
      }
      if (flag && str[i] == '/') {
        divisao(str, fila);
        break;
      } else if (flag && str[i] == '+') {
        soma(str, fila);
        break;
      } else if (flag && str[i] == '-') {
        subt(str, fila);
        break;
      } else if (flag && str[i] == '*') {
        mult(str, fila);
        break;
      }
    }
    while (!fila.empty())
      fila.pop();
    str.clear();
  }
  return 0;
}

void divisao(std::string str, std::queue<char> fila) {
  int i = 0, num, den, teste;
  std::vector<long long int> vet;
  std::string aux;

  fila.push('/');

  while (!fila.empty()) {
    if (fila.front() != '/') {
      aux.push_back(fila.front());
    } else {
      teste = std::stoi(aux);
      vet.push_back(teste);
      aux.clear();
    }
    fila.pop();
  }
  num = vet[0] * vet[3];
  den = vet[1] * vet[2];

  std::cout << num << "/" << den << " = ";
  simpl(num, den);
}

void soma(std::string str, std::queue<char> fila) {
  int i = 0, num, den, teste;
  std::vector<long long int> vet;
  std::string aux;

  fila.push('/');

  while (!fila.empty()) {
    if (fila.front() != '/' && fila.front() != '+') {
      aux.push_back(fila.front());
    } else {
      teste = std::stoi(aux);
      vet.push_back(teste);
      aux.clear();
    }
    fila.pop();
  }

  num = (vet[0] * vet[3]) + (vet[1] * vet[2]);
  den = vet[1] * vet[3];

  std::cout << num << "/" << den << " = ";
  simpl(num, den);
}

void subt(std::string str, std::queue<char> fila) {
  int i = 0, num, den, teste;
  std::vector<long long int> vet;
  std::string aux;

  fila.push('/');

  while (!fila.empty()) {
    if (fila.front() != '/' && fila.front() != '-') {
      aux.push_back(fila.front());
    } else {
      teste = std::stoi(aux);
      vet.push_back(teste);
      aux.clear();
    }
    fila.pop();
  }
  num = (vet[0] * vet[3]) - (vet[1] * vet[2]);
  den = vet[1] * vet[3];

  std::cout << num << "/" << den << " = ";
  simpl(num, den);
}

void mult(std::string str, std::queue<char> fila) {
  int i = 0, num, den, teste;
  std::vector<long long int> vet;
  std::string aux;

  fila.push('/');

  while (!fila.empty()) {
    if (fila.front() != '/' && fila.front() != '*') {
      aux.push_back(fila.front());
    } else {
      teste = std::stoi(aux);
      vet.push_back(teste);
      aux.clear();
    }
    fila.pop();
  }
  num = vet[0] * vet[2];
  den = vet[1] * vet[3];

  std::cout << num << "/" << den << " = ";
  simpl(num, den);
}

void simpl(long long int num, long long int den) {
  while (!(num % 3) && !(num % 3) && num != 1 && den != 1) {
    num = num / 3;
    den = den / 3;
  }
  while (!(num % 2) && !(den % 2) && num != 1 && den != 1) {
    num = num / 2;
    den = den / 2;
  }
  std::cout << num << "/" << den << std::endl;
}
