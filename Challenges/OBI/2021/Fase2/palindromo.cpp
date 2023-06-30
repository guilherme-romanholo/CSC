#include <cstring>
#include <iostream>

using namespace std;

string matriz[5001][5001];

string subcadeias(int inicio, int fim, string pal) {
  string aux;
  int j = 0;
  for (int i = inicio; i <= fim; i++) {
    aux[j] = pal[i];
    j++;
  }
  aux[j] = '\0';
  return aux;
}

void preenchermatriz(int tam, string pal) {
  for (int i = 0; i < tam; i++) {
    for (int j = i; j < tam + 1; j++) {
      matriz[i][j] = subcadeias(i, j, pal);
    }
  }
}

int palindromo(int tam, string pal) {
  for (int i = 0, j = tam - 1; i < tam; i++, j--) {
    if (pal[i] != pal[j]) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int tam, maior = 0;
  string palavra;
  cout << "Digite o tamanho da palavra: " << endl;
  cin >> tam;
  cout << "Digite uma palavra: " << endl;
  cin >> palavra;
  preenchermatriz(tam, palavra);

  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      if (palindromo(j - i + 1, matriz[i][j])) {
        if (j - i + 1 > maior) {
          maior = j - i + 1;
        }
      }
    }
  }
  cout << maior << endl;

  // if (palindromo(tam, palavra)) {
  //   cout << "É um palindromo!" << endl;
  // } else {
  //   cout << "Não é um palindromo!" << endl;
  // }
  return 0;
}
