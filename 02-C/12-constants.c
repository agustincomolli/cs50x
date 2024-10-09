#include <cs50.h>
#include <stdio.h>

// Definir constantes
#define SIZE_DECK 52
#define CARD_SUIT 4

void get_deck();

int main(void)
{
    get_deck();
}

void get_deck()
{
    int cards_per_suit = SIZE_DECK / CARD_SUIT;
    for (int suit = 0; suit < CARD_SUIT; suit++)
    {
        // Imprime el palo de la carta.
        switch (suit)
        {
            case 0:
                printf("♥️ Corazones: \t");
                break;
            case 1:
                printf("♦️ Diamantes: \t");
                break;
            case 2:
                printf("♠️ Picas: \t");
                break;
            case 3:
                printf("♣️ Tréboles: \t");
                break;
        }

        // Imprime cada carta del palo.
        for (int card = 0; card < cards_per_suit; card++)
        {
            switch (card)
            {
                case 0:
                    printf("AS, ");
                    break;
                case 10:
                    printf("J, ");
                    break;
                case 11:
                    printf("Q, ");
                    break;
                case 12:
                    printf("K");
                    break;
                default:
                    printf("%i, ", card + 1);
            }
        }
        // Salto de línea.
        printf("\n");
    }
}
