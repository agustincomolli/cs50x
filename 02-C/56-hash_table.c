#include <cs50.h>
#include <ctype.h> // Para la función hash.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
} node;

node *table[26];

int hash(string phrase);
bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    // Add items
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // Find phrase bucket
        int bucket = hash(phrase);
        printf("%s hashes to %i\n", phrase, bucket);
    }
}

// TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
    if (phrase == NULL)
    {
        return -1;
    }

    char first_letter = tolower(phrase[0]);
    if (isalpha(first_letter))
    {
        return first_letter - 'a';
    }
    else
    {
        return -1;
    }
}
