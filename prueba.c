#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
// Función de comparación 
int comparar(int *a, int *b)
{
    const struct Datos *dato1 = (const struct Datos *)a;
    const struct Datos *dato2 = (const struct Datos *)b;
    return (dato2->numero - dato1->numero);
}
int main()
{
     // Arreglo de datos
    struct Datos datos[8];
    // Leer los datos del archivo
    FILE *archivo;
    char caracter;
    archivo = fopen("alumnos.txt", "r");
    //if para cuando el archivo no se encuentre dentro del programa nos de un aviso
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
        int i = 0;
    while (fscanf(archivo, "%d;%[^;];%[^;];%f;%f;%f\n", &datos[i].numero, datos[i].nombre,
                  datos[i].carrera, &datos[i].nota1, &datos[i].nota2, &datos[i].nota3) == 6)
    {
        i++;
    }
    fclose(archivo);
    return 0;
}

   // Escribir los datos ordenados en otro archivo  /*el código lee los datos de un archivo, los ordena y
    luego escribe los datos ordenados en otro archivo en el formato requerido.*/
    qsort(datos, sizeof(datos) / sizeof(struct Datos), sizeof(struct Datos), comparar);
    // Escribir los datos ordenados en otro archivo
    archivo = fopen("alumnos_ordenados.txt", "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
for (int i = 0; i < 8; i++)
    {
        fprintf(archivo, "%d;%s;%s;%.2f;%.2f;%.2f\n", datos[i].numero, datos[i].nombre,
                datos[i].carrera, datos[i].nota1, datos[i].nota2, datos[i].nota3);
    }

    fclose(archivo);
    printf("\n Se ha ordenado el archivo exitosamente \n");
    return 0;
}
