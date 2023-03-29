#include <stdio.h>

int func(int *px, int *py, int *pz);

int main(int argc, char *argv[]) {

  int x, y, z;

  scanf("%d %d %d", &x, &y, &z);

  if (func(&x, &y, &z)) {
    printf("X = %d\nY = %d\nZ = %d\n", x, y, z);
    printf("Os valores são iguais!\n");
  } else {
    printf("X = %d\nY = %d\nZ = %d\n", x, y, z);
    printf("Os valores não são iguais!\n");
  }

  return 0;
}

int func(int *px, int *py, int *pz) {
  int aux;
  if (*px == *py && *py == *pz) {
    return 1;
  } else {
    if (*px > *py && *px > *pz) {
      if (*py > *pz) {
        return 0;
      } else {
        aux = *pz;
        *pz = *py;
        *py = aux;
      }
    }
  }
  return 0;
}
