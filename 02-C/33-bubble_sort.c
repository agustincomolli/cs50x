#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int const TOTAL_ITEMS = 8;
    int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int smallest = 0;
    bool swapped;

    printf("*** 🫧  Ordenamiento por burbúja 🫧  ***\n");

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        swapped = false;

        int inner_loop_limit = TOTAL_ITEMS - i - 1;

        for (int j = 0; j < inner_loop_limit; j++)
        {
            // Realizar el intercambio.
            if (numbers[j] > numbers[j + 1])
            {
                smallest = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = smallest;

                swapped  = true;
            }
        }

        // Si no se realizó ningún intercambio, el array ya está ordenado.
        if (!swapped)
        {
            break;
        }
    }

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}
