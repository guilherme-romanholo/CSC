#include <iostream>

int main(int argc, char *argv[]) {
  int N, F, i, j;
  std::string *matriz;

  std::cin >> N >> F;

  matriz = new std::string[N];

  for (i = 0; i < N; i++) {
    std::cin >> matriz[i];
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if ((matriz[i][j] - '0' <= F && j == 0) ||
          (matriz[i][j] - '0' <= F &&
           (matriz[i + 1][j] == '*' || matriz[i - 1][j] == '*' ||
            matriz[i][j + 1] == '*' || matriz[i][j - 1] == '*'))) {
        matriz[i][j] = '*';
      }
    }
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      std::cout << matriz[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}
