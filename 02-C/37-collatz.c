#include <cs50.h>
#include <stdio.h>

// Prototipo de funciones.
int collatz(int number);
bool is_even(int number);

int main(void)
{
    printf("*** Conjetura de Collatz ***\n");
    int number = get_int("Número: ");
    printf("Resultado: %i pasos para llegar a 1\n", collatz(number));
}

/**
 * Aplica la conjetura de Collatz a un número dado.
 *
 * La conjetura de Collatz establece que, partiendo de cualquier número entero positivo:
 * - Si el número es par, se divide por 2.
 * - Si el número es impar, se multiplica por 3 y se suma 1.
 * - Se repiten estos pasos sucesivamente hasta que el número llega a 1.
 *
 * @param number El número al que se aplicará la conjetura de Collatz.
 * @return El número de pasos necesarios para que el número dado llegue a 1
 *         siguiendo la conjetura de Collatz.
 */

int collatz(int number)
{
    int steps = 0;

    if (number == 1)
    {
        return steps;
    }

    steps++;

    if (is_even(number))
    {
        return steps + collatz(number / 2);
    }
    else
    {
        return steps + collatz(3 * number + 1);
    }
}

/**
 * Verifica si un número es par o no.
 *
 * @param number: Es el número a verificar.
 * @return: Devuelve true si el número es par.
 */
bool is_even(int number)
{
    return number % 2 == 0;
}
