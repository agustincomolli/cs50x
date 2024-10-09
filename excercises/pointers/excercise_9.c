/*
    Crea un programa que use malloc para asignar memoria
    para un array de enteros, y luego free para liberar esa
    memoria cuando ya no la necesites.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int TOTAL_ITEMS = 5;
    int *numbers = malloc(TOTAL_ITEMS * sizeof(int));
    if (numbers == NULL)
    {
        return 1;
    }

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        numbers[i] = i + 1;
    }

    for (int i = 0; i < TOTAL_ITEMS - 1; i++)
    {
        printf("%i, ", numbers[i]);
    }
    printf("%i\n", numbers[TOTAL_ITEMS - 1]);
    free(numbers);
    return 0;
}
