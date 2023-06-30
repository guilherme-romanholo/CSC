#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, i, *resp, x, y;
  scanf("%d", &n);
  resp = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    if ((x + y) % 2) {
      resp[i] = 'B';
    } else {
      resp[i] = 'A';
    }
  }
  for (i = 0; i < n; i++) {
    printf("%c\n", resp[i]);
  }

  return 0;
}
