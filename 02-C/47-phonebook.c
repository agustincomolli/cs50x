#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Nombre: ");
    char *phone = get_string("Teléfono: ");

    fprintf(file, "%s,%s", name, phone);

    fclose(file);
}
