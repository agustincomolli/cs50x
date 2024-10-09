/*
    Crea un puntero a un entero, asigna memoria para un entero
    usando malloc, y luego asigna un valor a ese entero a través del puntero.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof(int));
    *ptr = 5;

    printf("El puntero tiene el valor de: %i\n", *ptr);

    free(ptr);
}
