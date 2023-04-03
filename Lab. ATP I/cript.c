#include <stdio.h>
#define n 100000

int main(int argc, char const *argv[]) {
  int i = 0;
  char msg[n], codletras[n];
  int m[n], cod[n], decod[n], opc;
  printf("\t------Cifra de César------\n");
  printf("[1]Codificar\n[2]Decodificar\n");
  scanf("%d", &opc);

  if (opc == 1) {
    printf("Digite a mensagem que deseja criptografar (letras minúsculas):\n");
    scanf(" %[^\n]s", msg);
    // PRÉ CODIFICAÇÃO
    int i = 0;
    while (msg[i] != '\0') {
      switch (msg[i]) {
      case 'a':
        m[i] = 0;
        break;
      case 'b':
        m[i] = 1;
        break;
      case 'c':
        m[i] = 2;
        break;
      case 'd':
        m[i] = 3;
        break;
      case 'e':
        m[i] = 4;
        break;
      case 'f':
        m[i] = 5;
        break;
      case 'g':
        m[i] = 6;
        break;
      case 'h':
        m[i] = 7;
        break;
      case 'i':
        m[i] = 8;
        break;
      case 'j':
        m[i] = 9;
        break;
      case 'k':
        m[i] = 10;
        break;
      case 'l':
        m[i] = 11;
        break;
      case 'm':
        m[i] = 12;
        break;
      case 'n':
        m[i] = 13;
        break;
      case 'o':
        m[i] = 14;
        break;
      case 'p':
        m[i] = 15;
        break;
      case 'q':
        m[i] = 16;
        break;
      case 'r':
        m[i] = 17;
        break;
      case 's':
        m[i] = 18;
        break;
      case 't':
        m[i] = 19;
        break;
      case 'u':
        m[i] = 20;
        break;
      case 'v':
        m[i] = 21;
        break;
      case 'w':
        m[i] = 22;
        break;
      case 'x':
        m[i] = 23;
        break;
      case 'y':
        m[i] = 24;
        break;
      case 'z':
        m[i] = 25;
        break;
      case ' ':
        m[i] = -2;
        break;
      }
      i++;
    }
    m[i] = -1;
    i = 0;
    // CODIFICAÇÃO
    while (m[i] != -1) {
      if (m[i] > 0) {
        cod[i] = (m[i] + 3) % 26;
      } else {
        cod[i] = m[i];
      }
      i++;
    }
    cod[i] = -1;
    i = 0;
    // TRANSFORMANDO EM LETRAS
    while (cod[i] != -1) {
      switch (cod[i]) {
      case 0:
        codletras[i] = 'a';
        break;
      case 1:
        codletras[i] = 'b';
        break;
      case 2:
        codletras[i] = 'c';
        break;
      case 3:
        codletras[i] = 'd';
        break;
      case 4:
        codletras[i] = 'e';
        break;
      case 5:
        codletras[i] = 'f';
        break;
      case 6:
        codletras[i] = 'g';
        break;
      case 7:
        codletras[i] = 'h';
        break;
      case 8:
        codletras[i] = 'i';
        break;
      case 9:
        codletras[i] = 'j';
        break;
      case 10:
        codletras[i] = 'k';
        break;
      case 11:
        codletras[i] = 'l';
        break;
      case 12:
        codletras[i] = 'm';
        break;
      case 13:
        codletras[i] = 'n';
        break;
      case 14:
        codletras[i] = 'o';
        break;
      case 15:
        codletras[i] = 'p';
        break;
      case 16:
        codletras[i] = 'q';
        break;
      case 17:
        codletras[i] = 'r';
        break;
      case 18:
        codletras[i] = 's';
        break;
      case 19:
        codletras[i] = 't';
        break;
      case 20:
        codletras[i] = 'u';
        break;
      case 21:
        codletras[i] = 'v';
        break;
      case 22:
        codletras[i] = 'w';
        break;
      case 23:
        codletras[i] = 'x';
        break;
      case 24:
        codletras[i] = 'y';
        break;
      case 25:
        codletras[i] = 'z';
        break;
      case -2:
        codletras[i] = ' ';
        break;
      }
      i++;
    }
    codletras[i] = '\0';
    i = 0;
    printf("%s\n", codletras);
  } else {
    // PROCESSO DE DECODIFICAÇÂO
    printf("Digite a mensagem codificada:\n");
    scanf(" %[^\n]s", codletras);
    i = 0;
    while (codletras[i] != '\0') {
      switch (codletras[i]) {
      case 'a':
        m[i] = 0;
        break;
      case 'b':
        m[i] = 1;
        break;
      case 'c':
        m[i] = 2;
        break;
      case 'd':
        m[i] = 3;
        break;
      case 'e':
        m[i] = 4;
        break;
      case 'f':
        m[i] = 5;
        break;
      case 'g':
        m[i] = 6;
        break;
      case 'h':
        m[i] = 7;
        break;
      case 'i':
        m[i] = 8;
        break;
      case 'j':
        m[i] = 9;
        break;
      case 'k':
        m[i] = 10;
        break;
      case 'l':
        m[i] = 11;
        break;
      case 'm':
        m[i] = 12;
        break;
      case 'n':
        m[i] = 13;
        break;
      case 'o':
        m[i] = 14;
        break;
      case 'p':
        m[i] = 15;
        break;
      case 'q':
        m[i] = 16;
        break;
      case 'r':
        m[i] = 17;
        break;
      case 's':
        m[i] = 18;
        break;
      case 't':
        m[i] = 19;
        break;
      case 'u':
        m[i] = 20;
        break;
      case 'v':
        m[i] = 21;
        break;
      case 'w':
        m[i] = 22;
        break;
      case 'x':
        m[i] = 23;
        break;
      case 'y':
        m[i] = 24;
        break;
      case 'z':
        m[i] = 25;
        break;
      case ' ':
        m[i] = -2;
        break;
      default:
        break;
      }
      i++;
    }
    m[i] = -1;
    i = 0;
    while (m[i] != -1) {
      if (m[i] > 0) {
        decod[i] = (m[i] + 23) % 26;
      } else {
        decod[i] = m[i];
      }
      i++;
    }
    decod[i] = -1;
    i = 0;
    while (decod[i] != -1) {
      switch (decod[i]) {
      case 0:
        msg[i] = 'a';
        break;
      case 1:
        msg[i] = 'b';
        break;
      case 2:
        msg[i] = 'c';
        break;
      case 3:
        msg[i] = 'd';
        break;
      case 4:
        msg[i] = 'e';
        break;
      case 5:
        msg[i] = 'f';
        break;
      case 6:
        msg[i] = 'g';
        break;
      case 7:
        msg[i] = 'h';
        break;
      case 8:
        msg[i] = 'i';
        break;
      case 9:
        msg[i] = 'j';
        break;
      case 10:
        msg[i] = 'k';
        break;
      case 11:
        msg[i] = 'l';
        break;
      case 12:
        msg[i] = 'm';
        break;
      case 13:
        msg[i] = 'n';
        break;
      case 14:
        msg[i] = 'o';
        break;
      case 15:
        msg[i] = 'p';
        break;
      case 16:
        msg[i] = 'q';
        break;
      case 17:
        msg[i] = 'r';
        break;
      case 18:
        msg[i] = 's';
        break;
      case 19:
        msg[i] = 't';
        break;
      case 20:
        msg[i] = 'u';
        break;
      case 21:
        msg[i] = 'v';
        break;
      case 22:
        msg[i] = 'w';
        break;
      case 23:
        msg[i] = 'x';
        break;
      case 24:
        msg[i] = 'y';
        break;
      case 25:
        msg[i] = 'z';
        break;
      case -2:
        msg[i] = ' ';
        break;
      }
      i++;
    }
    msg[i] = '\0';
    printf("%s\n", msg);
  }
  return 0;
}
