#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("*** Argumentos de la línea de comandos ⌨️  ***\n");
    // Imprimir todos los argumentos de la línea de comandos.
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}
