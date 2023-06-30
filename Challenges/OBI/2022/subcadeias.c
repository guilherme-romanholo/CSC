#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (a > b ? a : b)

int main(int argc, char *argv[]) {
  int n, resp = 0;
  char *pal;
  bool flag;

  scanf("%d", &n);
  pal = malloc((n * sizeof(char)) + 1);
  scanf(" %s", pal);

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      flag = true;
      for (int pi = i, pj = j; pi <= pj; pi++, pj--) {
        if (pal[pi] != pal[pj])
          flag = false;
      }
      if (flag) {
        resp = max(resp, j - i + 1);
      }
    }
  }
  printf("%d\n", resp);

  return 0;
}
