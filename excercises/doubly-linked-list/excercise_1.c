#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Estructura de nodo.
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

// Prototipo de funciones.
node *create_node(int data);
node *insert(node *head, int data);
void show_list(node *head);
node *find(node *head, int value);
node *delete(node *head, int value);
void destroy(node *current_node);

int main(void)
{
    node *list = NULL;

    // Crear una lista.
    const int TOTAL_ITEMS = 10;
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        list = insert(list, i + 1);
    }

    // Mostrarla.
    show_list(list);

    // Buscar un valor.
    const int VALUE_TO_FIND = 3;
    node *found = find(list, VALUE_TO_FIND);
    if (found != NULL)
    {
        printf("%i fue encontrado en la dirección %p.\n", VALUE_TO_FIND, &found);
    }
    else
    {
        printf("NO se ha encontrado el valor %i en la lista.\n", VALUE_TO_FIND);
    }

    // Eliminar el 1° elemento de la lista.
    const int FIRST_ITEM = 10;
    list = delete (list, FIRST_ITEM);
    show_list(list);

    // ELiminar el último elemento de la lista.
    const int LAST_ITEM = 1;
    list = delete (list, LAST_ITEM);
    show_list(list);

    // ELiminar un elemento en medio de otros valores.
    const int MIDDLE_ITEM = 5;
    list = delete (list, MIDDLE_ITEM);
    show_list(list);

    // Liberar memoria.
    destroy(list);
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
        printf("ERROR: No hay espacio suficiente para asignar memoria.\n");
        exit(1);
    }

    new_node->data = data;
    new_node->prev = NULL;
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

    new_node->next = head;
    if (head != NULL)
    {
        head->prev = new_node;
    }

    return new_node;
}

/**
 * Imprime en la pantalla la lista vinculada.
 *
 * @param head: Es la dirección de memoria del 1° elemento de la lista.
 */
void show_list(node *head)
{
    for (const node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->data);
    }
    printf("\n");
}

/**
 * Busca un valor dentro de la lista vinculada y devuelve el nodo con ese valor.
 *
 * @param head: Es el puntero al primer elemento de la lista.
 * @param value: Es el valor a buscar.
 *
 * @return: El puntero al valor encontrado o NULL en caso contrario.
 */
node *find(node *head, int value)
{
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data == value)
        {
            return ptr;
        }
    }
    return NULL;
}

/**
 * Elimina un item de la lista.
 *
 * @param head: Es el puntero al 1° elemento de la lista.
 * @param value: Es el valor que se quiere eliminar.
 *
 * @return: Devuelve el puntero al primer elemento de la lista con
 *          los elemento eliminados.
 */
node *delete(node *head, int value)
{
    node *found = find(head, value);

    // Si no existe el item a eliminar...
    if (found == NULL)
    {
        printf("NO se encontró el item a eliminar.\n");
        return head;
    }

    // Si está en el primer lugar de la lista.
    if (found->prev == NULL)
    {
        // Si la lista tiene más de un item...
        if (head->next != NULL)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            head = NULL;
        }
    }
    else if (found->next == NULL)
    {
        // Si está en el último lugar de la lista.
        node *prev = found->prev;
        prev->next = NULL;
    }
    else
    {
        // Si está en medio de dos valores de la lista.
        node *prev = found->prev;
        node *next = found->next;
        prev->next = next;
        next->prev = prev;
    }

    // Borrar el item encontrado.
    free(found);
    return head;
}

/**
 * Función recursiva que destruye toda la lista y libera la memoria el S.O.
 *
 * @param current_node: Es el nodo inicial donde empezará a recorrer recursivamente.
 */
void destroy(node *current_node)
{
    // Caso base.
    if (current_node == NULL)
    {
        return;
    }

    destroy(current_node->next);
    free(current_node);
}
