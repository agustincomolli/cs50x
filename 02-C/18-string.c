#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("*** Cadenas de caracteres ***\n");

    string some_text = get_string("Entrada: ");
    printf("Salida:  ");
    // NOTA: Llamar a la función strlen dentro del for hace que dicha
    // función se llame y ejecute en cada iteración.
    for (int i=0; i < strlen(some_text); i++)
    {
        printf("%c", some_text[i]);
    }
    printf("\n");

    // La forma correcta es:
    int lenght = strlen(some_text);
    printf("Salida:  ");
    for (int i=0; i < lenght; i++)
    {
        printf("%c", some_text[i]);
    }
    printf("\n");

    // Una forma más eficiente todavía es:
    printf("Salida:  ");
    for (int i=0, n = strlen(some_text); i < n; i++)
    {
        printf("%c", some_text[i]);
    }
    printf("\n");
}
