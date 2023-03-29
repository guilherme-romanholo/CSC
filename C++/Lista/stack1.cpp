#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
  stack<int> pilha;
  stack<int> pilhaAux;
  int val, opc;
  char c;
  do {
    system("clear");
    cout << "=====Estudo da biblioteca STACK=====" << endl;
    cout << "Escolha uma opção:\n(1)Adicionar elemento(Push)\n(2)Retirar "
            "elemento(Pop)\n(3)Tamanho da pilha\n(4)Elemento do "
            "topo\n(5)Imprimir pilha\n(0)Sair"
         << endl;
    cin >> opc;
    if (opc == 1) {
      cout << "Digite um número para ser adicionado à pilha:" << endl;
      cin >> val;
      pilha.push(val);
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
    } else if (opc == 2) {
      if (!pilha.empty()) {
        pilha.pop();
        cout << "Elemento do topo retirado!" << endl;
      } else {
        cout << "Pilha vazia, não é possível retirar!" << endl;
      }
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
    } else if (opc == 3) {
      if (pilha.empty()) {
        cout << "A pilha está vázia!" << endl;
      } else {
        cout << "O tamanho da atual da pilha é: " << pilha.size() << endl;
      }
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
    } else if (opc == 4) {
      if (!pilha.empty()) {
        cout << "O elemento do topo da pilha é: " << pilha.top() << endl;
      } else {
        cout << "A pilha está vazia!" << endl;
      }
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
    } else if (opc == 5) {
      pilhaAux = pilha;
      cout << "Os elementos da pilha são: " << endl;
      while (!pilhaAux.empty()) {
        cout << pilhaAux.top() << endl;
        pilhaAux.pop();
      }
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
    }
  } while (opc != 0);
  cout << "Programa finalizado!" << endl;
  return 0;
}
