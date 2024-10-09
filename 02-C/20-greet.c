#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    /*
        string name = get_string("¿Cuál es tu nombre? ");
        printf("¡Hola %s!\n", name);
    */

    // argc devuelve la cantidad de argumentos pasados a la línea de comandos.
    if (argc == 2)
    {
        // argv[1] es el primer argumento pasado a la línea de comandos después
        // de el nombre del programa. Ej: ./20-greet Agustín
        printf("¡Hola %s!\n", argv[1]);
    }
    else
    {
        printf("Uso:\n\t./20-greet 'tu nombre'\n");
    }
}
