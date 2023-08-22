#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float v[2],u[2], modV, modU;
    for (int i = 0; i < 2; i++)
        scanf("%f",&v[i]);
    for (int i = 0; i < 2; i++)
        scanf("%f",&u[i]);
    modV = sqrt(v[0]*v[0] + v[1]*v[1]);
    modU = sqrt(u[0]*u[0] + u[1]*u[1]);
    printf("Módulo do vetor V = %.2f.\n",modV);
    printf("Módulo do vetor U = %.2f.\n",modU);
    return 0;
}
