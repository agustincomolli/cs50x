// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

// Cantidad de comensales.
#define DINERS 2

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
/**
 * Calcula la cantidad de dinero que debe abonar cada comensal.
 *
 * Parámetros:
 *      bill: el valor de la factura sin impuestos.
 *      tax: los impuestos a la factura.
 *      tip: porcentaje correspondiente a la propina
 *
 * Retorna:
 *      El valor que debe abonar cada comensal.
 */
float half(float bill, float tax, int tip)
{
    // Sumar el porcentaje de impuestos a la factura.
    bill += (tax * bill) / 100;
    // Sumar el porcentaje de propina a la factura.
    bill = bill + ((float) tip * bill) / 100;
    // Devolver lo que tiene que pagar cada comensal.
    return bill / DINERS;
}
