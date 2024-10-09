#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int ITEMS = 3;

    // int list[] = {1, 2, 3};

    // Reservar espacio en la memoria para almacenar números enteros.
    int *list = malloc(ITEMS * sizeof(int));
    if (list == NULL)
    {
        // En caso de no poder, salir del programa.
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *temp = malloc((ITEMS + 1) * sizeof(int));
    if (temp == NULL)
    {
        // Liberar la memoria reservada previamente para no tener
        // pérdidas de memoria (memory leaks).
        free(list);
        return 1;
    }

    // Copiar los datos viejos al array temporal.
    for (int i = 0; i < ITEMS; i++)
    {
        temp[i] = list[i];
    }
    temp[3] = 4;

    // Liberar la memoria reservada para list.
    free(list);
    list = temp;

    for (int i = 0; i < ITEMS + 1; i++)
    {
        printf("Elemento %i = %i\n", i, list[i]);
    }

    // Liberar la memoria reservada.
    free(list);
    return 0;
}
