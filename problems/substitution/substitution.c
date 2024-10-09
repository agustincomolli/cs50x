#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes.
#define TOTAL_LETTERS 26

// Prototipos de funciones.
bool validate_key(string key);
bool check_key_length(string key);
bool check_non_alpha_chars(string key);
bool check_repeated_chars(string key);
string encrypt(string text, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./sustitution key\n");
        return 1;
    }
    if (!validate_key(argv[1]))
    {
        return 1;
    }
    string const KEY = argv[1];
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext, KEY);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

/**
 * Realiza una serie de validaciones para comprobar que la clave sea correcta.
 *
 * @param key: es la clave, segundo argumento de la línea de comandos.
 * @return: Devuelve true si la clave es correcta.
 */
bool validate_key(string key)
{
    if (!check_key_length(key))
    {
        printf("La clave debe tener exactamente 26 caracteres.\n");
        return false;
    }

    if (!check_non_alpha_chars(key))
    {
        printf("La clave debe contener solo caracteres alfabeticos.\n");
        return false;
    }

    if (!check_repeated_chars(key))
    {
        printf("La clave no debe contener caracteres repetidos.\n");
        return false;
    }

    return true;
}

/**
 * Chequea que la clave tenga exactamante 26 caracteres que forman el total
 * de letras del abcdario inglés.
 *
 * @param key: clave.
 * @return: Devuelve true si el tamaño de la clave es el correcto.
 */
bool check_key_length(string key)
{
    if (strlen(key) != TOTAL_LETTERS)
    {
        return false;
    }
    return true;
}

/**
 * Verifica que la clave contenga solamente caracteres del alfabeto inglés.
 *
 * @param key: La clave.
 * @return: Devuelve true si la clave es correcta.
 */
bool check_non_alpha_chars(string key)
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}

/**
 * Verifica que la clave no contenga caracteres repetidos.
 *
 * @param key: La clave.
 * @return: Devuelve true si la clave es correcta.
 */
bool check_repeated_chars(string key)
{
    int length = strlen(key);

    // Recorrer todos los caracteres de la clave.
    for (int i = 0; i < length; i++)
    {
        // Recorrer todos los caracteres desde i + 1
        for (int j = i + 1; j < length; j++)
        {
            // Comprar el caracter i con el siguiente.
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * Cifra un texto utilizando la clave para reemplazar los caracteres del texto
 * por los de la clave.
 *
 * @param text: El texto a cifrar.
 * @param key: Clave con las 26 letras del alfabeto inglés.
 *
 * @return: El texto cifrado.
 */
string encrypt(string text, string key)
{
    int length = strlen(text);
    int alpha_index = 0;

    for (int i = 0; i < length; i++)
    {
        // Cifrar si es una letra del alfabeto.
        if (isalpha(text[i]))
        {
            // Si la letra está en mayúsculas...
            if (isupper(text[i]))
            {
                // Obtener el índice alfabetico.
                alpha_index = text[i] - 'A';
                // Buscar la posición del índice alfabetico en key, poner la
                // la letra obtenida en mayúsuculas y reasignarla a text.
                text[i] = toupper(key[alpha_index]);
            }
            else
            {
                alpha_index = text[i] - 'a';
                text[i] = tolower(key[alpha_index]);
            }
        }
    }

    return text;
}
