#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototipo de funciones.
string to_uppercase(string text);

int main(void)
{
    printf("*** Convirtiendo texto a MAYUSCULAS ***\n\n");

    string some_text = get_string("Antes:   ");
    // Usando mi función.
    printf("Después: %s\n", to_uppercase(some_text));

    // Usando toupper() de la librería ctype.h
    printf("Después: ");
    for (int i = 0, lenght = strlen(some_text); i < lenght; i++)
    {
        printf("%c", toupper(some_text[i]));
    }
    // Salto de línea.
    printf("\n");
}

/**
 * Devuelve una cadena en mayúsculas.
 *
 * @param text: el texto original.
 * @return: La cadena en mayúsuculas.
 */
string to_uppercase(string text)
{
    // Constantes
    const int DIFFERENCE_LOWER_UPPER_ASCII = 32;

    // Recorrer todos los caracteres de la cadena.
    for (int i = 0, lenght = strlen(text); i < lenght; i++)
    {
        // Si el caracter está en minúsculas.
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            // Cambiarlo a mayúsculas restandole 32 al valor
            // ASCII del caracter en minúsculas.
            text[i] -= DIFFERENCE_LOWER_UPPER_ASCII;
        }
    }

    return text;
}
