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
            return 1;
        }

        n->number = number;
        n->next = NULL;

        // Si la lista está vacía...
        if (list == NULL)
        {
            list = n;
        }
        else
        {
            // Recorrer toda la lista.
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // Si está en el final de la lista...
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
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
