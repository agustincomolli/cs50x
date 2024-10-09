#include <cs50.h>
#include <stdio.h>

// Prototipos de funciones
int factorial(int number);

int main(void)
{
    printf("*** Factorial con recursividad ***\n");
    int number = get_int("Número: ");
    printf("El factorial de %i es: %i\n", number, factorial(number));
}

int factorial(int number)
{
    // Caso base.
    if (number == 1)
    {
        return 1;
    }
    // Caso de recursividad.
    return number * factorial(number - 1);
}
