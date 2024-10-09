#include <stdio.h>
// Agregar la librería de CS50 para ayudar al uso de variables y tipos de datos.
#include <cs50.h>

int main(void)
{
    string name = get_string("¿Cuál es tu nombre? ");
    // El caracter %s es un código de formato para indicar a C que en ese lugar estará
    // el valor de la variable
    printf("¡Hola %s! Bienvenido a C 😎\n", name);
}
