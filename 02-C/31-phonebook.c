#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Tipo de datos
typedef struct
{
    string name;
    string phone;
} person;

int main(void)
{
    int const TOTAL_ITEMS = 3;
    // string names[] = {"Agustín", "Lorena", "Adrián", "Carlitos"};
    // string phones[] = {"(2226)-680056", "(11)-58836722", "(2664)-838076", "(2226)-511209"};
    person contacts[TOTAL_ITEMS];

    contacts[0].name = "Agustín";
    contacts[0].phone = "(2226)-680056";

    contacts[1].name = "Lorena";
    contacts[1].phone = "(11)-58836722";

    contacts[2].name = "Adrián";
    contacts[2].phone = "(2664)-838076";

    contacts[3].name = "Carlitos";
    contacts[3].phone = "(2226)-511209";

    string name_to_search = get_string("Nombre 🔍: ");

    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        if (strcmp(contacts[i].name, name_to_search) == 0)
        {
            printf("📞 Teléfono: %s\n", contacts[i].phone);
            return 0;
        }
    }

    printf("Ese contacto no está agendado 😢\n");
    return 1;
}
