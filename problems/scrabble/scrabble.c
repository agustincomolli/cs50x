#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototipos de funciones.
int calculate_score(string word);
void show_winner(int score_player_1, int score_player_2);

int main(void)
{
    string word_player_1 = get_string("Jugador 1: ");
    string word_player_2 = get_string("Jugador 2: ");

    int score_player_1 = calculate_score(word_player_1);
    int score_player_2 = calculate_score(word_player_2);

    show_winner(score_player_1, score_player_2);
}

/**
 * Calcula la cantidad de puntos obtenidos por cada letra de la palabra
 * ingresada según un array 'points' que tiene el valor de cada letra.
 *
 * @param word: la palabra a calcular.
 *
 * @return: Los puntos obtenidos.
 * (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')
 */
int calculate_score(string word)
{
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int lenght = strlen(word);
    char letter;
    int score = 0;

    // Recorrer toda la palabra.
    for (int i = 0; i < lenght; i++)
    {
        letter = word[i];
        // Si el caracter es una letra.
        if (isalpha(letter))
        {
            letter = toupper(letter);
            // Restando el valor de la letra por el valor de la letra 'A'
            // devuelve la posición en donde buscar el puntaje correspondiente.
            score += points[letter - 'A'];
        }
    }
    return score;
}

/**
 * Compara los puntos de los dos jugadores y muestra el ganador.
 *
 * @param score_player_1: Los puntos del jugador 1
 * @param score_player_1: Los puntos del jugador 1
 */
void show_winner(int score_player_1, int score_player_2)
{
    if (score_player_1 == score_player_2)
    {
        printf("Tie!\n");
    }
    else if (score_player_1 > score_player_2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}
