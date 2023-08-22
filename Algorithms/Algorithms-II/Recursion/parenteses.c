#include <stdio.h>
#include <string.h>

int parenteses(char *str, int tam) {
  int flag = 1;
  if (tam == 0) {
    if (*str == '(') {
      return 1;
    } else {
      return 0;
    }
  } else {
    if (*str == ')' && flag == 0) {
      return 0;
    } else if (*str == ')' && flag == 1) {
      flag = parenteses(++str, --tam);
    }
    flag = parenteses(++str, --tam);
    return flag;
  }
}

int main(int argc, char *argv[]) {
  char str[20];
  int len;

  scanf(" %s", str);

  len = strlen(str);

  if (parenteses(str, len)) {
    printf("Sim!\n");
  } else {
    printf("Não!\n");
  }
  return 0;
}
