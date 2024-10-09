#include <stdio.h>
#include <stdlib.h>

// Estructuras de datos.
typedef struct stack
{
    int data;
    struct stack *next;
} stack;

// Prototipos de funciones.
stack *create_node(int data);
stack *push(stack *head, int data);
stack *pop(stack *head);
void show_stack(stack *head);
void free_stack(stack *head);

int main(void)
{
    const int TOTAL_ITEMS = 10;
    stack *numbers = NULL;

    // Agregar items a la pila.
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        numbers = push(numbers, i + 1);
    }

    show_stack(numbers);

    numbers = pop(numbers);
    numbers = pop(numbers);

    show_stack(numbers);

    free_stack(numbers);
}

/**
 * Crea un nodo para almacenar números.
 *
 * @param data: Número entero que se va a guardar.
 *
 * @return un nodo de una lista vinculada.
 */
stack *create_node(int data)
{
    stack *new_node = malloc(sizeof(stack));
    if (new_node == NULL)
    {
        printf("ERROR: No hay memoria suficiente.\n");
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
stack *push(stack *head, int data)
{
    stack *new_item = create_node(data);
    new_item->next = head;
    return new_item;
}

/**
 * Elimina el último item agregado a la pila.
 *
 * @param head: es el inicio de la pila dónde está el último
 *              elemento agregado.
 *
 * @return: Devuelve un puntero al último elemento de la pila.
 */
stack *pop(stack *head)
{
    stack *aux = head;
    head = aux->next;
    free(aux);

    return head;
}

/**
 * Muesta los elementos que están en la pila.
 *
 * @param head: Es el inicio de la pila.
 *
 */
void show_stack(stack *head)
{
    for (stack *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%2i ", ptr->data);
    }
    printf("\n");
}

/**
 * Destruye una lista vinculada y libera memoria.
 * Es una función recursiva.
 *
 * @param head: Es el nodo a destruir.
 */
void free_stack(stack *head)
{
    if (head == NULL)
    {
        return;
    }

    free_stack(head->next);
    free(head);
}
