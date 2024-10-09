#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("*** Cadena de caracteres ***\n");

    string phrase = get_string("Ingrese una frase: ");
    int lenght = strlen(phrase);
    bool is_orderer = true;

    for (int i = 0; i < lenght - 1; i++)
    {
        if (phrase[i] > phrase[i + 1])
        {
            is_orderer = false;
            i = lenght;
        }
    }

    if (is_orderer)
    {
        printf("Los caracteres están ordenados alfabeticamente. ✔️\n");
    }
    else
    {
        printf("Los caracteres NO están ordenados alfabeticamente. ❌\n");
    }
}
