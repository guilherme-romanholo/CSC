#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

  queue<int> fila;
  queue<int> filaAux;
  int opc, val;
  char c;
  do {
    system("clear");
    cout << "=====Estudo das filas(FIFO)=====" << endl;
    cout << "(1)Adicionar elemento\n(2)Remover elemento\n(3)Elemento do "
            "início(front)\n(4)Elemento do fim(back)\n(5)Tamanho da "
            "fila\n(6)Imprimir fila\n(0)Sair"
         << endl;
    cin >> opc;
    switch (opc) {
    case 1:
      cout << "Digite um número para colocar na fila" << endl;
      cin >> val;
      fila.push(val);
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
      break;
    case 2:
      fila.pop();
      cout << "Elemento removido com sucesso!\nDigite alguma coisa para "
              "continuar..."
           << endl;
      cin >> c;
      break;
    case 3:
      cout << "Elemento do início da fila é: " << fila.front() << endl;
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
      break;
    case 4:
      cout << "Elemento do fim da fila é: " << fila.back() << endl;
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
      break;
    case 5:
      cout << "O tamanho da fila é: " << fila.size() << endl;
      cout << "Digite alguma coisa para continuar..." << endl;
      cin >> c;
      break;
    case 6:
      filaAux = fila;
      while (!filaAux.empty()) {
        cout << filaAux.front() << " ";
        filaAux.pop();
      }
      cout << "\nDigite alguma coisa para continuar..." << endl;
      cin >> c;
      break;
    }
  } while (opc != 0);
  cout << "Fim do programa!" << endl;
  return 0;
}
