/*
    Crea un array de punteros a enteros.
    Asigna memoria para 5 enteros usando malloc y
    asigna valores a esos enteros.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int TOTAL_ITEMS = 5;
    // Crear un array de punteros
    int **numbers = malloc(TOTAL_ITEMS * sizeof(int*));
    if (*numbers == NULL)
    {
        return 1;
    }

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        // Asignar memoria en cada item del array.
        numbers[i] = malloc(sizeof(int));
        *numbers[i] = i + 1;
    }

    for (int i = 0; i < TOTAL_ITEMS - 1; i++)
    {
        printf("%i, ", *numbers[i]);
    }
    printf("%i\n", *numbers[TOTAL_ITEMS - 1]);

    // Liberar memoria
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        free(numbers[i]);
    }
    free(numbers);

    return 0;
}
