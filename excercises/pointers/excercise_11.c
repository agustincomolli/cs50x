/*
    Copia de un string dinámico:
    Escribe una función en C llamada copyString que tome como
    argumento un string (char *) y devuelva una copia dinámica
    de ese string. Utiliza malloc() para asignar memoria para
    la nueva copia y asegúrate de liberar la memoria
    correctamente después de su uso.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de funciones.
char *copyString(const char *text);

int main(void)
{
    char *phrase = "Mangia che ti fa bene";
    char *new_phrase = copyString(phrase);
    free(new_phrase);
    return 0;
}

char *copyString(const char *text)
{
    int length = strlen(text);
    const int NULL_CHAR = 1;
    char *new_text = malloc((length + NULL_CHAR) * sizeof(char));
    if (new_text == NULL)
    {
        printf("No se puede asignar más memoria.\n");
        exit(1);
    }
    strcpy(new_text, text);
    return new_text;
}
