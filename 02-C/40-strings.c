#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string text = "¡Hola!";
    printf("Contenido de la variable 'text': %s\n", text);
    printf("Contenido del puntero: \t\t %p\n", text);
    int index = 0;
    do
    {
        printf("La dirección del %i° caracter: \t %p\n", index + 1, &text[index]);
        index++;
    }
    while (text[index] != '\0');

    // Una cadena string en realidad es un puntero al inicio de un array de caracteres.
    char *message = "Bienvenido a C";
    printf("%s\n", message);

    // Podemos imprimir un array de caracteres através de los punteros.
    index = 0;
    do
    {
        printf("%c", *(message + index));
        index++;
    }
    while (message[index] != '\0');
    printf("\n");
}
