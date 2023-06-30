#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int hora_in, hora_term, min_in, min_ter, seg_ter,seg_in,duracao_horas = 0,duracao_min,duracao_seg,aux;
    float tot_horas, tot_min, tot_seg;
    printf("Digite a momento de início do jogo:(hh mm ss)\n");
    scanf("%d %d %d",&hora_in,&min_in,&seg_in);
    printf("Digite a hora de término do jogo:(hh mm ss)\n");
    scanf("%d %d %d",&hora_term,&min_ter,&seg_ter);
    aux = hora_in;
    if (hora_in != hora_term)
    {
        while (aux != hora_term)
        {
           if (aux == 24)
           {    
            aux = 0; 
           }
           duracao_horas++;
           aux++;
        }
    } else{
        if (!(min_ter == 0 || seg_ter == 0))
        {
            duracao_horas = 24;
        }
    }
    if ((min_ter - min_in) >= 0)
    {
        duracao_min = abs(min_ter - min_in);
    } else if((min_ter - min_in) < 0)
    {
        duracao_min = 60 - (abs(min_ter - min_in));
        duracao_horas--;
    }
    if ((seg_ter - seg_in) >= 0)
    {
        duracao_seg = abs(seg_ter - seg_in);
    } else if((seg_ter - seg_in) < 0)
    {
        duracao_seg = 60 - abs(seg_ter - seg_in);
        duracao_min--;
    }
    if (duracao_min < 0)
    {
        duracao_horas--;
        duracao_min = 59;
    }
    tot_horas = duracao_horas + ((float)duracao_min/60) + ((float)duracao_seg/3600);
    tot_min = (duracao_horas*60) + duracao_min + ((float)duracao_seg/60);
    tot_seg = (duracao_horas*3600) + (duracao_min*60) + duracao_seg;
    printf("Duração: %dh %dmin %dseg\n",duracao_horas,duracao_min,duracao_seg);
    printf("Duração em apenas horas: %.2fh\n",tot_horas);
    printf("Duração em apenas minutos: %.2fmin\n",tot_min);
    printf("Duração em apenas segundos: %.2fseg\n",tot_seg);
    return 0;
}
