#include <cs50.h>
#include <stdio.h>

// Constante: cantidad de puntajes a cargar.
const int N_SCORES = 3;

// Prototipo de funciones.
float average(int lenght, int array[]);

int main(void)
{
    printf("*** Aprendiendo Arrays ***\n\n");

    // Calcular el promedio con tres variables.
    int score_1 = 72;
    int score_2 = 73;
    int score_3 = 33;

    // Al cambiar el tipo del denominador de la división a float (poniendo .0)
    // el resultado de la división será de tipo float.
    printf("El promedio es: %f\n\n", (score_1 + score_2 + score_3) / 3.0);

    // Misma operación usando Arrays.
    int scores[3];

    scores[0] = get_int("Puntuación: ");
    scores[1] = get_int("Puntuación: ");
    scores[2] = get_int("Puntuación: ");

    printf("El promedio es: %f\n\n", (scores[0] + scores[1] + scores[2]) / 3.0);

    // Misma operación usando bucles, arrays y usando constantes para evitar
    // números mágicos.
    for (int i = 0; i < N_SCORES; i++)
    {
        scores[i] = get_int("Puntuación %i: ", i + 1);
    }

    printf("El promedio es: %f\n\n", (scores[0] + scores[1] + scores[2]) / (float) N_SCORES);

    // Misma operación usando bucles, arrays, funciones y constantes.
    for (int i = 0; i < N_SCORES; i++)
    {
        scores[i] = get_int("Puntuación %i: ", i + 1);
    }

    printf("El promedio es: %f\n\n", average(N_SCORES, scores));
}
/**
 * Calcula el promedio de una serie de números.
 * Parámetros:
 *      lenght: Longitud de la matriz
 *      array[]: La matriz que contiene los números a promediar.
 * Retorna:
 *      El promedio de los números de la matriz.
 */
float average(int lenght, int array[])
{
    int sum = 0;

    for (int i = 0; i < lenght; i++)
    {
        sum += array[i];
    }

    return sum / (float) lenght;
}
