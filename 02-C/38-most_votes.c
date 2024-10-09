#include <cs50.h>
#include <stdio.h>

// Definición de estructura.
typedef struct
{
    string name;
    int votes;
} candidate;

// Prototipo de funciones.

int main(void)
{
    candidate for_president[4];
    int const TOTAL_CANDIDATES = 4;
    candidate most_voted;

    for_president[0].name = "Milei";
    for_president[0].votes = 8034990;
    for_president[1].name = "Massa";
    for_president[1].votes = 9853492;
    for_president[2].name = "Bulrich";
    for_president[2].votes = 6379023;
    for_president[3].name = "Bergman";
    for_president[3].votes = 722061;

    most_voted = for_president[0];

    for (int i = 1; i < TOTAL_CANDIDATES; i++)
    {
        if (for_president[i].votes > most_voted.votes)
        {
            most_voted = for_president[i];
        }
    }

    printf("El candidato más votado es %s con %i votos.\n", most_voted.name, most_voted.votes);
}
