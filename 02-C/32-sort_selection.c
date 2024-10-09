#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int const TOTAL_ITEMS = 8;
    int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int smallest = 0;

    printf("*** Ordenamiento por selección ***\n");

    // Recorrer toda la lista.
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        // Recorrer desde el siguiente número.
        for (int j = i + 1; j < TOTAL_ITEMS; j++)
        {
            // Buscar el elemento más pequeño e intercambiar posiciones.
            if (numbers[i] > numbers[j])
            {
                smallest = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = smallest;
            }
        }
    }

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}
