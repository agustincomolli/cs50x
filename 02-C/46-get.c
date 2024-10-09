#include <stdio.h>

// Prototipo de funciones.
int input_number(char *message);

int main(void)
{
    int number = input_number("Ingrese un número: ");
    printf("\nEl número ingresado es %i\n", number);

    char name[254];
    printf("\nNombre: ");
    // En el caso de una caadena de caracteres char *, lo que se pasa
    // es la dirección de memoria del inicio de dicha cadena por lo que
    // no hace falta enteponer el signo &.
    scanf("%s", name);
    printf("¡Bienvenido %s!\n", name);
}

int input_number(char *message)
{
    int number;
    printf("%s", message);
    // Pasar a la función scanf la dirección donde almacenar la
    // entrada del usuario anteponiendo & al nombre de la variable
    // donde se va a almacenar dicho valor.
    scanf("%i", &number);
    return number;
}
