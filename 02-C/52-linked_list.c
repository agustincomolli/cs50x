#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        // Convertir el caracter a número.
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Liberar memoria y salir.
            free(n);
            return 1;
        }

        n->number = number;
        // El siguiente elemento es el primer valor de la lista.
        n->next = list;
        // Ahora el primer valor de la lista es el último agregado.
        list = n;
    }

    // Imprimir toda la lista.
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    return 0;
}
