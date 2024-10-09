/*
    Puntero a estructura dinámica:
    Define una estructura en C llamada Persona que contenga
    campos para el nombre y la edad. Escribe un programa que
    solicite al usuario ingresar el nombre y la edad de una
    persona y luego cree dinámicamente una instancia de Persona
    utilizando malloc(). Finalmente, muestra los datos de la persona creada.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    char *name;
    int age;
} person;

int main(void)
{
    person *my_data = malloc(sizeof(person));
    if (my_data == NULL)
    {
        printf("No se puede reservar más memoria.\n");
        exit(1);
    }

    my_data->name = get_string("Nombre: ");
    my_data->age = get_int("Edad: ");

    printf("Los datos ingresados son: %s y %i\n", my_data->name, my_data->age);

    free(my_data);
    return 0;
}
