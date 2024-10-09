#include <cs50.h>
#include <stdio.h>

// Prototipo de funciones.
bool is_valid_triangle(float side_1, float side_2, float side_3);

int main(void)
{
    printf("*** Comprobando triángulos válidos ***\n");

    float side_1 = get_float("\nIngrese el 1° lado: ");
    float side_2 = get_float("Ingrese el 2° lado: ");
    float side_3 = get_float("Ingrese el 3° lado: ");

    if (is_valid_triangle(side_1, side_2, side_3))
    {
        printf("\nEs un triángulo válido 👍\n");
    }
    else
    {
        printf("\nNo es un triángulo válido 👎\n");
    }
}

/**
 * Comprueba si el tamaño de los lados de un triángulo son correctos como
 * para poder crearlo.
 *
 * @param side_1: 1° lado del triángulo.
 * @param side_2: 2° lado del triángulo.
 * @param side_3: 3° lado del triángulo.
 *
 * @return: Devuelve true si la suma de dos lados es mayor o igual al tercer
 *          lado.
 */
bool is_valid_triangle(float side_1, float side_2, float side_3)
{
    if (side_1 <= 0 || side_2 <= 0 || side_3 <= 0)
    {
        return false;
    }

    if ((side_1 + side_2 < side_3) || (side_1 + side_3 < side_2) || (side_2 + side_3 < side_1))
    {
        return false;
    }

    return true;
}
