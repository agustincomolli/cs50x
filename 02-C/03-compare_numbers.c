#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("\n*** COMPARANDO NUMEROS ***\n\n");
    // Para declarar una variable primero definimos el tipo,
    // en este caso int
    int number_1 = get_int("¿Qué valor le damos a number_1? ");
    int number_2 = get_int("¿Qué valor le damos a number_2? ");

    // Estructura de comparación
    if (number_1 < number_2)
    {
        /*
            Para nostrar los valores de las variables se usan cadenas de formateo:
                %c	char
                %f	double
                %f	float
                %i	int
                %li	long
                %s	string
         */
        printf("\n🤔 Humm!...\n %i es menor que %i\n", number_1, number_2);
    }
    else if (number_1 > number_2)
    {
        printf("\n🤔 Humm!...\n ¡%i es mayor que %i!\n", number_1, number_2);
    }
    else
    {
        printf("\n🤔 Humm!...\n ¡%i es igual %i!\n", number_1, number_2);
    }
}
