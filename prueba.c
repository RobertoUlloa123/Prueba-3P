#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *archivo;
    char caracter;
    archivo = fopen("alumnos.txt", "r");
    while (!feof(archivo))
    {
        caracter = fgetc(archivo);
        putchar(caracter);
    }
    fclose(archivo);
    return 0;
}
