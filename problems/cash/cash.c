#include <cs50.h>
#include <stdio.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

// Prototipos de funciones
int get_change(void);

int main(void)
{
    printf("*** Calculador de cambio 🪙 ***\n\n");

    int change = get_change();
    int cents = 0;
    // Cantidad de monedas de 25 centavos.
    cents += change / QUARTER;
    change %= QUARTER;

    // Cantidad de monedas de 10 centavos.
    cents += change / DIME;
    change %= DIME;

    // Cantidad de monedas de 5 centavos.
    cents += change / NICKEL;
    change %= NICKEL;

    // Cantidad de monedas de 1 centavo.
    cents += change / PENNY;

    printf("Devolver al cliente %i monedas\n", cents);
}

/**
 * Solicita al usuario la cantidad de centavos que debe devolver al cliente.
 * Tiene que ser mayor o igual a 0.
 * Retorna:
 *      Los centavos que debe devolver.
 */
int get_change(void)
{
    int change;
    do
    {
        change = get_int("Cambio adeudado: ");
    }
    while (change < 0);

    return change;
}
