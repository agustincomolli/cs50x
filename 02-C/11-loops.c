#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Bucle infinito
    while (true)
    {
        printf("¡Esto es un bucle infinitoooo! 😵‍💫\n");
        break; // Corta el bucle para que no se ejecute más
    }

    // Bucle while
    int counter = 3;
    while (counter > 0)
    {
        printf("%i\n", counter);
        counter--;
    }

    // Bucle do... while
    int number;
    do
    {
        number = get_int("Ingrese un número <> 0: ");
    }
    while (number != 0);

    // Bucle for
    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", i);
    }
}
