#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

  vector<int> num, num2;
  // é possível usar num.insert() com iterator para vector também
  // é possível usar todos os métodos de pilha, fila e lista

  for (int i = 0; i < 5; i++) {
    num.push_back(i);
  }
  for (int i = 5; i < 10; i++) {
    num2.push_back(i);
  }
  for (int i = 0; i < 5; i++) {
    cout << num[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < 5; i++) {
    cout << num2[i] << " ";
  }
  cout << "\nTamanho do vector 1: " << num.size() << endl;
  cout << "Tamanho do vector 2: " << num2.size() << endl;

  cout << "=====Swap=====" << endl;
  num.swap(num2);
  for (int i = 0; i < 5; i++) {
    cout << num[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < 5; i++) {
    cout << num2[i] << " ";
  }
  cout << "\n";

  cout << "Primeiro valor do vector 1: " << num.front() << endl;
  cout << "Último valor do vector 1: " << num.back() << endl;

  cout << "Tamanho do meio do vector 1: " << num.at(num.size() / 2) << endl;
  return 0;
}
