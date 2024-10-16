#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    // Caso base. Si la cadena está vacía.
    if (input[0] == '\0')
    {
        return 0;
    }
    int index = strlen(input) - 1;
    int number = (int) input[index] - '0';
    input[index] = '\0';
    return number + 10 * convert(input);
}
