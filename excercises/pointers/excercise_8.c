/*
    Crea un puntero a un puntero a un entero,
    asigna memoria para un entero y un puntero a un entero
    usando malloc, y luego asigna un valor al entero a través
    del puntero al puntero.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **ptr = malloc(sizeof(int*)); // Asigna memoria para ptr
    if (*ptr == NULL)
    {
        return 1;
    }
    int *number = malloc(sizeof(int)); // Asigna memoria para number
    if (number == NULL)
    {
        return 1;
    }
    *ptr = number; // Hace que ptr apunte a number
    **ptr = 10; // Asigna un valor a través de ptr
    printf("El número es: %i\n", **ptr);
    free(number);
    free(ptr);
    return 0;
}
