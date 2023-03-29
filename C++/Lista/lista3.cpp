#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
  srand(time(NULL));
  list<int> lista, aux;
  int tam = 10, opc;

  for (int i = 0; i < tam; i++) {
    lista.push_front(rand() % 20);
  }
  cout << "Lista: " << endl;
  aux = lista;
  for (int i = 0; i < tam; i++) {
    cout << aux.front() << " ";
    aux.pop_front();
  }

  cout << "\nEscolha uma opção:\n(1)Ordenar\n(2)Inverter" << endl;
  cin >> opc;
  if (opc == 1) {
    lista.sort();
  } else {
    lista.reverse();
  }

  for (int i = 0; i < tam; i++) {
    cout << lista.front() << " ";
    lista.pop_front();
  }
  cout << "\n";
  return 0;
}
