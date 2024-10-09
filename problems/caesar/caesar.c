/*
    Cifra una mensaje con el algoritmo de Cesar según la clave pasada en la
    línea de comandos.

    Algoritmo de César:
        caracter_cifrado = (caracter + clave) % 26
 */
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes.
#define TOTAL_LETTERS 26

// Prototipo de funciones.
bool is_number(string text);
string encrypt(string text, int key);

int main(int argc, string argv[])
{
    // Si la cantidad de argumentos de la línea de comandos no es igual a 2,
    // si el 2 argumento no es un número y no es mayor a 0, entonces salir.
    if (!(argc == 2 && is_number(argv[1]) && atoi(argv[1]) > 0))
    {
        printf("Uso: ./caesar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string plain_text;
        plain_text = get_string("plaintext:  ");
        printf("ciphertext: %s\n", encrypt(plain_text, key));
        return 0;
    }
}

/**
 * Comprueba que una cadena de caracteres es un número.
 *
 * @param text: la cadena de texto a verificar.
 * @return: Devuelve true si es un número.
 */
bool is_number(string text)
{
    // Recorrer la cadena de caracteres.
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // Si el caracter no es un número, salir.
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

/**
 * Encripta un texto con el cifrado de César.
 *
 * @param text: Texto a encriptar.
 * @param key: Número entero que contiene cúantos caracteres se van a rotar.
 *
 * @return: El texto encriptado.
 */
string encrypt(string text, int key)
{
    int length = strlen(text);
    char first_letter;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            char letter = text[i];
            if (isupper(text[i]))
            {
                // Convertir la letra al orden alfabético: letter - first_letter
                first_letter = 'A';
                text[i] = first_letter + ((letter - first_letter + key) % TOTAL_LETTERS);
            }
            else
            {
                first_letter = 'a';
                text[i] = first_letter + ((letter - first_letter + key) % TOTAL_LETTERS);
            }
        }
    }
    return text;
}
