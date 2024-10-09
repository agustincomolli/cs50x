#include <cs50.h>
#include <stdio.h>

// Mastercard usa números de 16 dígitos y comienzan en 51, 52, 53, 54 o 55
#define MASTERCARD_MAX_DIGITS 5599999999999999
#define MASTERCARD_MIN_DIGITS 5100000000000000
// American Express usa números de 15 dígitos y comienzan en 34 o 37
#define AMEX_MAX_DIGITS 379999999999999
#define AMEX_MIN_DIGITS 340000000000000
// VISA: Visa usa números de 13 y 16 dígitos y comienzan en 4
#define VISA_MAX_13_DIGITS 4999999999999
#define VISA_MIN_13_DIGITS 4000000000000
#define VISA_MAX_16_DIGITS 4999999999999999
#define VISA_MIN_16_DIGITS 4000000000000000

// Prototipos de funciones.
bool checksum_ok(long number);
string validate_credit_card(long number);

int main(void)
{
    printf("*** 💳 Validador de tarjetas de crédito 💳 ***\n\n");
    long credit_card_number = get_long("Número: ");
    string answer = validate_credit_card(credit_card_number);
    printf("%s", answer);
}

/**
 * Verifica si el número ingresado corresponde a una tarjeta de crédito.
 *
 * Parámetros:
 *      number: El número de la tarjeta de crédito.
 *
 * Retorna:
 *      El tipo de tarjeta de crédito o si es inválida.
 */
string validate_credit_card(long number)
{
    // Comprobar la suma de verificación del número.
    if (!checksum_ok(number))
    {
        return "INVALID\n";
    }

    // Comprueba que el número esté en el rango correcto.
    if (number >= MASTERCARD_MIN_DIGITS && number <= MASTERCARD_MAX_DIGITS)
    {
        return "MASTERCARD\n";
    }
    else if (number >= AMEX_MIN_DIGITS && number <= AMEX_MAX_DIGITS)
    {
        // Verifica que el número comience de forma correcta a la tarjeta.
        bool is_start_with_34 = (number / 10000000000000 == 34);
        bool is_start_with_37 = (number / 10000000000000 == 37);
        if (is_start_with_34 || is_start_with_37)
        {
            return "AMEX\n";
        }
    }
    else if ((number >= VISA_MIN_13_DIGITS && number <= VISA_MAX_13_DIGITS) ||
             (number >= VISA_MIN_16_DIGITS && number <= VISA_MAX_16_DIGITS))
    {
        if (number / 1000000000000000 == 4 || number / 1000000000000 == 4)
        {
            return "VISA\n";
        }
    }

    return "INVALID\n";
}

/**
 * Verifica si el número de tarjeta de crédito es válido según el algoritmo de Luhn.
 *
 * Parámetros:
 *      number: El número de tarjeta de crédito.
 *
 * Retorna:
 *      Verdadero si el número de tarjeta de crédito es válido, falso de lo contrario.
 */
bool checksum_ok(long number)
{
    int module;
    int second_digit;
    int sum_first_digits = 0;
    int sum_second_digits = 0;
    while (number != 0)
    {
        // Obtener los dos últimos dígitos de la tarjeta de crédito.
        module = number % 100;
        // Obtener el primer dígito y sumarlo.
        sum_first_digits += module % 10;
        // De esos dos últimos dígitos, obtener el de la izquierda.
        second_digit = module / 10;
        second_digit *= 2;
        // Sumar los dígitos de los productos.
        if (second_digit >= 10)
        {
            // Si el producto tiene dos dígitos separarlos y sumarlos.
            sum_second_digits += second_digit / 10;
            sum_second_digits += second_digit % 10;
        }
        else
        {
            sum_second_digits += second_digit;
        }
        // Quitar los dos últimos números de la tarjeta de crédito.
        number /= 100;
    }

    // Si último número de las sumas es 0, el número es válido.
    if ((sum_second_digits + sum_first_digits) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
