#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  int tam, n, k, i, j, cont, num, pos, t, l;
  char aux;
  std::string senha, senhaaux;

  std::cin >> tam >> n >> k;
  std::cin >> senha;

  char partes[n][k];

  for (i = 0; i < n; i++) {
    std::cin >> partes[i];
  }
  // for (i = 0; i < n; i++) {
  //   for (j = 0; j < k; j++) {
  //     std::cout << partes[i][j] << " ";
  //   }
  //   std::cout << "\n";
  // }

  std::cin >> num;

  for (cont = 0; cont < n * k; cont++) {
    senhaaux = senha;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        t = 0;
        while (senhaaux[t] != '#')
          t++;
        senhaaux[t] = partes[j][i];
      }
    }
    std::cout << senhaaux << std::endl;
  }

  return 0;
}
