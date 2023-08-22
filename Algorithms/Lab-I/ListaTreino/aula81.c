#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    file = fopen("gui.txt", "w");
    fprintf(file,"Teste para ver se funciona.");
    fclose(file);
    return 0;
}