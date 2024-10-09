#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int const TOTAL_ITEMS = 6;
    string strings[] = {"banana", "pera", "uva", "manzana", "durazno", "frutilla"};
    string to_search = get_string("Palabra a buscar 🔍: ");

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        if (strcmp(strings[i],to_search) == 0)
        {
            printf("Encontrada en la posición %i\n", i);
            return 0;
        }
    }
    printf("Palabra no encontrada 😢\n");
    return 1;
}
