#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// Definir límites para la altura.
#define MIN_HEIGHT 1
#define MAX_HEIGHT 23

// Prototipos de funciones.
int get_height(void);
void print_left_side(int width, int height);
void print_right_side(int width);
void print_floor(int width, int height);
void print_pyramid(int height);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s n, donde n es la altura de la pirámide.\n", argv[0]);
        return 1;
    }

    // Mensaje de bienvenida.
    printf("*** Súper Mario Bros ***\n\n       🕹️  🕹️  🕹️\n\n");

    // Obtener altura de la pirámide desde la línea de comandos y la convierte
    // en un entero con la librería <stdlib.h>.
    int height = atoi(argv[1]);
    // Imprimir la pirámide.
    print_pyramid(height);
}

/**
 * Obtiene la altura deseada del usuario.
 *
 * Esta función solicita al usuario que ingrese la altura deseada
 * para una pirámide, y continúa solicitando la entrada hasta que
 * se ingresa un valor válido dentro del rango permitido.
 *
 * Retorna:
 *     La altura deseada ingresada por el usuario.
 */
int get_height(void)
{

    int height;
    do
    {
        // Solicitar altura al usuario.
        height = get_int("¿Cuál es la altura? ");
    }
    while (height < MIN_HEIGHT || height > MAX_HEIGHT);

    return height;
}

/**
 * Imprime la pirámide de Mario con la altura especificada.
 *
 * Parámetros:
 *     height: La altura de la pirámide a imprimir.
 */
void print_pyramid(int height)
{
    // Iterar sobre cada fila de la pirámide.
    for (int rows = 1; rows <= height; rows++)
    {
        // Imprimir cada fila.
        print_floor(rows, height);
        // Salto de línea.
        printf("\n");
    }
}

/**
 * Imprime una fila de la pirámide con un piso y espacios intermedios.
 *
 * Parámetros:
 *     width: El ancho del piso actual.
 *     height: La altura total de la pirámide.
 */
void print_floor(int width, int height)
{
    // Imprimir el lado izquierdo de la pirámide.
    print_left_side(width, height);

    // Espacios entre lados izquierdo y derecho.
    printf("    ");

    // Imprimir el lado derecho de la pirámide.
    print_right_side(width);
}

/**
 * Imprime el lado izquierdo de una fila de la pirámide.
 *
 * Parámetros:
 *     width: El ancho del piso actual.
 *     height: La altura total de la pirámide.
 */
void print_left_side(int width, int height)
{
    // Imprimir espacios a la izquierda del piso.
    for (int cols = 1; cols <= height - width; cols++)
    {
        printf(" ");
    }

    // Imprimir bloques de la pirámide.
    for (int cols = 1; cols <= width; cols++)
    {
        printf("#");
    }
}

/**
 * Imprime el lado derecho de una fila de la pirámide.
 *
 * Parámetros:
 *     width: El ancho del piso actual.
 */
void print_right_side(int width)
{
    // Imprimir bloques de la pirámide.
    for (int cols = 1; cols <= width; cols++)
    {
        printf("#");
    }
}
