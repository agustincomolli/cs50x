#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = 10;

    // IF, ELSE IF, ELSE

    if (x == 10)
    {
        printf("x es igual a 10\n");
    }

    if (x < 30)
    {
        printf("x es menor a 30\n");
    }
    else
    {
        printf("x no es menor a 30\n");
    }

    if (x < 10)
    {
        printf("x es menor a 10\n");
    }
    else if (x > 10)
    {
        printf("x es mayor a 10");
    }
    else
    {
        printf("x es igual a 10\n");
    }

    // SWITCH
    x = get_int("Ingresa un número: ");
    switch (x)
    {
        case 1:
            printf("¡Uno!\n");
            break;
        case 2:
            printf("¡Dos!\n");
            break;
        case 3:
            printf("¡Tres!\n");
            break;
        default:
            printf("Oops!\n");
    }

    // Operador ternario
    string message = (x > 10) ? "¡Es mayor!" : "¡Es menor!";
    printf("El mensaje es: %s\n", message);
}
