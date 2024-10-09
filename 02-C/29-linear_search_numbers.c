#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int const TOTAL_NUMBERS = 7;
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int to_search = get_int("Número a buscar 🔍: ");

    for (int i = 0; i < TOTAL_NUMBERS; i++)
    {
        if (numbers[i] == to_search)
        {
            printf("Encontrado en la posición %i\n", i);
            return 0;
        }
    }
    printf("Número no encontrado 😢\n");
    return 1;
}
