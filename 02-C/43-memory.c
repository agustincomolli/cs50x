#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Reservar una posición de memoria con malloc,
    // sizeof devuelve el tamaño en bytes que ocupa su
    // argumento.
    int *x = malloc(3 * sizeof(int));

    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    // Liberar la memoria reservada
    free(x);
    return 0;
}
