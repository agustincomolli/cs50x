/*
    Crea una estructura que contenga un puntero a un entero.
    Crea una instancia de esa estructura y usa el puntero
    para modificar y acceder a un entero.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct integer
{
    int *ptr;
} integer;

int main(void)
{
    int number = 10;
    integer my_number;

    my_number.ptr = &number;
    *my_number.ptr = 5;

    printf("El nuevo número es: %i\n", *my_number.ptr);
}
