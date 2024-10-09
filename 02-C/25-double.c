#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*
        Crear un array de 5 elementos cada uno con el doble del valor del
        elemento anterior. El primer valor es 1.
     */

    printf("*** Lista de dobles ***\n");

    int size = get_int("¿De cuántos elementos quiere la lista? ");
    int doubles_list[size];

    doubles_list[0] = 1;
    printf("%i ", doubles_list[0]);

    for (int i = 1; i < size; i++)
    {
        doubles_list[i] = doubles_list[i - 1] * 2;
        printf("%i ", doubles_list[i]);
    }

    printf("\n");
}
