#include "tempo.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Tempo padrao1;
  Tempo custom(11, 20, 36);

  cout << "Hora padrão: ";
  padrao1.imprime();

  cout << "\nHora customizada: ";
  custom.imprime();

  cout << endl;

  padrao1.setTempo(11, 25, 00);
  cout << "Hora padrão setada: ";
  padrao1.imprime();

  cout << endl;
  return 0;
}
