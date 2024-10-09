#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = 50;
    int *pointer = &number;
    // '%p' es un puntero a una dirección de memoria.
    printf("La dirección en memoria es: %p\n", pointer);
    // Para mostrar lo que hay en una dirección de memoria.
    printf("Dentro de esa dirección hay: %i\n", *pointer);
}
