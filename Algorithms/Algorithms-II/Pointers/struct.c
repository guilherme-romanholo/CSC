#include <stdio.h>

typedef struct horario {
  int hora;
  int minuto;
  int segundo;
} Hor;

int main(int argc, char *argv[]) {
  Hor agora, *depois;
  depois = &agora;
  depois->hora = 20; // o compilador precisa ver assim (*depois).hora que é
                     // igual depois->hora
  depois->minuto = 30;
  depois->segundo = 45;
  printf("%d:%d:%d\n", agora.hora, agora.minuto, agora.segundo);
  return 0;
}
