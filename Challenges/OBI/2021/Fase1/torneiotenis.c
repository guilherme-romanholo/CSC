#include <stdio.h>

int main(int argc, char *argv[]) {
  int cont = 0;
  char res;
  for (int i = 0; i < 6; i++) {
    scanf(" %c", &res);
    if (res == 'V') {
      cont++;
    }
  }
  if (cont >= 5) {
    printf("1\n");
  } else if (cont == 3 || cont == 4) {
    printf("2\n");
  } else if (cont == 1 || cont == 2) {
    printf("1\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
