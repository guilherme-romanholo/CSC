#include <stdio.h>

typedef struct horario {
  int *pHora;
  int *pMin;
  int *pSeg;
} Hor;

int main(int argc, char *argv[]) {
  Hor hoje;
  int hora = 100, minuto = 20, segundo = 80;

  hoje.pHora = &hora;
  hoje.pMin = &minuto;
  hoje.pSeg = &segundo;

  printf("Hora -- %d\n", *hoje.pHora);
  printf("Minuto -- %d\n", *hoje.pMin);
  printf("Segundo -- %d\n", *hoje.pSeg);

  *hoje.pSeg = 1000;

  printf("Segundo -- %d\n", *hoje.pSeg);
  return 0;
}
