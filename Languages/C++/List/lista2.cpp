#include <iostream>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
  // usando iterator para navegar pela lista
  list<int> lista;
  int tam = 10, aux;
  list<int>::iterator it; // declaramos um iterator para list<int>

  for (int i = 0; i < tam; i++) {
    lista.push_front(i);
  }

  it = lista.begin(); // coloca o iterator no inicio da lista
  advance(it, 5);     // move o iterator para quinta posição

  lista.insert(it, 0); // insere o 0 na posição do iterator

  aux = lista.size();
  for (int i = 0; i < aux; i++) {
    cout << lista.front() << endl;
    lista.pop_front();
  }
  return 0;
}
