#include <cs50.h>
#include <stdio.h>

void draw_wall(int rows, int cols);

int main(void)
{
    // 4 bloques de signos "?"
    for (int i = 0; i < 4; i++) // el 4 en este caso sería un número mágico
    {
        printf(" ? ");
    }
    printf("\n\n");

    // Muro de 3 bloques de alto por 4 de ancho. Los números mágicos se
    // reemplazan con constantes.
    const int rows = 3;
    const int cols = 4;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf(" # ");
        }
        printf("\n");
    }

    // Validar las filas
    int valid_rows = get_int("¿Cuántas filas? ");
    while (valid_rows < 1)
    {
        valid_rows = get_int("¿Cuántas filas? ");
    }

    // Validar las columnas usando el bucle do...while
    int valid_cols;
    do
    {
        valid_cols = get_int("¿Cuántas columnas? ");
    }
    while (valid_cols < 1);

    draw_wall(valid_rows, valid_cols);
}

void draw_wall(int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf(" # ");
        }
        printf("\n");
    }
}
