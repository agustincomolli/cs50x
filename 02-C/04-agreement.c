#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("\n*** Acuerdo de Licencia de Usuario Final ***\n\n");
    printf("Este Acuerdo es un contrato legal entre usted  y yo para el uso de este software.\n\n");
    char answer = get_char("¿Está de acuerdo con los términos del contrato? ");

    // Para comparar caracteres se utiliza las comillas simples '' en lugar de las dobles ""
    /*
        Para unir varias expresiones de comaparación se pueden utilizar los términos:
            && (and): significa y
            || (or):  significa o
     */
    if (answer == 's' || answer == 'S')
    {
        printf("😀 Estás de acuerdo\n");
    }
    else if (answer == 'n' || answer == 'N')
    {
        printf("😢 No estás de acuerdo\n");
    }
    else
    {
        printf("🤔 Humm... No te entendí\n");
    }
}
