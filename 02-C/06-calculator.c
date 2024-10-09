#include <cs50.h>
#include <stdio.h>

// Prototipo de función que será implementada en el código más abajo.
int add(int number_1, int number_2);
float division(float first_number, float second_number);

int main(void)
{
    printf("*** Calculadora ***\n\n");
    int number_1 = get_int("Número 1: ");
    int number_2 = get_int("Número 2: ");
    printf("\n%i + %i = %i\n", number_1, number_2, add(number_1, number_2));
    // Conversión de tipos de datos.
    float result = division((float) number_1, (float) number_2);
    // La cadena de formateo %.2f significa el lugar de decimales que quiero mostrar.
    printf("%i / %i = %.2f\n", number_1, number_2, result);

}

// Funciones con parámetros y valores de retorno. El 1° int indica el valor
// de retorno.
int add(int first_number, int second_number)
{
    return first_number + second_number;
}

float division(float first_number, float second_number)
{
    return first_number / second_number;
}
