#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char texto[10001], stack[10001];
  int tam, tam2, ind = 0, flag = 0;

  scanf("%s", texto);
  tam2 = tam = strlen(texto);

  for (int i = 0; i < tam; i++) {
    if (texto[i] == '{' || texto[i] == '[' || texto[i] == '(') {
      stack[ind] = texto[i];
      ind++;
    }
    if (texto[i] == '}') {
      if (stack[ind - 1] == '{') {
        ind--;
      } else {
        flag = 1;
        break;
      }
    }
    if (texto[i] == ']') {
      if (stack[ind - 1] == '[') {
        ind--;
      } else {
        flag = 1;
        break;
      }
    }
    if (texto[i] == ')') {
      if (stack[ind - 1] == '(') {
        ind--;
      } else {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) {
    printf("S\n");
  } else {
    printf("N\n");
  }
  return 0;
}
