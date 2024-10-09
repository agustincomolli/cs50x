#include <stdio.h>
#include <stdlib.h>

// Constantes.
#define MAX_CAPACITY 20

// Estructuras de datos.
typedef struct queue
{
    int data[MAX_CAPACITY];
    int front;
    int size;
} queue;

// Prototipos de funciones.
void enqueue(queue *list, int number);
void show_queue(queue *list);
int dequeue(queue *list);

int main(void)
{
    const int TOTAL_ITEMS = 10;
    queue numbers;
    numbers.front = 0;
    numbers.size = 0;

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        enqueue(&numbers, i + 1);
    }

    show_queue(&numbers);

    int deleted = dequeue(&numbers);
    if (deleted != -1)
    {
        printf("El número eliminado es %i.\n", deleted);
    }
    else
    {
        printf("La cola está vacía.\n");
    }

    show_queue(&numbers);
}

/**
 * Agrega un número al final de la cola.
 *
 * @param list: Es el puntero a la cola.
 * @param data: Es el número que se quiere agregar a la cola.
 *
 */
void enqueue(queue *ptr_queue, int number)
{
    if (ptr_queue->front + ptr_queue->size > MAX_CAPACITY)
    {
        printf("ERROR: No se pueden agregar más elementos a la cola.\n");
        exit(1);
    }

    int index = ptr_queue->front + ptr_queue->size;
    ptr_queue->data[index] = number;
    ptr_queue->size++;
}

/**
 * Muestra el contenido de la cola.
 *
 * @param list: Es la cola a recorrer.
 *
 */
void show_queue(queue *list)
{
    for (int i = list->front; i < list->size; i++)
    {
        printf("%2i ", list->data[i]);
    }

    printf("\n");
}

/**
 * ELimina el primer elemento de la cola.
 *
 * @param list: Es la cola donde se eliminará el item.
 *
 * @return: Devuelve el valor del elemento eliminado. En caso de que
 *          la cola esté vacía devolverá -1.
 *
 */
int dequeue(queue *list)
{
    // En caso de que la cola esté vacía devolverá -1.
    int deleted = -1;

    if (list->size != 0)
    {
        deleted = list->data[list->front];
        // Cambiar la localización del primer elemento.
        list->front++;
        if (list->front == MAX_CAPACITY)
        {
            list->front = 0;
        }
        // Reducir el valor del tamaño de la cola.
        list->size--;
    }

    return deleted;
}
