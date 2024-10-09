#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *text = get_string("Escribe aquí 👉 ");
    // malloc pide al Sistema Operativo que le asigne un espacio libre en la memoria
    // entre paréntesis hay que especificar cuántos bytes hay que reservar.
    // En el siguiente caso se agrega uno más para que entre el caracter nulo '\0'.
    char *copy_text = malloc(strlen(text) + 1);

    // Si malloc() retorna un valor nulo significa que no hay memoria suficiente
    // para reservar.
    if (copy_text == NULL)
    {
        // Abortar el programa.
        return 1;
    }

    // Copiar una cadena en otra.
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        copy_text[i] = text[i];
    }

    // Lo anterior se simplifica con strcpy(destination, source)
    strcpy(copy_text, text);

    if (strlen(copy_text) > 0)
    {
        copy_text[0] = toupper(copy_text[0]);
    }

    printf("%s\n", text);
    printf("%s\n", copy_text);

    // Liberar el espacio reservado en memoria
    free(copy_text);
    return 0;
}
