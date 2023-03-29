#include <iostream>
#include <list>
#define tam 16

using namespace std;

int main(int argc, char *argv[]) {
  list<int> lista1, lista2, aux1, aux2;
  int opc;
  for (int i = 1; i < tam; i += 2) {
    lista1.push_front(i);
  }
  for (int i = 0; i < tam; i += 2) {
    lista2.push_front(i);
  }
  aux1 = lista1;
  aux2 = lista2;
  cout << "Lista 1: ";
  for (int i = 0; i < lista1.size(); i++) {
    cout << aux1.front() << " ";
    aux1.pop_front();
  }
  cout << "\n";
  cout << "Lista 2: ";
  for (int i = 0; i < lista2.size(); i++) {
    cout << aux2.front() << " ";
    aux2.pop_front();
  }
  cout << "\nEscolha uma opção:\n(1)Limpar a lista\n(2)Mesclar listas" << endl;
  cin >> opc;

  if (opc == 1) {
    lista1.clear();
    lista2.clear();
    cout << "O tamanho da lista 1 é: " << lista1.size() << endl;
    cout << "O tamanho da lista 2 é: " << lista2.size() << endl;
  } else {
    lista1.merge(lista2);
    cout << "O tamanho da lista 1 é: " << lista1.size() << endl;
    cout << "O tamanho da lista 2 é: " << lista2.size() << endl;
    for (int i = 0; i < tam; i++) {
      cout << lista1.front() << " ";
      lista1.pop_front();
    }
  }
  cout << "\n";
  return 0;
}
