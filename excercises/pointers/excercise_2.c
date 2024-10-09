/*
    Crea una función que acepte un puntero a un entero y
    modifique el valor del entero a través del puntero.
 */

#include <stdio.h>
#include <stdlib.h>

// Prototipo de funciones.
void change_int(int *ptr);

int main(void)
{
    int number = 10;
    change_int(&number);
    printf("El nuevo número es: %i\n", number);
    return 0;
}

void change_int(int *ptr)
{
    *ptr = 11;
    return;
}
