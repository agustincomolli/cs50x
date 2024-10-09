#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definición de nodo.
typedef struct node
{
    int data;
    struct node *next;
} node;

// Prototipo de funciones.
node *create_node(int data);
node *insert(node *head, int data);
bool find(node *head, int data);
void destroy(node *current_node);

int main(void)
{
    // Crear una lista vinculada con 10 items.
    const int TOTAL_ITEMS = 10;
    node *list = NULL;

    printf("Orden original:\n");

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        list = insert(list, i + 1);
        printf("%i ", i + 1);
    }
    printf("\n");

    // Recorrer la lista.
    printf("\nOrden de la lista:\n");
    for (const node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->data);
    }
    printf("\n\n");

    // Buscar un elemento.
    int item_to_find = 6;
    if (find(list, item_to_find) == true)
    {
        printf("El número %i está en la lista.\n", item_to_find);
    }
    else
    {
        printf("El número %i NO está en la lista.\n", item_to_find);
    }

    // Buscar otro elemento.
    item_to_find = 24;
    if (find(list, item_to_find) == true)
    {
        printf("El número %i está en la lista.\n", item_to_find);
    }
    else
    {
        printf("El número %i NO está en la lista.\n", item_to_find);
    }

    // Liberar memoria.
    destroy(list);

    return 0;
}

/**
 * Crea un nodo para almacenar números.
 *
 * @param data: Número entero que se va a guardar.
 *
 * @return un nodo de una lista vinculada.
 */
node *create_node(int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("ERROR: No se puede asignar más memoria.\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

/**
 * Inserta un nodo nuevo al principio de la lista.
 *
 * @param head: es la lista donde se insertará el nuevo elemento.
 * @param data: número que se va a guardar en la lista.
 *
 * @return La lista vinculada con el nuevo elemento al principio.
 */
node *insert(node *head, int data)
{
    node *new_node = create_node(data);

    new_node->data = data;
    new_node->next = head;

    return new_node;
}

/**
 * Busca si existe un número dentro de la lista vinculada.
 *
 * @param head: Lista a buscar.
 * @param data: es el valor que se quiere buscar.
 *
 * @return Devuelve true si existe en la lista; de lo contrario false.
 */
bool find(node *head, int data)
{
    for (const node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data == data)
        {
            return true;
        }
    }

    return false;
}

/**
 * Destruye una lista vinculada y libera memoria.
 * Es una función recursiva.
 *
 * @param current_node: Es el nodo a destruir.
 */
void destroy(node *current_node)
{
    if (current_node == NULL)
    {
        return;
    }
    destroy(current_node->next);
    free(current_node);
}
