#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  int tam, i, j;
  char aux;
  std::vector<char> str;
  std::vector<int> vet1;
  std::vector<int> vet2;

  std::cin >> tam;
  for (i = 0; i < tam; i++) {
    std::cin >> aux;
    str.push_back(aux);
  }

  for (i = 0; i < tam; i++) {
    for (j = i; j < tam; j++) {
      vet2.insert();
      if (std::equal(vet1.begin(), vet1.end(), vet2.begin())) {
      }
    }
    str2.clear();
  }
  return 0;
}
