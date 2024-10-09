#include <stdio.h>
#include <stdint.h>

// Definimos un alias para el tipo de dato uint8_t
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Verificamos que se pasen exactamente 3 argumentos al programa
    if (argc != 3)
    {
        printf("Uso %s [archivo origen] [archivo destino]\n", argv[0]);
        return 1; // Salimos del programa con código de error
    }

    // Abrimos el archivo de origen en modo lectura binaria
    FILE *source = fopen(argv[1], "rb");
    // Abrimos el archivo de destino en modo escritura binaria
    FILE *destination = fopen(argv[2], "wb");

    BYTE b; // Variable para almacenar los bytes leídos

    // Leemos un byte del archivo de origen y lo escribimos en el archivo de destino
    while (fread(&b, sizeof(b), 1, source) != 0)
    {
        fwrite(&b, sizeof(b), 1, destination);
    }

    // Cerramos los archivos
    fclose(destination);
    fclose(source);

    return 0; // Indicamos que el programa se ejecutó correctamente
}
