#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

/**
 * Determina si un número es primo.
 *
 * Parámetros:
 *      number: El número a comprobar.
 *
 * Retorna:
 *      devuelve true si es primo, de lo contrario false.
 */
bool prime(int number)
{
    // TODO
    // El 1 no se considera primo.
    if (number == 1)
    {
        return false;
    }

    // Recorrer desde el 2 hasta la mitad del número, se toma la mitad de number.
    for (int i = 2; i <= number / 2; i++)
    {
        // Si hay un numero que de de resto 0 entonces no es primo.
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}
