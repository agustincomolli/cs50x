#include <cs50.h>
#include <stdio.h>

// Prototipo de funciones.
void draw_pyramid(int height);

int main(void)
{
    int height = get_int("Altura: ");
    draw_pyramid(height);
}

void draw_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
