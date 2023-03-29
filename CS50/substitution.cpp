#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int cript[26];
char decript[27] = "abcdefghijklmnopqrstuvwxyz";

bool validateKey(char *key) {
  int verifica[26], check, i;
  for (i = 0; i < 25; i++) {
    verifica[i] = 0;
  }
  if (strlen(key) != 26) {
    cout << "Sua chave não possui 26 letras!" << endl;
    return false;
  }
  for (int i = 0; i < strlen(key); i++) {
    if (!isalpha(key[i])) {
      cout << "A chave precisa possuir somente letras!" << endl;
      return false;
    }
  }
  for (i = 0; i < 25; i++) {
    check = key[i] - 'A';
    if (verifica[i] == 1) {
      cout << "Sua chave possui letras repetidas!" << endl;
      return false;
    }
    verifica[check] = 1;
  }
  if (verifica[i] == 1) {
    cout << "Sua chave possui letras repetidas!" << endl;
    return false;
  }
  for (int i = 0; i < 25; i++) {
    cript[i] = (toupper(key[i]) - 'A') % 26;
  }
  return true;
}

int main(int argc, char *argv[]) {

  string palavra;
  int k;

  if (argc != 2) {
    cout << "Digite na frente uma chave contendo o alfabeto embaralhado para "
            "criptografar a frase!"
         << endl;
    return 0;
  }
  if (!validateKey(argv[1])) {
    cout << "Chave Inválida!" << endl;
  }
  cin.ignore();
  getline(cin, palavra);

  for (int i = 0; i < palavra.size(); i++) {
    if (!isalpha(palavra[i])) {
      k = palavra[i] - '0';
      cout << decript[cript[k]];
    } else {
      cout << palavra[i];
    }
  }
  cout << "\n";
  return 0;
}
