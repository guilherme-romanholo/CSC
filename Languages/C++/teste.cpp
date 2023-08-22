#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int num;
  string nome;
  cout << "Digite um número: " << endl;
  cin >> num;
  cout << "Digite um nome: " << endl;
  cin.ignore();
  getline(cin, nome);
  cout << "Você digitou o número " << num << " e o nome " << nome
       << " no programa." << endl;
  return 0;
}
