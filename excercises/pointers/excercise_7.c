/*
    Crea una función que tome un puntero a un entero
    como argumento y modifique el valor del entero.
 */

#include <stdio.h>
#include <stdlib.h>

// Prototipo de funciones.
void change_number(int *ptr);

int main(void)
{
    int *number = malloc(sizeof(int));
    if (number == NULL)
    {
        return 1;
    }

    *number = 5;
    printf("El valor de number es: %i\n", *number);
    change_number(number);
    printf("El nuevo valor es: %i\n", *number);

    free(number);
    return 0;
}

void change_number(int *ptr)
{
    *ptr = 10;
    return;
}
