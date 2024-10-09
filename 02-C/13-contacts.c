#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Almacenar información de contacto
    printf("*** 📇 Contacto 📇 ***\n\n");
    string first_name = get_string("Nombre: ");
    string last_name = get_string("Apellido: ");
    int age = get_int("Edad: ");
    string phone = get_string("Teléfono: ");

    // Mostrar la información del contacto
    printf("\n\n*** 🪪 Información del contacto 🪪 ***\n\n");
    printf("-> Apellido y Nombre: %s %s\n", last_name, first_name);
    printf("-> Edad: %i\n", age);
    printf("-> Teléfono: %s\n", phone);
}
