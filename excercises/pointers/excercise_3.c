/*
    Crea una matriz de enteros y un puntero.
    Haz que el puntero apunte al primer elemento de la matriz y
    luego usa el puntero para recorrer la matriz e imprimir cada elemento.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int TOTAL_ITEMS = 10;
    int numbers[] = {1, 2, 3, 4, 0, 8, 9, 7, 6, 5};
    int *ptr = NULL;
    ptr = &numbers[0];

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        printf("Número %i: %i\n", i + 1, ptr[i]);
    }
    return 0;
}
