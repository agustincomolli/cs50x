#include <cs50.h>
#include <stdio.h>

/*
    *** Tipos de datos ***

    int: Número entero de 32 bits. Puede almacenar 2 mil millones de números
         positivos (2^31) y 2 mil millones en negativos (-2^31).

    unsigned int: Número entero de 32 bits. No soporta números negativos y
                  puede almacenar 4 mil millones de números.

    char: Almacena un caracter de forma individual.

    float: Son números reales con decimales. Es un número de 32 bits. Tiene
           problemas de precisión con la parte decimal.

    double: Al igual que float pero número de 64 bits.

    void: No es un tipo de datos, significa vacío.

    struct: Permite crear un tipo de datos combinado. Por ejemplo: Un caracter
            y un número entero.

    NOTA: La librería CS50.h aporta dos tipos de datos:
    *****

        bool: Almacena un valor Booleano true o false.

        string: Es una cadena de caracteres.
 */

int main(void)
{
    // Para crear una variable se define el tipo de datos y después el nombre.
    int number;
    char letter;

    // Para crear varias variables del mismo tipo:
    int width, height;
    float sqrt2, sqrt3, pi;

    // Usando las variables.
    int age;            // declaración
    age = 46;           // asignación
    int older = 18;     // Inicialización
}
