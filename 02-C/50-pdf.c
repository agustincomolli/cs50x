#include <stdint.h>
#include <stdio.h>

// Define un entero positivo de 8 bits de tamaño. Un byte.
typedef uint8_t byte;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <nombre archivo>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int const SIZE_CHUNK = 1;
    int const AMOUNT_BYTES = 4;
    FILE *file = fopen(filename, "r");
    byte buffer[4];

    // Al leer los 4 primeros bytes de un archivo obtenemos
    // la firma del mismo que nos dirá qué tipo de archivo es.
    int blocks_read = fread(buffer, SIZE_CHUNK, AMOUNT_BYTES, file);

    printf("Los primeros 4 bytes son: ");
    for (int i = 0; i < AMOUNT_BYTES; i++)
    {
        printf("%i ", buffer[i]);
    }
    printf("\n");

    // La firma para los archivos PDF es 37, 80, 68, 70
    if (buffer[0] == 37 && buffer[1] == 80 && buffer[2] == 68 && buffer[3] == 70)
    {
        printf("El archivo \"%s\" es un archivo PDF.\n", filename);
    }
    else
    {
        printf("El archivo \"%s\" NO es un archivo PDF.\n", filename);
    }

    printf("\nBloques leídos: %i\n", blocks_read);

    fclose(file);
}
