#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras.
typedef struct node
{
    char *name;
    struct node *next;
} node;

// Constantes.
#define HASH_TABLE_SIZE 10

// Prototipo de funciones.
unsigned int hash(char *name);
node *create_node(char *name);
void insert(node *hash_table[], char *name);
void show_hash_table(node *hash_table[]);
node *find(node *hash_table[], char *name);
void free_node(node *current_node);
void free_hash_table(node *hash_table[]);

int main(void)
{
    node *hash_table[HASH_TABLE_SIZE] = {NULL};

    insert(hash_table, "Agustín");
    insert(hash_table, "Adrián");
    insert(hash_table, "Adriano");
    insert(hash_table, "Lorena");
    insert(hash_table, "Carlitos");

    show_hash_table(hash_table);

    node *searched = find(hash_table, "Agustín");
    if (searched != NULL)
    {
        printf("\nSe encontró %s.\n", searched->name);
    }
    else
    {
        printf("\nNo se encontró ese nombre.\n");
    }

    free_hash_table(hash_table);
}

/**
 * Calcula el hash de una cadena de caracteres.
 *
 * Esta función calcula un hash para una cadena de caracteres dada, sumando los
 * valores ASCII de los caracteres en la cadena y tomando el módulo del tamaño
 * de la tabla hash para obtener el índice en la tabla hash donde se almacenará
 * la cadena.
 *
 * @param name La cadena de caracteres para la que se calculará el hash.
 * @return El índice calculado en la tabla hash.
 */
unsigned int hash(char *name)
{
    int sum = 0;

    // Recorre la cadena de caracteres sumando los valores ASCII de los caracteres.
    for (int i = 0; name[i] != '\0'; i++)
    {
        sum += name[i];
    }

    // Toma el módulo del valor de suma con respecto al tamaño de la tabla hash.
    return sum % HASH_TABLE_SIZE;
}

/**
 * Crea un nodo para almacenar nombres.
 *
 * @param name: es un string que contiene el nombre.
 *
 * @return: Devuelve el nodo creado.
 */
node *create_node(char *name)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("ERROR: No hay memoria suficiente para asignar espacio.");
        exit(1);
    }

    // Asignar memoria para almacenar una copia de la cadena de nombre
    new_node->name = malloc(strlen(name) + 1); // +1 para el carácter nulo final
    if (new_node->name == NULL)
    {
        printf("ERROR: No hay memoria suficiente para asignar espacio.");
        exit(1);
    }

    // Copiar la cadena de nombre a la nueva ubicación de memoria
    strcpy(new_node->name, name);
    new_node->next = NULL;

    return new_node;
}

/**
 * Inserta un nuevo nodo en la tabla hash.
 *
 * @param table: Es el array que contiene los nombres o lista de nombres.
 * @param name: Es el nombre a agregar.
 */
void insert(node *hash_table[], char *name)
{
    int index = hash(name);
    if (hash_table[index] == NULL)
    {
        hash_table[index] = create_node(name);
    }
    else
    {
        node *aux = create_node(name);
        aux->next = hash_table[index];
        hash_table[index] = aux;
    }
}

/**
 * Muestra los datos almacenados en una tabla hash.
 *
 * @param hash_table: Es la tabla hash.
 */
void show_hash_table(node *hash_table[])
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        // Si tiene un nodo en la posición del array...
        if (hash_table[i] != NULL)
        {
            // Comprobar si hay más valores en esa posición.
            if (hash_table[i]->next != NULL)
            {
                // Recorrer la lista enlazada.
                for (const node *ptr = hash_table[i]; ptr != NULL; ptr = ptr->next)
                {
                    printf("%2i - %s\n", i + 1, ptr->name);
                }
            }
            else
            {
                printf("%2i - %s\n", i + 1, hash_table[i]->name);
            }
        }
        else
        {
            printf("%2i - _ _ _\n", i + 1);
        }
    }
}

/**
 * Busca un nombre en la tabla hash.
 *
 * @param hash_table: Es la tabla hash donde se buscará.
 * @param name: Nombre a buscar dentro de la tabla.
 *
 * @return Devuelve un node con los datos encontrados o NULL.
 */
node *find(node *hash_table[], char *name)
{
    int index = hash(name);

    // Si el nombre está directamente en la tabla hash...
    if (strcmp(hash_table[index]->name, name) == 0)
    {
        return hash_table[index];
    }

    // Si no está en la posición de la tabla hash pero hay una lista vinculada...
    if (hash_table[index]->name != name && hash_table[index]->next != NULL)
    {
        // Recorrer la lista vinculada.
        for(node *ptr = hash_table[index]; ptr != NULL; ptr = ptr->next)
        {
            if (strcmp(ptr->name, name) == 0)
            {
                return ptr;
            }
        }
    }

    // Si no se encontró el nombre...
    return NULL;
}

/**
 * Libera memoria destruyendo una lista vinculada de forma recursiva.
 *
 * @param current_node: nodo inicial a liberar memoria.
 */
void free_node(node *current_node)
{
    // Caso base.
    if (current_node == NULL)
    {
        return;
    }

    free_node(current_node->next);
    free(current_node);
}

/**
 * Recorre toda la tabla hash liberando memoria.
 *
 * @param hash_table: La tabla hash que se liberará.
 */
void free_hash_table(node *hash_table[])
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        free_node(hash_table[i]);
        hash_table[i] = NULL;
    }
}
