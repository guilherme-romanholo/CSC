#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *txt;
  int opc;
  char texto[100];

  do {
    printf("Escolha a operação:\n");
    printf("(1)Escrever Texto\n(2)Ler Texto\n(0)Sair\n");
    scanf("%d", &opc);
    if (opc == 1) {
      printf("Escreva o que quer guardar no arquivo:\n");
      scanf(" %[^\n]s", texto);
      txt = fopen("write.txt", "w");
      fputs(texto, txt);
      fclose(txt);
    } else if (opc == 2) {
      printf("No arquivo está escrito o seguinte:\n");
      txt = fopen("write.txt", "r");
      fscanf(txt, "%[^\n]s", texto);
      printf("%s\n", texto);
      fclose(txt);
    }
  } while (opc != 0);

  return 0;
}
