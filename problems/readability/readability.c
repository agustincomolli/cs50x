/*
   Implementar un programa que calcula el nivel de calificación aproximado necesario para comprender un texto. El programa debería
   imprimir como resultado “Grado X”, donde “X” es el nivel de grado calculado, redondeado al número entero más cercano. Si el nivel
   de grado es 16 o superior (equivalente o superior a un nivel de lectura de pregrado superior), su programa debería generar "Grado
   16+" en lugar de dar el número de índice exacto. Si el nivel de grado es inferior a 1, su programa debería generar "Antes del
   grado 1".
 */

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Constantes.
#define ONE_HUNDRED_WORDS 100

// Prototipo de funciones.
int calculate_coleman_liau(int letters, int words, int sentences);
void show_grade(int coleman_liau);

int main(void)
{
    // Obtener la entrada del usuario
    string text = get_string("Texto: ");

    // Calcular total de letras, palabras y oraciones.
    int length = strlen(text);
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; i < length; i++)
    {
        // Contar letras: Excluye números, caracteres de puntuación y espacios.
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Contar palabras: Secuencia de caracteres separados por un espacio.
        // Nota: La última palabra no se cuenta porque no termina en espacio.
        if (isspace(text[i]))
        {
            words++;
        }

        // Contar oraciones: Los '.', '?', '!' indican que empieza una nueva
        // oración.
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    // Contar la última palabra del texto porque no termina con un espacio.
    words++;

    int coleman_liau = calculate_coleman_liau(letters, words, sentences);

    // Mostrar el resultado.
    show_grade(coleman_liau);
}

/**
 * Algoritmo Coleman-Liau:
 * CLI = 0.0588 * L - 0.296 * S - 15.8
 *
 * Donde L es el número promedio de letras por cada 100 palabras y S es
 * el número promedio de oraciones por cada 100 palabras.
 *
 * @param letters: Cantidad de letras del texto.
 * @param words: Cantidad de palabras.
 * @param sentences: Cantidad de oraciones.
 *
 * @return: Devuelve un entero con el índice de legibilidad de un texto.
 */
int calculate_coleman_liau(int letters, int words, int sentences)
{
    // Calcular los promedios por regla de 3 simple.
    float average_letters = (float) (ONE_HUNDRED_WORDS * letters) / (float) words;
    float average_sentences = (float) (ONE_HUNDRED_WORDS * sentences) / (float) words;

    // Calcular la fórmula.
    float coleman_liau = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;

    // Devolver el número entero más cercano al resultado de la fórmula usando
    // la función round() de la librería math.
    return round(coleman_liau);
}

/**
 * Muestra el grado de legibilidad de un texto según el índice Coleman-Liau.
 *
 * @param coleman_lia: Indice de legibilidad.
 */
void show_grade(int coleman_liau)
{
    if (coleman_liau < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (coleman_liau >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", coleman_liau);
    }
}
