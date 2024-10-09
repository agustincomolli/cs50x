/*
    Suma de elementos de un array dinámico:
    Escribe un programa en C que solicite al usuario el tamaño
    de un array dinámico de enteros. Luego, utiliza malloc() para
    asignar memoria para el array y solicita al usuario que ingrese
    los elementos. Finalmente, calcula la suma de todos los
    elementos del array y muestra el resultado.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Chequear la cantidad de argumentos correctos.
    if (argc != 2)
    {
        printf("Uso: %s <número de items>\n", argv[0]);
        return 1;
    }

    // Convertir el 2° argumento a entero.
    const int TOTAL_ITEMS = atoi(argv[1]);

    int *numbers = malloc(TOTAL_ITEMS * sizeof(int));
    if (numbers == NULL)
    {
        return 1;
    }

    // Solicitar al usuario los números.
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        numbers[i] = get_int("Número %i: ", i + 1);
    }

    int *sum = malloc(sizeof(int));
    if (sum == NULL)
    {
        return 1;
    }

    // Sumar los números.
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        *sum += numbers[i];
    }

    printf("La suma es %i\n", *sum);

    // Liberar memoria.
    free(numbers);
    free(sum);
    return 0;
}
