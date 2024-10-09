#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("*** Arrays de caracteres 🅰️  🅱️  ***\n");

    // Usando 3 variables.
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("Con 3 variables 👉 %c%c%c\n\n", c1, c2, c3);

    // Usando una cadena de caracteres 'string'.
    string greet = "HI!";

    printf("Con 1 string 👉 %s\n\n", greet);

    // Usando dos strings.
    string word_1 = "HI!";
    string word_2 = "BYE!";

    printf("Con 2 strings 👉\n");
    printf("%s\n", word_1);
    printf("%s\n\n", word_2);

    // Usando un array de strings.
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("Con un array 👉\n");
    printf("%s\n", words[0]);
    printf("%s\n\n", words[1]);

    // Mirando bajo el capó.
    printf("Mirando bajo el capó 🚗\n");
    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
}
