// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Prototipo de funciones.
string replace(string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./no-vowels texto\n");
        return 1;
    }

    printf("%s\n", replace(argv[1]));
    return 0;
}

/**
 * Reemplaza las vocales de un texto por números. La u permanece igual.
 *
 * @param text: Es el texto que será reemplazado.
 *
 * @return: El nuevo texto que en lugar de volcales tendrá números.
 */
string replace(string text)
{
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        switch (text[i])
        {
            case 'a':
                text[i] = '6';
                break;
            case 'e':
                text[i] = '3';
                break;
            case 'i':
                text[i] = '1';
                break;
            case 'o':
                text[i] = '0';
                break;
            case 'A':
                text[i] = '6';
                break;
            case 'E':
                text[i] = '3';
                break;
            case 'I':
                text[i] = '1';
                break;
            case 'O':
                text[i] = '0';
                break;
        }
    }

    return text;
}
