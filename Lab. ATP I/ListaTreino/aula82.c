#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    int x, y, z;
    file = fopen("numero.txt","r");
    if (file == NULL)
    {
        printf("Arquivo não pode ser aberto.\n");
        return 0;
    }
    fscanf(file,"%d %d %d",&x,&y,&z);
    printf("%d %d %d\n",x,y,z);
    fclose(file);    
    return 0;
}
