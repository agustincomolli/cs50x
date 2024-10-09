#include <stdio.h>
#include <stdlib.h>

// Prototipo de funciones
int read_file(char *filename);

int main(int argc, char *argv[])
{
    // Verificar que en la línea de comandos se haya pasado el nombre del
    // archivo a leer.
    if (argc != 2)
    {
        printf("Uso %s <nombre de archivo>\n", argv[0]);
        return 1;
    }

    // Ejecutar la función read_file y si hay algún error mostrarlo.
    if (read_file(argv[1]) != 0)
    {
        printf("No se ha podidio leer el archivo %s\n", argv[1]);
        return 2;
    }

    return 0;
}

/**
 * Lee un archivo de texto y lo muestra en la consola.
 *
 * @param filename: es el archivo de texto a leer.
 *
 */
int read_file(char *filename)
{
    FILE *file = fopen(filename, "r");

    // Comprobar que se haya podido arbir el archivo.
    if (file == NULL)
    {
        return 1;
    }

    // Mientras no llegue al final leer un caracter y mostrarlo en
    // consola.
    char ch = fgetc(file);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(file);
    }

    fclose(file);
    return 0;
}
