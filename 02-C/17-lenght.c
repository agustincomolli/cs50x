#include <cs50.h>
#include <stdio.h>
#include <string.h> // Para manejar strings

// Constantes.
const char NUL = '\0';

// Prototipo de funciones.
int string_lenght(string string_to_check);

int main(void)
{
    printf("*** Averiguando la longitud de una cadena ***\n");
    string name = get_string("¿Cómo te llamas? ");

    // Usando mi propia función.
    int lenght = string_lenght(name);
    printf("Función propia: %s tiene %i caracteres\n", name, lenght);

    // Usando la función incluída en string.h
    lenght = strlen(name);
    printf("Función incorporada: %s tiene %i caracteres\n", name, lenght);
}

/**
 * Devuelve la longitud de una cadena de caracteres.
 *
 * @param string_to_check: cadena a verifcar.
 *
 * @return: La cantidad de caracteres que conforman la cadena.
 */
int string_lenght(string string_to_check)
{
    int lenght = 0;
    while (string_to_check[lenght] != NUL)
    {
        lenght++;
    }

    return lenght;
}
