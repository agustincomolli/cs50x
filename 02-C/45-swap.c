#include <stdio.h>

// Portotipo de funciones.
void swap_by_value(int a, int b);
void swap_by_reference(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("El valor de X es %i y el de Y es %i\n", x, y);
    swap_by_value(x, y);
    printf("\nPasando argumentos por valor, no hay intercambio.\n");
    printf("El valor de X es %i y el de Y es %i\n", x, y);
    printf("\nPasando argumentos por referencia\n");
    // Para pasar la dirección en memoria de una variable hay que anteponer
    // el signo & al nombre de la variable.
    swap_by_reference(&x, &y);
    printf("El valor de X es %i y el de Y es %i\n", x, y);
}

void swap_by_value(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap_by_reference(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
