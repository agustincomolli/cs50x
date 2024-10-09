// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Contador de palabras.
unsigned int words_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    // Recorrer la lista enlazada a partir del valor hash
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        // Si se encontró el valor devolver true.
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false; // No se pudo cargar el archivo.
    }

    // Read each word in the file
    char word[LENGTH];
    int index = 0;

    while (fscanf(file, "%s", word) != EOF)
    {
        // Add each word to the hash table

        // Obtener el índice del lugar de la tabla hash.
        index = hash(word);

        // Crear un nodo con el valor leído del archivo.
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false; // No hay memoria suficiente.
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // Agregar el nuevo nodo a la tabla hash.
        new_node->next = table[index];
        table[index] = new_node;
        words_count++;
    }

    // Close the dictionary file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Recorrer la tabla hash.
    for (int i = 0; i < N; i++)
    {
        // En cada elemento de la tabla hash recorrer los nodos si hay lista enlazada y
        // liberar la memoria.
        node *current_node = table[i];
        node *temp = NULL;
        while (current_node != NULL)
        {
            temp = current_node->next;
            free(current_node);
            current_node = temp;
        }
        table[i] = NULL;
    }
    return true;
}
