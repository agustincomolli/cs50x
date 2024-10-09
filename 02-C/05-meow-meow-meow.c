#include <cs50.h>
#include <stdio.h>

// Declarar la función que más abajo se desarrollará
void meow(void);
void repeat_meow(int amount);

int main(void)
{
    printf("*** Mauyando 🐈 ***\n\n");
    // Ciclo de repetición While
    // Contando para atrás:
    int counter = 3;
    while (counter > 0)
    {
        printf("😸: ¡Meow! ");
        counter--;
    }

    // Salto de línea
    printf("\n");

    // Contando hacia adelante:
    int i = 0;
    while (i < 3)
    {
        printf("😸: ¡Meow! ");
        i++;
    }

    // Salto de línea
    printf("\n\n");

    // Ciclo de repetición For
    // La variable i del ciclo for debe ir precedida de la declaración del tipo
    // int pero como i fue definida anteriormente en este caso no se pone.
    for (i = 0; i < 3; i++)
    {
        printf("😸: ¡Meow! ");
    }

    printf("\n\n");

    // Usando funciones
    printf("*** Mauyando con funciones ***\n");
    for (i = 0; i < 3; i++)
    {
        meow();
    }

    printf("\n");

    // Usando funciones con parámetros
    repeat_meow(2);
    printf("\n");
}

void meow(void)
{
    printf("😸: ¡Meow! ");
}

void repeat_meow(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        printf("😻: ¡Meow! ");
    }
}
