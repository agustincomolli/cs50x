#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Constantes
#define ROTATE_LETTER 13

// Prototipos de funciones
string encrypt(string message, int key);

int main(void)
{
    string secret_message = get_string("Tu mensaje: ");
    printf("Tu mensaje cifrado es: %s\n", encrypt(secret_message, ROTATE_LETTER));
    return 0;
}

/**
 * Encripta un mensaje utilizando el cifrado cesar.
 *
 * @param message: El mensaje a encriptar.
 * @param key: La clave de encriptación (valor de desplazamiento).
 *
 * @return: El mensaje encriptado.
 */
string encrypt(string message, int key)
{
    char letter;
    const int TOTAL_LETTERS = 26;
    int lenght = strlen(message);

    // Recorrer todas las letras del mensaje.
    for (int i = 0; i < lenght; i++)
    {
        letter = message[i];

        // Encriptar solamente las letras minúsculas.
        if (letter >= 'a' && letter <= 'z')
        {
            message[i] = 'a' + ((letter - 'a' + key) % TOTAL_LETTERS);
        }

        // Encriptar solamente las letras mayúsculas.
        if (letter >= 'A' && letter <= 'Z')
        {
            message[i] = 'A' + ((letter - 'A' + key) % TOTAL_LETTERS);
        }
    }
    
    return message;
}
