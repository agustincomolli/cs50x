#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Argumento de la línea de comando inválido o faltan\n");
        // Devolver un valor distinto de 0 indica algún tipo de error.
        return 1;
    }
    printf("¡Hola %s!\n", argv[1]);
    // 0 es un estado exitoso.
    return 0;
}
