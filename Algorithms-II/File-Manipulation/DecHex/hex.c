#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int num, aux, arr[50], i, j;
  char arrc[50];
  FILE *fp = fopen("decimal.dat", "r");
  FILE *out = fopen("hexadecimal.dat", "a");

  while (fscanf(fp, "%d ", &num) != EOF) {
    aux = num;
    i = 0;
    memset(arrc, -1, 50 * sizeof(char));
    memset(arr, -1, 50 * sizeof(int));

    while (aux != 0) {
      arr[i] = aux % 16;
      aux = aux / 16;
      i++;
    }

    j = 0;
    i--;

    while (i != -1) {
      switch (arr[i]) {
      case 10:
        arrc[j] = 'A';
        break;
      case 11:
        arrc[j] = 'B';
        break;
      case 12:
        arrc[j] = 'C';
        break;
      case 13:
        arrc[j] = 'D';
        break;
      case 14:
        arrc[j] = 'E';
        break;
      case 15:
        arrc[j] = 'F';
        break;
      default:
        arrc[j] = 48 + arr[i];
        break;
      }
      i--;
      j++;
    }
    arrc[j] = '\0';

    fprintf(out, "%s ", arrc);
  }

  fclose(fp);
  fclose(out);
  return 0;
}
