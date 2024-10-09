#include <cs50.h>
#include <stdio.h>

/*
    *** Operadores ***

    =: Operador de asignación.

    Operadores aritméticos:
        +: Suma
        -: Resta
        *: Multiplicación
        /: División
        %: Módulo. Obtiene el resto de una división
        ++: Incremento en 1
        --: Decremento en 1

    Operadores lógicos:
        && (AND): Es true si las dos partes de la expresión booleana son true.
        || (OR): Es false si las dos partes de la expresión booleana son false.
        ! (NOT): Invierte el valor de su operando.

    Operadores relacionales:
        x < y (Menor que)
        x <= y (Menor o igual a)
        x > y (Mayor que)
        x >= y (Mayor o igual a)
        x == y (Es igual a)
        x != y (No es igual a)

 */

int main(void)
{
    int y = 10;
    int x = y + 1;
    int m = 13 % 4;

    x = x * 5;
    x *= 5; // forma optimizada de la línea anterior.

    x++; // incrementar el valor de x en 1
    x--; // reducir el valor de x en 1

}
