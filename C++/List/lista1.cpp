#include <iostream>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
  list<int> lista; // na lista é possível inserir valores por trás e pela frente
  int tam,
      opc; // além disso é possível retirar os valores por trás e pela frente
  cout << "(1)Inserir pela frente\n(2)Inserir por trás" << endl, cin >> opc;
  cout << "Digite o tamanho da lista:" << endl;
  cin >> tam;
  if (opc == 1) {
    for (int i = 0; i < tam; i++) {
      lista.push_front(i);
    }
  } else {
    for (int i = 0; i < tam; i++) {
      lista.push_back(i);
    }
  }
  cout << "O tamanho da lista é: " << lista.size() << endl;
  for (int i = 0; i < tam; i++) {
    cout << lista.front() << endl;
    lista.pop_front();
  }

  return 0;
}
