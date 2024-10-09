#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define un entero positivo de 8 bits de tamaño. Un byte.
typedef uint8_t BYTE;

// Prototipo de funciones.
int recover(char *filename);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso %s <nombre archivo>\n", argv[0]);
        return 1;
    }

    return recover(argv[1]);
}

/**
 * Recupera los archivos JPG de una imagen de tarjeta de memoria.
 *
 * @param filename: El nombre del archivo de imagen.
 *
 * @returns: Devuelve 0 si no hay errores o 1 si hay algún error.
 */
int recover(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("No se ha podido abrir el archivo especificado.\n");
        return 1;
    }

    int const SIZE_CHUNK = 1;       // Leerá 1 fragmento por vez
    int const ELEMENTS = 512;       // El tamaño del fragmento es de 512 bytes.
    int const FILE_NAME_LENGTH = 8; // La cantidad de caracteres que tendrán los archivos JPG.
    BYTE buffer[ELEMENTS];
    bool is_writing_file = false; // Indica si se está escribiendo en un archivo.
    int filenumber = 0;
    FILE *new_jpg_file;

    // Leer el archivo mientras haya que leer.
    while (fread(buffer, SIZE_CHUNK, ELEMENTS, file) == ELEMENTS)
    {
        // Si el encabezado de 4 bytes coincide con la firma de un JPG...
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            // Si se está escribiendo un archivo, cerrarlo.
            if (is_writing_file)
            {
                fclose(new_jpg_file);
            }
            // Generar un archivo JPG nuevo.
            is_writing_file = true;
            char jpg_file_name[FILE_NAME_LENGTH];
            sprintf(jpg_file_name, "%03i.jpg", filenumber);
            new_jpg_file = fopen(jpg_file_name, "w");
            filenumber++;
        }

        // Si se está escribiendo un archivo, grabar los datos leídos.
        if (is_writing_file)
        {
            fwrite(buffer, SIZE_CHUNK, ELEMENTS, new_jpg_file);
        }
    }

    // Cerrar todos los archivos.
    fclose(new_jpg_file);
    fclose(file);

    return 0;
}
