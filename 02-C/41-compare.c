#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *text_1 = get_string("Escriba aquí: ");
    char *text_2 = get_string("Escriba aquí: ");

    if (text_1 == text_2)
    {
        printf("Iguales\n");
    }
    else
    {
        printf("Diferentes\n");
    }

    printf("%p\n", text_1);
    printf("%p\n", text_2);
 }
