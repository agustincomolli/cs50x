#include <stdio.h>
#include <stdlib.h>

// Definición de estructuras.
typedef struct queue
{
    int data;
    struct queue *prev;
    struct queue *next;
} queue;

// Constantes.
queue *head = NULL;
queue *tail = NULL;

// Prototipo de funciones.
queue *create_node(int data);
void enqueue(int data);
void dequeue(void);
void show_queue(void);
void destroy(queue *current_node);

int main(void)
{
    const int TOTAL_ITEMS = 10;

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        enqueue(i + 1);
    }

    show_queue();
    dequeue();
    dequeue();
    dequeue();
    printf("\n");
    show_queue();

    // Liberar memoria.
    destroy(head);
}

/**
 * Crea un nodo para almacenar números.
 *
 * @param data: Número entero que se va a guardar.
 *
 * @return un nodo de una lista vinculada.
 */
queue *create_node(int data)
{
    queue *new_node = malloc(sizeof(queue));
    if (new_node == NULL)
    {
        printf("ERROR: No hay memoria suficiente para crear un nodo\n");
        exit(1);
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

/**
 * Agrega un número al final de la cola.
 *
 * @param data: Es el número que se quiere agregar a la cola.
 *
 */
void enqueue(int data)
{
    queue *new_item = create_node(data);
    // Si la cola no tiene items...
    if (head == NULL)
    {
        head = new_item;
        tail = new_item;
    }
    // Si tiene un sólo item...
    else if (head->next == NULL)
    {
        head->next = new_item;
        new_item->prev = head;
        tail = new_item;
    }
    else
    {
        // Agregar al final el nuevo elemento.
        tail->next = new_item;
        new_item->prev = tail;
        tail = new_item;
    }

    return;
}

/**
 * Elimina el primer elemento de la cola.
 *
 */
void dequeue(void)
{
    // Si no hay items en la cola...
    if (head == NULL)
    {
        return;
    }
    // Si solo hay un item en la cola...
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    // Cambiar la cabecera al siguiente item de la cola y
    // eliminar la antigua cabecera.
    queue *old_head = head;
    head = head->next;
    head->prev = NULL;
    free(old_head);

    return;
}

/**
 * Muestra los elementos que están en la cola.
 */
void show_queue(void)
{
    printf("Cola de números:\n");
    for (queue *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->data);
    }
    printf("\n");
}

/**
 * Función recursiva que destruye toda la lista y libera la memoria el S.O.
 *
 * @param current_node: Es el nodo inicial donde empezará a recorrer recursivamente.
 */
void destroy(queue *current_node)
{
    // Caso base.
    if (current_node == NULL)
    {
        return;
    }

    destroy(current_node->next);
    free(current_node);
}
