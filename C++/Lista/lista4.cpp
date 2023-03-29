#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#define tam 10

using namespace std;

int main(int argc, char *argv[]) {
  srand(time(NULL));
  list<int> lista, aux;
  list<int>::iterator it;
  int opc, pos, val;
  for (int i = 0; i < tam; i++) {
    lista.push_front(rand() % 20);
  }

  do {
    system("clear");
    aux = lista;
    for (int i = 0; i < lista.size(); i++) {
      cout << aux.front() << " ";
      aux.pop_front();
    }
    cout << "\n=====Teste de Iterators=====" << endl;
    cout
        << "(1)Inserir em alguma posição\n(2)Remover de alguma posição\n(0)Sair"
        << endl;
    cin >> opc;
    switch (opc) {
    case 1:
      it = lista.begin();
      cout << "Digite a posição: " << endl;
      cin >> pos;
      cout << "Digite o valor: " << endl;
      cin >> val;
      advance(it, --pos);
      lista.insert(it, val);
      break;
    case 2:
      it = lista.begin();
      cout << "Digite a posição: " << endl;
      cin >> pos;
      advance(it, pos);
      lista.erase(--it);
      break;
    }
  } while (opc != 0);

  return 0;
}
