#include <stdio.h>
#include <string.h>

void romano(int N) {
  int i = 0;
  char aux[30];
  while (N != 0) {
    if (N / 1000) {
      N -= 1000;
      aux[i] = 'M';
    } else if (N / 900) {
      N -= 900;
      aux[i] = 'C';
      i++;
      aux[i] = 'M';
    } else if (N / 500) {
      N -= 500;
      aux[i] = 'D';
    } else if (N / 400) {
      N -= 400;
      aux[i] = 'C';
      i++;
      aux[i] = 'D';
    } else if (N / 100) {
      N -= 100;
      aux[i] = 'C';
    } else if (N / 90) {
      N -= 90;
      aux[i] = 'X';
      i++;
      aux[i] = 'C';
    } else if (N / 50) {
      N -= 50;
      aux[i] = 'L';
    } else if (N / 40) {
      N -= 40;
      aux[i] = 'X';
      i++;
      aux[i] = 'L';
    } else if (N / 10) {
      N -= 10;
      aux[i] = 'X';
    } else if (N / 9) {
      N -= 9;
      aux[i] = 'I';
      i++;
      aux[i] = 'X';
    } else if (N / 5) {
      N -= 5;
      aux[i] = 'V';
    } else if (N / 4) {
      N -= 4;
      aux[i] = 'I';
      i++;
      aux[i] = 'V';
    } else if (N / 1) {
      N -= 1;
      aux[i] = 'I';
    }
    i++;
  }
  aux[i] = '\0';
  printf("%s\n", aux);
}

void decimal(char *rom, int *soma) {
  int i = 0, len, num = 0;
  len = strlen(rom);
  for (i = 0; i < len; i++) {
    if (rom[i] == 'M') {
      num += 1000;
    } else if (rom[i] == 'D') {
      num += 500;
    } else if (rom[i] == 'C') {
      if (rom[i + 1] == 'M') {
        num += 900;
        i++;
      } else if (rom[i + 1] == 'D') {
        num += 400;
        i++;
      } else {
        num += 100;
      }
    } else if (rom[i] == 'L') {
      num += 50;
    } else if (rom[i] == 'X') {
      if (rom[i + 1] == 'C') {
        num += 90;
        i++;
      } else if (rom[i + 1] == 'L') {
        num += 40;
        i++;
      } else {
        num += 10;
      }
    } else if (rom[i] == 'V') {
      num += 5;
    } else if (rom[i] == 'I') {
      if (rom[i + 1] == 'X') {
        num += 9;
        i++;
      } else if (rom[i + 1] == 'V') {
        num += 4;
        i++;
      } else {
        num += 1;
      }
    }
  }
  printf("%d\n", num);
  *soma += num;
}

int main(int argc, char *argv[]) {
  int N, i, opc, num, soma = 0;
  char rom[30];
  // M  CM D CD C XC L XL X IX V IV I
  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%d", &opc);
    if (opc == 1) {
      scanf(" %s", rom);
      decimal(rom, &soma);
    } else {
      scanf("%d", &num);
      romano(num);
    }
  }
  printf("%d\n", soma);
  return 0;
}
