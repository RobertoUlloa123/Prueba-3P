#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
// Función de comparación
int comparar(const void *a, const void *b)
{
    struct Datos *dato1 = (struct Datos *)a;
    struct Datos *dato2 = (struct Datos *)b;
    return (dato2->numero - dato1->numero);
}
// Estructura para almacenar los datos de cada texto
struct Datos
{
    int numero;
    char nombre[50];
    char carrera[50];
    float nota1;
    float nota2;
    float nota3;
    float promedio;
};
// Ordenar de mayor a menor
int main(int argc, char const *argv[])
{
    FILE *archivo;
    char caracter;
    archivo = fopen("alumnos2.0.txt", "w");
    int fputs = ((struct Datos), archivo);
    fclose(archivo);
    while (!feof(archivo))
    {
        caracter = fgetc(archivo);
        putchar(caracter);
    }
    fclose(archivo);
    return 0;
}
