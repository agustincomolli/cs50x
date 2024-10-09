/*
    Declara un entero y un puntero a un entero.
    Asigna la dirección del entero al puntero y luego imprime el valor del
    entero usando el puntero.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number = 10;
    int *ptr;

    ptr = &number;
    printf("¡El puntero dice que el número es: %i!\n", *ptr);
}
