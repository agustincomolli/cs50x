#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Constantes.
#define MAX_CAPACITY 20

// Estructuras de datos.
typedef struct stack
{
    int array[MAX_CAPACITY];
    int top;
} stack;

// Prototipo de funciones.
void push(stack *ptr_stack, int data);
int pop(stack *ptr_stack);
void show_stack(stack *ptr_stack);

int main(void)
{
    const int TOTAL_STACK = 7;
    stack numbers;
    numbers.top = 0;

    // Agregar items a la pila.
    for (int i = 0; i < TOTAL_STACK; i++)
    {
        push(&numbers, i + 1);
    }

    show_stack(&numbers);

    int deleted = pop(&numbers);
    printf("El número eliminado es %i.\n", deleted);

    show_stack(&numbers);
}

/**
 * Agrega un número al final de la pila.
 *
 * @param ptr_stack: Es el puntero a la pila.
 * @param data: Es el valor a agregar.
 *
 */
void push(stack *ptr_stack, int data)
{
    ptr_stack->array[ptr_stack->top] = data;
    if (ptr_stack->top + 1 < MAX_CAPACITY)
    {
        ptr_stack->top++;
    }
    else
    {
        printf("ERROR: stack overflow 😆\n");
        exit(1);
    }
}

/**
 * Elimina el último valor agregado a la pila.
 *
 * @param ptr_stack: Es el puntero a la pila.
 *
 * @return: Devuelve el valor eliminado.
 */
int pop(stack *ptr_stack)
{
    int last_value = 0;

    if (ptr_stack >= 0)
    {
        ptr_stack->top--;
        last_value = ptr_stack->array[ptr_stack->top];
    }
    return last_value;
}

/**
 * Muestra el contenido de la pila.
 *
 * @param ptr_stack: es el puntero a la pila.
 *
 */
void show_stack(stack *ptr_stack)
{
    for (int i = 0; i < ptr_stack->top; i++)
    {
        printf("%i ", ptr_stack->array[i]);
    }
    printf("\n");
}
