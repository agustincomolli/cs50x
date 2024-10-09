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
    if (height <= 0)
    {
        return;
    }

    draw_pyramid(height - 1);

    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}
