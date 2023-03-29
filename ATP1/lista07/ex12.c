#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    typedef struct retangulo
    {
        float x[4],y[4], ret_larg,ret_alt,ret_area;
    }Ret;
    Ret retang;
    for (int i = 0; i < 4; i++)
    {
        printf("Digite o as coordenadas x e y do ponto %d\n",i+1);
        scanf("%f",&retang.x[i]);
        scanf("%f",&retang.y[i]);
    }
    if (sqrt(pow(retang.x[0] - retang.x[1],2) + pow(retang.y[0] - retang.y[1],2)) == sqrt(pow(retang.x[2] - retang.x[3],2) + pow(retang.y[2] - retang.y[3],2)) && sqrt(pow(retang.x[0] - retang.x[2],2) + pow(retang.y[0] - retang.y[2],2)) == sqrt(pow(retang.x[1] - retang.x[3],2) + pow(retang.y[2] - retang.y[3],2)))
    {
        printf("Pode ser formado um retângulo!\n");
        retang.ret_larg = sqrt(pow(retang.x[0] - retang.x[1],2) + pow(retang.y[0] - retang.y[1],2));
        retang.ret_alt = sqrt(pow(retang.x[0] - retang.x[2],2) + pow(retang.y[0] - retang.y[2],2));
        retang.ret_area = retang.ret_alt*retang.ret_larg;
        printf("Ele possui arestas com valores de de %.2f e %.2f.\nEsse retângulo possui uma área de %.2f.\n",retang.ret_alt,retang.ret_larg,retang.ret_area);   
    } else
    {
        printf("Não pode ser formado um retângulo!\n");
    }
    return 0;
}
