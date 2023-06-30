#include <math.h>
#include <stdio.h>

void distanciaMRU(double veloc, double tempo);
void velocMRU(double dist, double tempo);
void tempoMRU(double dist, double veloc);
void distanciaMRUV(double veloc, double acel, double tempo);
void velocFinalMRUV(double velocini, double acel, double tempo);
void velocInicMRUV(double dist, double acel, double tempo);
void tempoTotalMRUV(double dist, double veloc, double acel);

int main(int argc, char *argv[]) {
  int N, i, O;
  double aux1, aux2, aux3;

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%d", &O);
    if (O == 1) {
      scanf("%lf %lf", &aux1, &aux2);
      distanciaMRU(aux1, aux2);
    } else if (O == 2) {
      scanf("%lf %lf", &aux1, &aux2);
      velocMRU(aux1, aux2);
    } else if (O == 3) {
      scanf("%lf %lf", &aux1, &aux2);
      tempoMRU(aux1, aux2);
    } else if (O == 4) {
      scanf("%lf %lf %lf", &aux1, &aux2, &aux3);
      distanciaMRUV(aux1, aux2, aux3);
    } else if (O == 5) {
      scanf("%lf %lf %lf", &aux1, &aux2, &aux3);
      velocFinalMRUV(aux1, aux2, aux3);
    } else if (O == 6) {
      scanf("%lf %lf %lf", &aux1, &aux2, &aux3);
      velocInicMRUV(aux1, aux2, aux3);
    } else if (O == 7) {
      scanf("%lf %lf %lf", &aux1, &aux2, &aux3);
      tempoTotalMRUV(aux1, aux2, aux3);
    }
  }
  return 0;
}

void distanciaMRU(double veloc, double tempo) {
  double dist = 0;
  dist = veloc * tempo;
  printf("%.2lf\n", dist);
}

void velocMRU(double dist, double tempo) {
  double veloc = 0;
  veloc = dist / tempo;
  printf("%.2lf\n", veloc);
}

void tempoMRU(double dist, double veloc) {
  double tempo = 0;
  tempo = dist / veloc;
  printf("%.2lf\n", tempo);
}

void distanciaMRUV(double veloc, double acel, double tempo) {
  double dist = 0;
  dist = veloc * tempo + (acel * tempo * tempo) / 2;
  printf("%.2lf\n", dist);
}

void velocFinalMRUV(double velocini, double acel, double tempo) {
  double velocfinal = 0;
  velocfinal = velocini + acel * tempo;
  printf("%.2lf\n", velocfinal);
}

void velocInicMRUV(double dist, double acel, double tempo) {
  double velocini = 0;
  velocini = (dist - (acel * tempo * tempo) / 2) / tempo;
  printf("%.2lf\n", velocini);
}

void tempoTotalMRUV(double dist, double veloc, double acel) {
  double tempo, velocfin;
  velocfin = sqrt(veloc * veloc + 2 * acel * dist);
  tempo = (velocfin - veloc) / acel;
  printf("%.2lf\n", tempo);
}
